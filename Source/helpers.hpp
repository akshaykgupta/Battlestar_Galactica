#ifndef HELPERS_H
#define HELPERS_H
/** c++ includes */
using namespace std;


#include <string.h> //because character arrays.
#include <iostream>
#include <fstream>
/** sfml includes */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
/** physics includes */
#include <btBulletDynamicsCommon.h>

#include <boost/config.hpp>
#include <boost/bimap.hpp>
#include <boost/bimap/support/lambda.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <sstream>

/* math! */
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

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
const std::string DEBRIS_FNAME  = "debris";
const std::string ENDPOINT_FNAME  = "endpoint";
const std::string SKYRISE_TALL_FNAME  = "skyrise_tall";
const std::string SKYRISE_FAT_FNAME  = "skyrise_fat";
const std::string OBJ_EXTENSION = ".obj";
const std::string PHY_EXTENSION = ".lhc";
const std::string MUSIC_EXTENSION = ".ogg";
const std::string WORLD_PHY_FNAME = "Resource/myWorld.avril";
class SpaceObject;
class Player;
class NetworkManager;
struct Weapon;
struct State;
struct Message;

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


enum KeyboardInput {
	NONE = -1 ,
	ACCELERATE, DECELERATE, STRAFE_LEFT, STRAFE_RIGHT, ASCEND, DESCEND, /* Translational Movement */
	PITCH_UP, PITCH_DOWN, YAW_LEFT, YAW_RIGHT, ROLL_LEFT, ROLL_RIGHT, /* Rotational Movement */
	TOGGLE_FULLSCREEN, TOGGLE_CAM, /* camera type things. */
	FIRE_WEAPON , TOGGLE_WEAPON, USE_ABILITY, /* weaponry */
	ESCAPE, /**/
	START_CHAT, ESCAPE_CHAT, SEND_CHAT

};
//Utility functions.

