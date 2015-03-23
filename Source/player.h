#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>

#include "networkManager.cpp"
#include <unordered_map>
/**
This file is the header file for userSettings and also the player.
*/
using namespace std;

enum KeyboardInput {};

class UserSettings {
public:
	/* Sensitivity and stuff. */
	glm::vec3 mouseSensitivity;	   //Along x,y,z.
	// need a bimap for keyboard mappings.
	// unordered_map< int , KeyboardInput > keyboardMapping; //Along x,y,z.

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