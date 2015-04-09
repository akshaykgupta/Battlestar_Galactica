#ifndef PLAYER_EVENT_CPP
#define PLAYER_EVENT_CPP

#include "player.hpp"

void Player::handle_event(sf::Event& event,sf::Window& window) {
	sf::Keyboard::Key key;
	bool collision, laser;
	/*
		Follows the model of : keyboard, mouse.
	*/
	//Rotational
	double tx = sf::Mouse::getPosition(window).x;
    double ty = sf::Mouse::getPosition(window).y;
    //-----------------------------------MAX YAW AND PITCH ALLOWED OF 45 DEGREES. MIN PITCH AND YAW REQUIRED FOR MOVEMENT IS 2 DEGREES--//
    double pitch = ((halfWindowSizeY-ty)*(45.0/halfWindowSizeY) > 2.0)?(halfWindowSizeY-ty)*(45.0/halfWindowSizeY) : 0.0 ;
    double yaw  =  ((halfWindowSizeX-tx)*(45.0/halfWindowSizeX) > 2.0)?(halfWindowSizeX-tx)*(45.0/halfWindowSizeX) : 0.0 ;

    if(pitch!=0.0 || yaw !=0.0){
    	fighter->rotate(pitch,yaw);
    }
    
	//Translational.
	if( ((key = settings->getKey( ACCELERATE )) != sf::Keyboard::Unknown) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->accelerate();
	}
	if( ((key = settings->getKey( DECELERATE )) != sf::Keyboard::Unknown) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->decelerate();
	}
	if( ((key = settings->getKey( STRAFE_LEFT )) != sf::Keyboard::Unknown) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->strafe_left();
	}
	if( ((key = settings->getKey( STRAFE_RIGHT )) != sf::Keyboard::Unknown) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->strafe_right();
	}
	if( ((key = settings->getKey( ASCEND )) != sf::Keyboard::Unknown) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->ascend();
	}
	if( ((key = settings->getKey( DESCEND )) != sf::Keyboard::Unknown) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->descend();
	}
	//rotational.
	if( ((key = settings->getKey( PITCH_UP )) != sf::Keyboard::Unknown) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->pitch_up();
	}
	if( ((key = settings->getKey( PITCH_DOWN )) != sf::Keyboard::Unknown) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->pitch_down();
	}
	if( ((key = settings->getKey( YAW_LEFT )) != sf::Keyboard::Unknown) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->yaw_left();
	}
	if( ((key = settings->getKey( YAW_RIGHT )) != sf::Keyboard::Unknown) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->yaw_right();
	}
	if( ((key = settings->getKey( ROLL_LEFT )) != sf::Keyboard::Unknown) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->roll_left();
	}
	if( ((key = settings->getKey( ROLL_RIGHT )) != sf::Keyboard::Unknown) && sf::Keyboard::isKeyPressed(key) ) {
		fighter->roll_right();
	}

	//End of continuous time keyboard handlers.
	//Begin toggles and shit.
	if ( event.type == sf::Event::KeyPressed ) {
		if ( event.key.code == settings->getKey(TOGGLE_FULLSCREEN) ) {
			//what? How. TODO
		} else if ( event.key.code == settings->getKey(TOGGLE_CAM) ) {
			toggle_camera( window.getSize().x , window.getSize().y );
		} else if ( event.key.code == settings->getKey(FIRE_WEAPON) ) {
			fire_laser();
		} else if ( event.key.code == settings->getKey(TOGGLE_WEAPON) ) {
			fighter->toggle_weapon();
		} else if ( event.key.code == settings->getKey(USE_ABILITY) ) {
			//TODO
		} else if ( event.key.code == settings->getKey(ESCAPE) ) {
			//TODO: Move this from the main to the plauer.
		} else if ( event.key.code == settings->getKey(START_CHAT) ) {
			//TODO
		} else if ( event.key.code == settings->getKey(ESCAPE_CHAT) ) {
			//TODO
		} else if ( event.key.code == settings->getKey(SEND_CHAT) ) {
			//TODO
		}
	}
	
}
#endif