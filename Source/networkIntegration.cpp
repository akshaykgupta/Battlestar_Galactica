#ifndef NETWORK_INTEGRATION_CPP
#define NETWORK_INTEGRATION_CPP

#include "networkManager.cpp"
#include "helpers.hpp"
#include "player.cpp"

void Player::connectToNetwork(string IP, unsigned short server_port, unsigned int local_port) {
	network = new NetworkManager(IP, server_port, local_port);
	myMessage->setData(CONNECTDATA, myIP, myPort);
	std::ostringstream archive_stream;
}

void Player::sendMessage() {
	std::ostringstream archive_stream;
	boost::archive::text_oarchive archive(archive_stream);
	archive << (*myMessage);
	string message = archive_stream.str();
	network.SendToAll(message);
}

void Player::translateMessage(ClientMessage inMessage) {
	Message message;
	std::istringstream archive_stream(inMessage.first);
	boost::archive::text_iarchive archive(archive_stream);
	archive >> message;
	handleMessage(message, inMessage.second);
}

void receiveMessage() {
	ClientMessage inMessage = network->popMessage();
	if(inMessage.first != "")
		translateMessage(inMessage);
}

#endif