std::string toString(sf::Keyboard::Key key) {
	string ans;
	switch(key) {
        case (A		        ) : { ans = "A"; break; }
        case (B	            ) : { ans = "B"; break; }
        case (C	            ) : { ans = "C"; break; }
        case (D	            ) : { ans = "D"; break; }
        case (E	            ) : { ans = "E"; break; }
        case (F	            ) : { ans = "F"; break; }
        case (G	            ) : { ans = "G"; break; }
        case (H	            ) : { ans = "H"; break; }
        case (I	            ) : { ans = "I"; break; }
        case (J	            ) : { ans = "J"; break; }
        case (K	            ) : { ans = "K"; break; }
        case (L	            ) : { ans = "L"; break; }
        case (M	            ) : { ans = "M"; break; }
        case (N	            ) : { ans = "N"; break; }
        case (O	            ) : { ans = "O"; break; }
        case (P	            ) : { ans = "P"; break; }
        case (Q	            ) : { ans = "Q"; break; }
        case (R	            ) : { ans = "R"; break; }
        case (S	            ) : { ans = "S"; break; }
        case (T	            ) : { ans = "T"; break; }
        case (U	            ) : { ans = "U"; break; }
        case (V	            ) : { ans = "V"; break; }
        case (W	            ) : { ans = "W"; break; }
        case (X	            ) : { ans = "X"; break; }
        case (Y	            ) : { ans = "Y"; break; }
        case (Z	            ) : { ans = "Z"; break; }
        case (Num0	         ) : { ans = "Num0"; break; }
        case (Num1	         ) : { ans = "Num1"; break; }
        case (Num2	         ) : { ans = "Num2"; break; }
        case (Num3	         ) : { ans = "Num3"; break; }
        case (Num4	         ) : { ans = "Num4"; break; }
        case (Num5	         ) : { ans = "Num5"; break; }
        case (Num6	         ) : { ans = "Num6"; break; }
        case (Num7	         ) : { ans = "Num7"; break; }
        case (Num8	         ) : { ans = "Num8"; break; }
        case (Num9	         ) : { ans = "Num9"; break; }
        case (Escape      	) : { ans = "Esc"; break; }
        case (LControl    	) : { ans = "LCtrl"; break; }
        case (LShift      	) : { ans = "LShft"; break; }
        case (LAlt        	) : { ans = "LAlt"; break; }
        case (LSystem     	) : { ans = "LSys"; break; }
        case (RControl    	) : { ans = "RCtrl"; break; }
        case (RShift      ) : { ans = "RShft"; break; }
        case (RAlt        ) : { ans = "RAlt"; break; }
        case (RSystem     ) : { ans = "RSys"; break; }
        case (Menu        ): { ans = "Menu"; break; }
        case (LBracket     ) : { ans = "LBracket"; break; }
        case (RBracket     ) : { ans = "RBracket"; break; }
        case (SemiColon    ) : { ans = ";"; break; }
        case (Comma        ) : { ans = ","; break; }
        case (Period       ) : { ans = "."; break; }
        case (Quote        ) : { ans = "\""; break; }
        case (Slash        ) : { ans = "\\"; break; }
        case (BackSlash    ) : { ans = "/"; break; }
        case (Tilde        ) : { ans = "~"; break; }
        case (Equal        ) : { ans = "="; break; }
        case (Dash         ) : { ans = "-"; break; }
        case (Space   		) : { ans = " "; break; }
        case (Return  		) : { ans = "return"; break; }
        case (BackSpace   		) : { ans = "backspace"; break; }
        case (Tab         		) : { ans = "tab"; break; }
        case (PageUp    		) : { ans = "pageup"; break; }
        case (PageDown    		) : { ans = "pagedown"; break; }
        case (End   		) : { ans = "end"; break; }
        case (Home  		) : { ans = "home"; break; }
        case (Insert   		) : { ans = "Insert"; break; }
        case (Delete   		) : { ans = "Delete"; break; }
        case (Add          ) : { ans = "Add"; break; }
        case (Subtract     ) : { ans = "Subtract"; break; }
        case (Multiply     ) : { ans = "Multiply"; break; }
        case (Divide       ) : { ans = "Divide"; break; }
        case (Left         ) : { ans = "Left"; break; }
        case (Right        ) : { ans = "Right"; break; }
        case (Up         ) : { ans = "Up"; break; }
        case (Down         ) : { ans = "Down"; break; }
        case (Numpad0      ) : { ans = "Numpad0"; break; }
        case (Numpad1      ) : { ans = "Numpad1"; break; }
        case (Numpad2      ) : { ans = "Numpad2"; break; }
        case (Numpad3      ) : { ans = "Numpad3"; break; }
        case (Numpad4      ) : { ans = "Numpad4"; break; }
        case (Numpad5      ) : { ans = "Numpad5"; break; }
        case (Numpad6      ) : { ans = "Numpad6"; break; }
        case (Numpad7      ) : { ans = "Numpad7"; break; }
        case (Numpad8      ) : { ans = "Numpad8"; break; }
        case (Numpad9      ) : { ans = "Numpad9"; break; }
        case (F1          ) : { ans = "F1"; break; }
        case (F2          ) : { ans = "F2"; break; }
        case (F3          ) : { ans = "F3"; break; }
        case (F4          ) : { ans = "F4"; break; }
        case (F5          ) : { ans = "F5"; break; }
        case (F6          ) : { ans = "F6"; break; }
        case (F7          ) : { ans = "F7"; break; }
        case (F8          ) : { ans = "F8"; break; }
        case (F9          ) : { ans = "F9"; break; }
        case (F10          ) : { ans = "F10"; break; }
        case (F11          ) : { ans = "F11"; break; }
        case (F12          ) : { ans = "F12"; break; }
        case (F13          ) : { ans = "F13"; break; }
        case (F14          ) : { ans = "F14"; break; }
        case (F15         ) : { ans = "F15"; break; }
        case (Pause        ) : { ans = "Pause"; break; }
		default : { ans = "not valid";break;}
	}
	return ans;
}

