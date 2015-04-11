#ifndef MESSAGE_TO_GAME_CPP
#define MESSAGE_TO_GAME_CPP

#include "player.hpp"
#include "spaceObject.hpp"
#include "helper.hpp"

void Player::handleMessage(Message& msg) {
	//I need, the spaceObject's int-index, the spaceObject's linear velocity, angular velocity, health, ammo and so on.
	if ( msg.msgType & CONNECTDATA ) {
		//TODO
	} else if (msg.msgType & GENDATA ) {

	}
}

void SpaceObject::setState(State& shipdata) {
	btTransform myNewTransform;
	//TODO: Make state the new ship state.
}

#endif