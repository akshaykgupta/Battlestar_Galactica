#ifndef SKYBOX_CPP
#define SKYBOX_CPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

class SkyBox {
private:
	sf::Image* box; 
	sf::Texture* texture;
	string imgPath;
	enum FACE {
		TOP = 0,
		BOTTOM = 1,
		LEFT = 2,
		RIGHT = 3,
		FRONT = 4,
		BACK = 5
	};
public:
	SkyBox(const string &);
	~SkyBox();
	void setImage();
	void renderBox(float size);
};
#endif