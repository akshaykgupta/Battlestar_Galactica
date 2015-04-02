#ifndef PLAYER_H
#define PLAYER_H

#include "helpers.hpp"
#include "spaceObject.hpp"
#include "spaceObject_load.cpp"
#include "spaceObject_render.cpp"
#include "spaceObject_event.cpp"
#include "spaceObject_getsets.cpp"

class HUD{
//Elements to show on the screen.
};

class Player {
private:
	/* misc data. */
	OBJECT_TYPE fighterType;
	UserSettings settings;
	HUD hud;
	SpaceObject* fighter;
	/* Rendering geometry */

	/* Physics geometry. */
	BulletWorld* bulletWorld;
		
public:
	Player();
	~Player();

	void init_bulletWorld();
	void init_fighter();

	void update_state(double dt);
	void render_state(double dt);
	void setup_game_screen(double,double);
	void loadSettings(); //includes HUD settings.
	void saveSettings();


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
	
	/** gets and sets */
	BulletWorld* 	getBulletWorld();
	SpaceObject* 	getFighter();
	void 			setFighterType(OBJECT_TYPE _t);
	OBJECT_TYPE 	getFighterType();
	/** debuggers */
	void debug();

};
#endif