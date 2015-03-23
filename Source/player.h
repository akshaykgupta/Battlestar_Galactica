#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>

#include "networkManager.cpp"
#include <unordered_map>
/* Boost includes. no special linkers. */
#include <boost/config.hpp>
#include <boost/bimap.hpp>

/**
This file is the header file for userSettings and also the player.
*/
using namespace std;

/* Auxillary things for keyboard mapping. */
enum KeyboardInput {};
typedef boost::bimap<int,KeyboardInput> KeyboardMapping;
typedef KeyboardMapping::value_type keymap_type;

class UserSettings {
public:
	/* Sensitivity and stuff. */
	glm::vec3 mouseSensitivity;	   //Along x,y,z.
	KeyboardMapping keyboardMapping;

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

	int playerIdx; 						//which space object is mine.
	std::vector<SpaceObject> players;	//
	std::vector<SpaceObject> miscobject;//Asteroids, debris and the sort.

	vector<Player> otherPlayers;
	vector< tIP > otherPlayersIP;
	vector<bool>   isConnected;
};
#endif