std::string toString(KeyboardInput key) {
	string ans;
	switch(key) {
		case (ACCELERATE) : { ans = "accelerate"; break; }
		case (DECELERATE) : { ans = "decelerate"; break; }
		case (STRAFE_LEFT) : { ans = "strafe-left"; break; }
		case (STRAFE_RIGHT) : { ans = "strafe-right"; break; }
		case (ASCEND) : { ans = "ascend"; break; }
		case (DESCEND) : { ans = "descend"; break; }
		case (PITCH_UP) : { ans = "pitch-up" ; break; }
		case (PITCH_DOWN) : { ans = "pitch-down" ; break; }
		case (YAW_LEFT) : { ans = "yaw-left" ; break; }
		case (YAW_RIGHT) : { ans = "yaw-right" ; break; }
		case (ROLL_LEFT) : { ans = "right-left" ; break; }
		case (ROLL_RIGHT) : { ans = "roll-right" ; break; }
		case (TOGGLE_FULLSCREEN) : { ans = "toggle-fscrn" ; break; }
		case (TOGGLE_CAM) : { ans = "toggle-cam" ; break; }
		case (FIRE_WEAPON) : { ans = "shoot" ; break; }
		case (TOGGLE_WEAPONLE) : { ans = "toggle-weapon" ; break; }
		case (USE_ABILITY) : { ans = "use-ability" ; break; }
		case (ESCAPE) : { ans = "escape" ; break; }
		case (START_CHAT) : { ans = "start-chat" ; break; }
		case (ESCAPE_CHAT) : { ans = "escape-chat" ; break; }
		case (SEND_CHAT) : { ans = "send-chat" ; break; }
		default : { ans = "not valid";break;}
	}
	return ans;	
}
sf::Keyboard::Key fromString(std::string str) {
	sf::Keyboard::Key ans=Unknown;
	switch(str) {
		case("A") : { ans=A; break; }
		case("B") : { ans=B; break; }
		case("C") : { ans=C; break; }
		case("D") : { ans=D; break; }
		case("E") : { ans=E; break; }
		case("F") : { ans=F; break; }
		case("G") : { ans=G; break; }
		case("H") : { ans=H; break; }
		case("I") : { ans=I; break; }
		case("J") : { ans=J; break; }
		case("K") : { ans=K; break; }
		case("L") : { ans=L; break; }
		case("M") : { ans=M; break; }
		case("N") : { ans=N; break; }
		case("O") : { ans=O; break; }
		case("P") : { ans=P; break; }
		case("Q") : { ans=Q; break; }
		case("R") : { ans=R; break; }
		case("S") : { ans=S; break; }
		case("T") : { ans=T; break; }
		case("U") : { ans=U; break; }
		case("V") : { ans=V; break; }
		case("W") : { ans=W; break; }
		case("X") : { ans=X; break; }
		case("Y") : { ans=Y; break; }
		case("Z") : { ans=Z; break; }
		case("Num0") : { ans=Num0; break; }
		case("Num1") : { ans=Num1; break; }
		case("Num2") : { ans=Num2; break; }
		case("Num3") : { ans=Num3; break; }
		case("Num4") : { ans=Num4; break; }
		case("Num5") : { ans=Num5; break; }
		case("Num6") : { ans=Num6; break; }
		case("Num7") : { ans=Num7; break; }
		case("Num8") : { ans=Num8; break; }
		case("Num9") : { ans=Num9; break; }
		case("Esc") : { ans=Esc; break; }
		case("LCtrl") : { ans=LControl; break; }
		case("LShft") : { ans=LShift; break; }
		case("LAlt") : { ans=LAlt; break; }
		case("LSys") : { ans=LSystem; break; }
		case("RCtrl") : { ans=RControl; break; }
		case("RShft") : { ans=RShift; break; }
		case("RAlt") : { ans=RAlt; break; }
		case("RSys") : { ans=RSystem; break; }
		case("Menu") : { ans=Menu; break; }
		case("LBracket") : { ans=LBracket; break; }
		case("RBracket") : { ans=RBracket; break; }
		case("pageup") : { ans=PageUp; break; }
		case("pagedown") : { ans=PageDown; break; }
		case("Left") : { ans=Left; break; }
		case("Right") : { ans=Right; break; }
		case("Up") : { ans=Up; break; }
		case("Down") : { ans=Down; break; }
		case("Numpad0") : { ans=Numpad0; break; }
		case("Numpad1") : { ans=Numpad1; break; }
		case("Numpad2") : { ans=Numpad2; break; }
		case("Numpad3") : { ans=Numpad3; break; }
		case("Numpad4") : { ans=Numpad4; break; }
		case("Numpad5") : { ans=Numpad5; break; }
		case("Numpad6") : { ans=Numpad6; break; }
		case("Numpad7") : { ans=Numpad7; break; }
		case("Numpad8") : { ans=Numpad8; break; }
		case("Numpad9") : { ans=Numpad9; break; }
		case("F1") : { ans=F1; break; }
		case("F2") : { ans=F2; break; }
		case("F3") : { ans=F3; break; }
		case("F4") : { ans=F4; break; }
		case("F5") : { ans=F5; break; }
		case("F6") : { ans=F6; break; }
		case("F7") : { ans=F7; break; }
		case("F8") : { ans=F8; break; }
		case("F9") : { ans=F9; break; }
		case("F10") : { ans=F10; break; }
		case("F11") : { ans=F11; break; }
		case("F12") : { ans=F12; break; }
		case("F13") : { ans=F13; break; }
		case("F14") : { ans=F14; break; }
		case("F15") : { ans=F15; break; }
		default:{ans=Unknown;break;}
	}
	return ans;
}

typedef boost::bimap< sf::Keyboard::Key , KeyboardInput > KeyboardMapping;
typedef KeyboardMapping::value_type keymap_type;

enum WEAPON_TYPE {
	WEAK_LASER = 1,
	MEDIUM_LASER = 2,
	STRONG_LASER = 3,
	CANNON = 4,
	HEAT_MISSILE = 5,
	FORCE = 6
};

/** communication protocols. */
enum OBJECT_TYPE {
	ASTEROID = 0,
	HEALTH = 1,
	AMMO = 2,	
	XWING = 3,
	TIE = 4,
	MF = 5,
	ENDPOINT = 6,
	SKYRISE_TALL = 7,
	SKYRISE_FAT = 8,
	DEBRIS = 9,
	UFO = 10000
};


