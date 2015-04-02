ifndef HELPERS_H
#define HELPERS_H
/** c++ includes */
#include <string.h> //because character arrays.
#include <iostream>
/** sfml includes */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
/** physics includes */
#include <btBulletDynamicsCommon.h>

/**
#defines.
*/
const std::string RSC_DIR= "../Resource/"; //shouldn't need this, ideally.
class SpaceObject;
class Player;
class NetworkManager;

#include <tuple>
/** networking typedefs */
typedef std::tuple< int,int,int,int > tIP4;
typedef int Time ; //discretized?

/** communication protocols. */
enum OBJECT_TYPE {
	ASTEROID = 0,
	
	HEALTH = 1,
	AMMO = 2,
	
	XWING = 3,
	TIE = 4,
	MF = 5,

	UFO = 10000
};


/** Message_type is the protocol within the network manager. */
enum MESSAGE_PROTOCOL { GENDATA=0 , //use these messages as an internal protocol.
					LASERDATA=1,
					COLLISIONDATA=2,
					CHATDATA=3,
					CONNECTDATA=4,
					PINGDATA=5
};
/** enum Event Type is the protocol between NetworkManager and Player */
enum PLAYER_PROTOCOL { //push these messages into the player's queue.
	GENDATA_P=0 , 
	LASERDATA_P=1,
	COLLISIONDATA_P=2,
	CHATDATA_P=3,
	CONNECTDATA_P=4,
	DROPDATA_P=5
};
/** Intra-player helper functions */

/** Bullet Physics' World. */
struct BulletWorld {
    btBroadphaseInterface* broadphase;// = new btDbvtBroadphase();
    btDefaultCollisionConfiguration* collisionConfiguration;// = new btDefaultCollisionConfiguration();
    btCollisionDispatcher* dispatcher;// = new btCollisionDispatcher(collisionConfiguration);
    btSequentialImpulseConstraintSolver* solver;// = new btSequentialImpulseConstraintSolver;
    btDiscreteDynamicsWorld* dynamicsWorld;// = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);

    BulletWorld() {
    	broadphase = new btDbvtBroadphase();
		collisionConfiguration = new btDefaultCollisionConfiguration();
		dispatcher = new btCollisionDispatcher(collisionConfiguration);
		solver = new btSequentialImpulseConstraintSolver;
		dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
    }
    ~BulletWorld() {
    	    delete dynamicsWorld;
		    delete solver;
		    delete collisionConfiguration;
		    delete dispatcher;
		    delete broadphase;
    }
};

/** PlayerInfo is used by the network for initializing player*/
struct PlayerInfo {
	std::string playerName;
	tIP4 ipAddress;
	Time lastMessageTime;
	OBJECT_TYPE objtype; //Communicated this to the player, maybe?
	//TODO: Aux data.
};


/** game state. */
class SpaceObject; //forward declaration.
struct WorldState {
	//needs to contain a lot of stuff.
	vector<PlayerInfo> playerInfo;
	vector<SpaceObject> objectsInSpace;
};

/** event */
struct GameEvent {
	PLAYER_PROTOCOL eventType;
	//TODO: +Aux data.
};


/** event handlers */
enum KeyboardInput {};
typedef boost::bimap<int,KeyboardInput> KeyboardMapping;
typedef KeyboardMapping::value_type keymap_type;

//class user settings. 
class UserSettings {
public:
	/* Sensitivity and stuff. */
	glm::vec3 mouseSensitivity;	   //Along x,y,z.
	KeyboardMapping keyboardMapping;
	void read_settings(); //Read from setting files.
	void save_settings(); //Save to setting files
};

#endif