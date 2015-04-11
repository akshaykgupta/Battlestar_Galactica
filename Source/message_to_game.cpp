#ifndef MESSAGE_TO_GAME_CPP
#define MESSAGE_TO_GAME_CPP

#include "player.hpp"
#include "spaceObject.hpp"
#include "helper.hpp"

void Player::handleMessage(Message& msg) {
	//I need, the spaceObject's int-index, the spaceObject's linear velocity, angular velocity, health, ammo and so on.
	if (msg.msgType & CONNECTDATA) {
		//might need to add to list of clients
		if(network->getMyIP() != msg.newConnectorIP) { 
			//check if this client corresponding to this IP and port already exists
			if(!findClient(msg.newConnectorIP, msg.newConnectorPort)) {
				//if not found then add to list of clients
				int nextClientId = addClient(msg.newConnectorIP, msg.newConnectorPort);
				//add this spaceObject to list of objects
				spaceObject *newObject = new spaceobject(msg.ship.objType);
				if( add_object(newObject) ) {
					int nextPlayerId = getID(newObject);
					addtoNtoP(nextClientId, nextPlayerId);
				}
				//send this message to everyone else
				myMessage = msg;
				sendMessage();
			}
		}
	} else if (msg.msgType & GENDATA) {

	}
}

void SpaceObject::setState(State& shipdata) {
	btTransform myNewTransform;
	//TODO: Make state the new ship state.
}

#endif