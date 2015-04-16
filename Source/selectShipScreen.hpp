#ifndef SELECT_SHIP_SCREEN
#define SELECT_SHIP_SCREEN

#include "helpers.hpp"

class SelectShipScreen {
private:
	//Player that calls this window
	Player* usrptr;
	
	//All the buttons on this window
	sfg::Button::Ptr leftShift;
	sfg::Button::Ptr rightShift;
	sfg::Button::Ptr startJoin;

	sfg::Scale::Ptr XMouseSense;
	sfg::Scale::Ptr YMouseSense;
	sfg::Scale::Ptr ColourMeter;
	
	/* pain incoming. 
	map characters to sf::Keyboard::Key , very very painful :(
	->made to string functions, to make life less painful.
	*/
	std::vector< std::pair<sfg::Label::Ptr, sfg::Entry::Ptr> > userSettings;
	
	sfg::Button::Ptr resetSettings;
	sfg::Button::Ptr saveSettings;

	sfg::Label::Ptr playerName;
	sfg::Entry::Ptr enterName;
	sfg::Label::Ptr shipName;
	//List of ships
	std::vector<SpaceObject*> shipDisplayList;

	int currentShip;
	bool startjoin;

	sfg::SFGUI sfgui;
public:

	SelectShipScreen();

	~SelectShipScreen();

	void onRightShiftButtonClick();

	void onLeftShiftButtonClick();

	void onStartJoinButtonClick();

	void setMouseSensitivity();


};
#endif