#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "helpers.hpp"
#include "spaceObject.hpp"
#include "networkManager.hpp"
#include "skybox.hpp"

typedef boost::bimap< int, SpaceObject* > spaceObjWeed;
typedef spaceObjWeed::value_type spaceObjWeedNormal;
typedef spaceObjWeed::left_value_type spaceObjWeedLeft; 
typedef spaceObjWeed::right_value_type spaceObjWeedRight;

typedef boost::bimap<int,int> NtoPType;
typedef NtoPType::value_type NtoPTypeNormal;
typedef NtoPType::left_value_type NtoPTypeLeft;
typedef NtoPType::right_value_type NtoPTypeRight;
struct HUD{
//Elements to show on the screen.

};

class Player {
private:
	/* misc data. */


	int nextSpaceObjId;
	OBJECT_TYPE fighterType;
	UserSettings* settings;
	HUD hud;
	SpaceObject* fighter;

	/* network integration */
	State* myState;
	NtoPType NtoP;  // for every network int,there must be a player int
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
	SpaceObject* which_spaceObject(int network_int){
		// if present,return
		auto cit = NtoP.left.find(network_int);
		if (cit != NtoP.left.end())
	    {
	    	int player_int = cit->second;
	    	// return spaceobject corresponding to this player_int
	    	getSpaceObject(player_int);
	    }
	    
	    return nullptr;
	    /* Assert : no player corresponding to this network int means this spaceObject hasn't yet been added */
	}

	bool addtoNtoP(int network_int, int player_int) {
		//TODO: add the pair of network_int and player_int to the bimap.
		NtoP.insert(NtoPTypeNormal(network_int,player_int));
		return true;
	}
		
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

	void connectToNetwork(string, unsigned short, unsigned short);
	void sendMessage();
	void translateMessage(ClientMessage);
	void receiveMessage();
	void handleMessage(Message&, int);

	//TODO : addSpaceObjectToWorld( cool-network-struct )
	bool addToEveryOne(int,SpaceObject*); //------------PASS THE SPACE OBJ AFTER INSTANTIATING IT----------//
	bool add_object(SpaceObject*); //------------PASS THE SPACE OBJ AFTER INSTANTIATING IT----------//
	
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