/** Message_type is the protocol within the network manager. */
enum MESSAGE_PROTOCOL { GENDATA=1 , //use these messages as an internal protocol.
					LASERDATA=2,
					COLLISIONDATA=4,
					CHATDATA=8,
					CONNECTDATA=16,
					SETCONNECTDATA=32
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

class UserSettings {
public:
	/* Sensitivity and stuff. */
	std::string name;
	btVector3 mouseSensitivity;	   //Along x,y,z.
	KeyboardMapping keyboardMapping;
	float fov;
	float HUDCross_r,HUDCross_g,HUDCross_b;
	int defaultScreenSizeX,defaultScreenSizeY;
	void set_default();
	void read_settings(); //Read from setting files.
	void save_settings(); //Save to setting files
	/* wrappers for the bimap. */
	void 				updateKeyMap(sf::Keyboard::Key _key , KeyboardInput _action);
	KeyboardInput 		getAction(sf::Keyboard::Key _key); // -1 returns NONE.
	sf::Keyboard::Key 	getKey(KeyboardInput _action); //returns -1 if nothing is mapped.
};

struct State {
	int health;
	int ammo;
	std::vector<float> transform; //position, rotation.
	std::vector<float> linearVelocity, angularVelocity;
	OBJECT_TYPE objType;
	
	State();	
	~State();
	State(State& other);
	State& operator= (State& other);
	State(int h,int am, btTransform& t, btVector3& lv , btVector3& av, OBJECT_TYPE _t);
	void setData(int h,int am, btTransform& t, btVector3& lv , btVector3& av, OBJECT_TYPE& _t);
	void getData(int& h, int& am, btTransform& t, btVector3& velo, btVector3& avelo , OBJECT_TYPE& _t);
	
	template<typename Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar & health;
		ar & transform;
		ar & linearVelocity;
		ar & angularVelocity;
		ar & objType;
	}
};

struct Message {
	int msgType;
	State ship; //general data - includes myShip details.
	//collision data, is essentially health and new transform.
	std::string chatMessage;	 //chat data.
	std::vector<float> laserFrom,laserTo; //laser data. LINE SEGMENT.
	int wpnType;
	/* Connection data */
	std::string newConnectorIP;
	unsigned short newConnectorPort;
	/*
		IDEA : Forward this message to everyone, and respond to the sender with my details.
	*/
	std::string worldData; //file name to load from.

	Message(int prot , 
		int& h, int& am, btTransform& t, btVector3& velo, btVector3& avelo , OBJECT_TYPE& _t, //For state
		btVector3& _laserFrom , btVector3& _laserTo , int& _wpnType , 
		std::string ip = "" , unsigned short port = 0, std::string chatmsg = "" , std::string worldfile = "");
	Message();
	Message(Message& other);
	Message& operator= (Message& other);
	void setData(int prot , 
		int& h, int& am, btTransform& t, btVector3& velo, btVector3& avelo , OBJECT_TYPE& _t, //For state
		btVector3& _laserFrom , btVector3& _laserTo ,int& _wpnType,
		std::string ip = "" , unsigned short port = 0, std::string chatmsg = "" , std::string worldfile = "");
	void setData(int prot, std::string ip = "", unsigned short port = 0);
	void setData( int prot , State* state , Weapon* wpn );
	void getData(int prot , 
		int& h, int& am, btTransform& t, btVector3& velo, btVector3& avelo , OBJECT_TYPE& _t, //For state
		btVector3& _laserFrom , btVector3& _laserTo ,int& _wpnType,
		std::string& ip, unsigned short port, std::string& chatmsg, std::string& worldfile);
	void getData(btVector3&, btVector3&);
	
	template<typename Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar & msgType;
		ar & ship;
		ar & chatMessage;
		ar & laserFrom;
		ar & laserTo;
		ar & newConnectorIP;
		ar & newConnectorPort;
		ar & worldData;
	}
	void print(){
		cout<<newConnectorIP<<" "<<newConnectorPort<<"\n";
	}
};
struct Weapon {

	Weapon(WEAPON_TYPE t , btVector3 color);
	~Weapon();
	void fireProjectile(btVector3& from, btVector3& to);
	void drawProjectile(btVector3& from, btVector3& to);
	void update();
	WEAPON_TYPE type;
	float strength;
	float r,g,b;
	double regen_rate;
	int max_ammo,ammo;
	bool active;
	int time_left;
	SpaceObject* fighter;
	BulletWorld* world;
	btVector3 last_from, last_to;
	
};

#include <tuple>
/** networking typedefs */
typedef std::tuple< int,int,int,int > tIP4;
typedef int Time ; //discretized?


#endif