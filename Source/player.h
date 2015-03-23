#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>

#include "networkManager.cpp"
/**
This file is the header file for userSettings and also the player.
*/
using namespace std;

class UserSettings {
public:
	/* Sensitivity and stuff. */
	glm::vec3 mouseSensitivity;	   //Along x,y,z.
	glm::vec3 keyboardSensitivity; //Along x,y,z.

	UserSettings() {}
	~UserSettings() {}
	void read_settings(); //Read from setting files.
	void save_settings(); //Save to setting files
};

class Player {
public:
	Player() {}
	~Player() {}
private:
	/* Load this upon creaiton. */
	UserSettings settings;
	NetworkManager network;

	vector<Player> otherPlayers;
	vector< tIP > otherPlayersIP;
	vector<bool>   isConnected;
};
#endif