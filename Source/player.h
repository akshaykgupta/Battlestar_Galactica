#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
/* GLM! */
#include <glm/glm.hpp>
/* Boost includes. no special linkers. */
#include <boost/config.hpp>
#include <boost/bimap.hpp>

#include "networkManager.h"
#include "spaceObject.h"

/**
This file is the header file for userSettings and also the player.
*/
using namespace std;

/* Auxillary things for keyboard mapping. */
enum KeyboardInput {};
typedef boost::bimap<int,KeyboardInput> KeyboardMapping;
typedef KeyboardMapping::value_type keymap_type;

struct GameEvent {
	PLAYER_PROTOCOL eventType;
	//TODO: +Aux data.
};

struct WorldState {
	//needs to contain a lot of stuff.
	vector<PlayerInfo> playerInfo;
	vector<SpaceObject> objectsInSpace;
};

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


	/** Debugging functions -- The boolean is for toggle debug mode. */
	void dprint(bool debug_cuboid=false); //the d stands for Debug.
	void drender(bool debug_cuboid=false);

	/** glut-linking-event handlers. */
	void keyboardHandler(); //Takes in keyboard stuff.
	void mouseHandler(); //Takes in mouse position.
	void shootHandle(); //Takes in clicked point?
	void shotHandle(GameEvent); //I got shot, handle it.
	void updateGameState();
			
private:
	/* Load this upon creaiton. */
	UserSettings settings;
	NetworkManager manager;
	std::vector< GameEvent > todolist; //List of all messages received etc.

	WorldState world;
};
#endif