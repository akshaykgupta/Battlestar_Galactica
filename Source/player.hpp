#ifndef PLAYER_H
#define PLAYER_H

#include "helpers.hpp"
#include "spaceObject.hpp"
#include "spaceObject_load.cpp"
#include "spaceObject_render.cpp"
#include "spaceObject_event.cpp"
#include "spaceObject_getsets.cpp"
typedef boost::bimap< int, SpaceObject* > spaceObjWeed;
typedef spaceObjWeed::value_type spaceObjWeedNormal;
typedef spaceObjWeed::left_value_type spaceObjWeedLeft; 
typedef spaceObjWeed::right_value_type spaceObjWeedRight;
class HUD{
//Elements to show on the screen.
};

class Player {
private:
	/* misc data. */
	OBJECT_TYPE fighterType;
	UserSettings* settings;
	HUD hud;
	SpaceObject* fighter;
	/* Rendering geometry */

	/* Physics geometry. */
	BulletWorld* bulletWorld;
	sf::Music* music;
	boost::bimap< int, SpaceObject* > EveryOne; 	
public:
	Player();
	~Player();

	void init_bulletWorld();
	void init_fighter();
	/* collision */
	bool collisionCallback(btManifoldPoint& cp,
		const btCollisionObject* obj1,int id1,int index1,
		const btCollisionObject* obj2,int id2,int index2);


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
	
	/** gets and sets */
	UserSettings* 	getSettings();
	BulletWorld* 	getBulletWorld();
	SpaceObject* 	getFighter();
	void 			setFighterType(OBJECT_TYPE _t);
	OBJECT_TYPE 	getFighterType();
	SpaceObject*	getSpaceObject(int); 
	int 			getID(SpaceObject*);
	/** debuggers */
	void debug();

};
#endif