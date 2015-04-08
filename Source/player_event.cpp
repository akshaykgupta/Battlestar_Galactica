#ifndef PLAYER_EVENT_CPP
#define PLAYER_EVENT_CPP

#include "player.hpp"

void Player::handle_event(sf::Event& event) {
	KeyboardInput key;
	bool collision, laser;
	/*
		Follows the model of : keyboard, mouse.
	*/


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
	

	if ( sf::Mouse)

}
#endif