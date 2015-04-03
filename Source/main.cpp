using namespace std;

/*LIBS=
-lBulletSoftBody -lBulletDynamics -lBulletCollision -lLinearMath -lboost_system -lboost_thread -lsfml-graphics -lsfml-window -lsfml-system -lGL
*/
//Assume that everything turns up magically from outside :P
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>

#include "spaceObject.hpp"
#include "player.cpp"
#include "player_getsets.cpp"
using namespace std;
int main(int argc, char** argv) {
	sf::Window window(sf::VideoMode(800,600), "spaceRash" , sf::Style::Default, sf::ContextSettings(32));
	window.setVerticalSyncEnabled(true);
	bool running = true;
    Player* usr = new Player();
    usr->setFighterType(UFO);
    usr->init_fighter();
    usr->setup_game_screen( 800 , 600 );

    
    Player* usr2 = new Player();
    SpaceObject* otr;
    otr = new SpaceObject(UFO);
    otr->init(usr->getBulletWorld());
    double dt = 1.0;
    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                usr->setup_game_screen( event.size.width , event.size.height );
                
            }
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W)  ) {
                cout << "front pressed \n";
                usr->getFighter()->setVelocity(btVector3(0,0,-1.0));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                otr->setVelocity(btVector3(0,0,-1.0));
            }
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S) ) {
                cout << "front pressed \n";
                usr->getFighter()->setVelocity(btVector3(0,0,+1.0));
            }
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ){
                otr->setVelocity(btVector3(0,0,+1.0));
            }
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::D) ) {
                cout << "front pressed \n";
                usr->getFighter()->setVelocity(btVector3(1.0,0,0.0));
            }
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                otr->setVelocity(btVector3(1.0,0,0.0));
            }
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ) {
                cout << "front pressed \n";
                usr->getFighter()->setVelocity(btVector3(-1.0,0,0.0));
            }
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                otr->setVelocity(btVector3(-1.0,0,0.0));
            }
            //--------------------TODO----------------------//
            //-------------------CAMERA---------------------//
            //--------------------Accelerate --------------//
            //--------------------Physics files for max veclocity--------//

        }
        // clear the buffers
        cout << usr->getFighter()->getRigidBody()->getLinearVelocity().getZ() << "\n";
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        usr->update_state(dt);
        usr->render_state(dt);
        otr->render(true);
        //---------------------------------------------//
        //usr->getFighter()->render(true);
        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }
	return 1;
}