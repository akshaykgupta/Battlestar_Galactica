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
        }
        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        usr->update_state();
        usr->render_state();
        
        //---------------------------------------------//
        //usr->getFighter()->render(true);
        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }
	return 1;
}