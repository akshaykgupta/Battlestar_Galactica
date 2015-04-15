#ifndef SELECT_SHIP_SCREEN
#define SELECT_SHIP_SCREEN

#include "helpers.h"

class SelectShipScreen {
private:
	//Player that calls this window
	Player* usrptr;
	
	//All the buttons on this window
	sfg::Button::Ptr leftShiftButton;
	sfg::Button::Ptr rightShiftButton;
	sfg::Button::Ptr startJoin;
	sfg::Scale::Ptr XMouseSense;
	sfg::Scale::Ptr YMouseSense;
	sfg::Scale::Ptr ColourMeter;
	
	
	//List of ships
	std::vector<SpaceObject*> shipDisplayList;

public:

};
#endif