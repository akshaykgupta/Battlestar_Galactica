#ifndef HELPERS_H
#define HELPERS_H
/** c++ includes */

#include <sys/stat.h>

#include <string.h> //because character arrays.
#include <iostream>
#include <fstream>
/** sfml includes */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
/** physics includes */
#include <btBulletDynamicsCommon.h>

#include <boost/config.hpp>
#include <boost/bimap.hpp>
#include <boost/bimap/support/lambda.hpp>

/* math! */
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

inline bool doesFileExist(std::string fname) {
	struct stat buffer;
	return (stat( fname.c_str() , &buffer ) == 0 );
}
/**
#defines.
*/
const std::string RSC_DIR= "Resource/"; //shouldn't need this, ideally.
const std::string PHY_RSC_DIR =  "Resource/Physics/";
const std::string OBJ_RSC_DIR = "Resource/Render/";
const std::string MUSIC_RSC_DIR = "Resource/Music/";
const std::string SW_MUSIC = "SW";
const std::string HEALTH_FNAME  = "health";
const std::string AMMO_FNAME  = "ammo";
const std::string TIEF_FNAME  = "tiefighter";
const std::string ASTEROID_FNAME  = "asteroid";
const std::string XWING_FNAME  = "xwing";
const std::string MF_FNAME  = "mf";
const std::string UFO_FNAME  = "ufo";
const std::string OBJ_EXTENSION = ".obj";
const std::string PHY_EXTENSION = ".lhc";
const std::string MUSIC_EXTENSION = ".ogg";
class SpaceObject;
class Player;
class NetworkManager;
struct Weapon;
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
		dynamicsWorld->setGravity(btVector3(0,0,0));
    }
    ~BulletWorld() {
		    delete solver;
		    delete collisionConfiguration;
		    delete dispatcher;
		    delete broadphase;
		    delete dynamicsWorld;
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
#include "userSettings.hpp"
#include "weapon.hpp"
#include "message.hpp"
#endif