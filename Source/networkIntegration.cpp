#ifndef NETWORK_INTEGRATION_CPP
#define NETWORK_INTEGRATION_CPP

#include "networkManager.h"
#include "helpers.hpp"
#include "player.hpp"

void Player::connectToNetwork(string IP, unsigned short server_port, unsigned int local_port) {
	network = new NetworkManager(IP, server_port, local_port);
	myMessage->setData(CONNECTDATA, myIP, myPort);
	std::ostringstream archive_stream;
}

void Player::sendMessage() {
	boost::archive::text_oarchive archive(archive_stream);
	archive << (*myMessage);
	std::string message = archive_stream.str();
	network.SendToAll(message);
}

#endif