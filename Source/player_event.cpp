#ifndef PLAYER_EVENT_CPP
#define PLAYER_EVENT_CPP

#include "player.hpp"

void Player::handle_event(sf::Event& event,sf::Window& window) {
	KeyboardInput key;
	bool collision, laser;
	/*
		Follows the model of : keyboard, mouse.
	*/
	//Rotational
	double tx = sf::Mouse::getPosition(window).x;
    double ty = sf::Mouse::getPosition(window).y;
    //-----------------------------------MAX YAW AND PITCH ALLOWED OF 45 DEGREES. MIN PITCH AND YAW REQUIRED FOR MOVEMENT IS 2 DEGREES--//
    pitch = ((halfWindowSizeY-ty)*(45.0/halfWindowSizeY) > 2.0)?(halfWindowSizeY-ty)*(45.0/halfWindowSizeY) : 0.0 ;
    yaw  =  ((halfWindowSizeX-tx)*(45.0/halfWindowSizeX) > 2.0)?(halfWindowSizeX-tx)*(45.0/halfWindowSizeX) : 0.0 ;

    if(pitch!=0.0 || yaw !=0.0){
    	fighter->rotate(pitch,yaw);
    }
    
	//Translational.
	if( ((key = settings->getKey( ACCELERATE )) != NONE) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->accelerate();
	}
	if( ((key = settings->getKey( DECELERATE )) != NONE) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->decelerate();
	}
	if( ((key = settings->getKey( STRAFE_LEFT )) != NONE) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->strafe_left();
	}
	if( ((key = settings->getKey( STRAFE_RIGHT )) != NONE) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->strafe_right();
	}
	if( ((key = settings->getKey( ASCEND )) != NONE) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->ascend();
	}
	if( ((key = settings->getKey( DESCEND )) != NONE) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->descend();
	}
	//rotational.
	if( ((key = settings->getKey( PITCH_UP )) != NONE) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->pitch_up();
	}
	if( ((key = settings->getKey( PITCH_DOWN )) != NONE) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->pitch_down();
	}
	if( ((key = settings->getKey( YAW_LEFT )) != NONE) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->yaw_left();
	}
	if( ((key = settings->getKey( YAW_RIGHT )) != NONE) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->yaw_right();
	}
	if( ((key = settings->getKey( ROLL_LEFT )) != NONE) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->roll_left();
	}
	if( ((key = settings->getKey( ROLL_RIGHT )) != NONE) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->roll_right();
	}
	
}
#endif