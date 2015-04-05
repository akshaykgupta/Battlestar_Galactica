#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
/*
linker:
-lsfml-graphics -lsfml-window -lsfml-system -lGL
*/
using namespace std;
int main(int argc, char** argv) {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    // load resources, initialize the OpenGL states, ...

    // run the main loop
    bool running = true;
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
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // glColor3f(1.0,1.0,0.0);
        // glBegin(GL_POLYGON);
        // glVertex3f(0.0,-1.0,0.0);
        // glVertex3f(0.0,0.0,0.0);
        // glVertex3f(-1.0,0.0,0.0);
        // glEnd();
        window.pushGLStates();
        sf::Texture t;
        if (!t.loadFromFile("Top.jpg") ) {
            cout << "nooo\n";
            exit(1);
        }
        t.setSmooth(true);
        sf::Texture::bind(&t);
        glBegin(GL_POLYGON);
        glTexCoord2f(0,0); glVertex3f(0.0,0.0,0.0);
        glTexCoord2f(0,1); glVertex3f(1.0,0.0,0.0);
        glTexCoord2f(1,0); glVertex3f(0.0,1.0,0.0);
        glEnd();
        sf::Texture::bind(NULL);
        
        // sf::Text t;
        // string tstr = "hibarun";
        // t.setString(tstr);
        // t.setCharacterSize(100);
        // t.setColor(sf::Color(125,170,255));
        // t.setPosition(0,0);
        
        window.popGLStates();

        // glBegin(GL_POLYGON);
        // glVertex3f(0.0,0.0,0.0);
        // glVertex3f(1.0,0.0,0.0);
        // glVertex3f(0.0,1.0,0.0);
        // glEnd();
        // draw...

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // release resources...

    return 0;
}