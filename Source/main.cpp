using namespace std;

/*LIBS=
-lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath -lboost_system -lboost_thread -lsfml-graphics -lsfml-window -lsfml-system -lGL
*/


#include "spaceObject.hpp"
#include "player.hpp"
#include "helpers.hpp"

using namespace std;
int main(int argc, char** argv) {
    Player* usr = new Player();
    usr->setFighterType(UFO);
    usr->init_fighter();

    sf::Window window(sf::VideoMode(usr->getSettings()->defaultScreenSizeX , usr->getSettings()->defaultScreenSizeY), "spaceRash" , sf::Style::Default, sf::ContextSettings(32));
    usr->setup_game_screen( usr->getSettings()->defaultScreenSizeX , usr->getSettings()->defaultScreenSizeY );
    gContactAddedCallback=(Player::collisionCallback);

    window.setVerticalSyncEnabled(true);
	bool running = true;
    usr->playMusic(true);
    Player* usr2 = new Player();
    SpaceObject* otr;
    
    // otr = new SpaceObject(UFO);
    // otr->init(usr->getBulletWorld());
    // otr->getRigidBody()->translate(btVector3(0,0,-10));
    // usr->addToEveryOne(1,otr);
    
    unsigned short myport, connect_to_port;
    string connect_to_ip;

    double dt = 1.0;
    if (argc==2) {
        //listener.
        myport = (unsigned short)atoi(argv[1]);
        usr->startNetwork(myport);
    } else if ( argc == 4 ) {
        //connector.
        myport = (unsigned short)atoi(argv[1]);
        connect_to_ip = argv[2];
        connect_to_port = (unsigned short)atoi(argv[3]);
        usr->getFighter()->getRigidBody()->setPosition(btVector3(0,0,10));
        usr->connectToNetwork(connect_to_ip , connect_to_port , myport);
    } else {
        cout << "invalid connection type. EXIT\n";
        exit(1);
    }
    
    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized) {
                // adjust the viewport when the window is resized
                usr->setup_game_screen( event.size.width , event.size.height );
                
            }
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                running = false;
            }
            usr->handle_event(event,window);
        }
        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        usr->update_state(dt);
        usr->render_state(dt);
        //---------------------------------------------//
        //usr->getFighter()->render(true);
        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }
    delete usr;
	return 1;
}