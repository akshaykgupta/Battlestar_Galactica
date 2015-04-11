#ifndef NETWORK_INTEGRATION_CPP
#include "networkManager.h"
#include "helpers.hpp"
#include "player.hpp"

void Player::connectToNetwork(string IP, unsigned short server_port, unsigned int local_port) {
	network = new NetworkManager(IP, server_port, local_port);
	myMessage->setData(CONNECTDATA);
}

void 

#define NETWORK_INTEGRATION_CPP
#endif