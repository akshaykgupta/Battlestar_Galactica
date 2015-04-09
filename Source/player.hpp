#ifndef PLAYER_H
#define PLAYER_H

#include "helpers.hpp"
#include "spaceObject.hpp"
#include "spaceObject_load.cpp"
#include "spaceObject_render.cpp"
#include "spaceObject_event.cpp"
#include "spaceObject_getsets.cpp"
#include "networkManager.cpp"
#include "skybox.cpp"

typedef boost::bimap< int, SpaceObject* > spaceObjWeed;
typedef spaceObjWeed::value_type spaceObjWeedNormal;
typedef spaceObjWeed::left_value_type spaceObjWeedLeft; 
typedef spaceObjWeed::right_value_type spaceObjWeedRight;
struct HUD{
//Elements to show on the screen.

};

class Player {
private:
	/* misc data. */
	OBJECT_TYPE fighterType;
	UserSettings* settings;
	HUD hud;
	SpaceObject* fighter;
	State* myState;
	NetworkManager* network;
	Message* myMessage;
	/* Rendering geometry */
	sf::Window wnd; //Window that things run on.
	/* Physics geometry. */
	BulletWorld* bulletWorld;
	sf::Music* music;
	boost::bimap< int, SpaceObject* > EveryOne;
	std::string SKYBOX_IMG;
	SkyBox* skybox;
	float skybox_size;
	double halfWindowSizeX;
	double halfWindowSizeY;

	int camera_idx;
public:
	Player();
	~Player();

	void init_bulletWorld();
	void init_fighter();
	/* collision */
	static bool collisionCallback(btManifoldPoint& cp,
		const btCollisionObjectWrapper* obj1,int id1,int index1,
		const btCollisionObjectWrapper* obj2,int id2,int index2);


	void handle_event(sf::Event& event,sf::Window& window);

	void update_state(double dt);
	void render_state(double dt);
	void setup_game_screen(double,double);
	void loadSettings(); //includes HUD settings.
	void saveSettings();
	void playMusic(bool dflag = false);
	void handleEvent();
	/* game loop functions. */
	void game_loop();
	void select_ship_screen();
	void startjoin_screen();
	void start_game(); 
	void connect_game();
	void waiting_screen();
	void race_begin();
	void race_end();
	void game_over();
	
	//TODO : addSpaceObjectToWorld( cool-network-struct )
	bool addToEveryOne(int,SpaceObject*); //------------PASS THE SPACE OBJ AFTER INSTANTIATING IT----------//
	void fire_laser();
	void toggle_camera(double winX, double winY);
	/** gets and sets */
	UserSettings* 	getSettings();
	BulletWorld* 	getBulletWorld();
	SpaceObject* 	getFighter();
	void 			setFighterType(OBJECT_TYPE _t);
	OBJECT_TYPE 	getFighterType();
	SpaceObject*	getSpaceObject(int); 
	int 			getID(SpaceObject*);
	void getWindowSize(double & x, double & y);
	/** debuggers */
	void debug();

};
#endif