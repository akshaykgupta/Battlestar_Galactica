#ifndef START_JOIN_SCREEN
#define START_JOIN_SCREEN
#include "helpers.hpp"

class StartJoinScreen {
public:
	StartJoinScreen();
	~StartJoinScreen();

	void onStartButtonClick();
	void onJoinButtonClick();
	void Run();
private:
	Player* usrptr;
	sfg::Label::Ptr ipLabel,portLabel,helpLabel, nPlayersLabel;
	sfg::Entry::Ptr myIPEntry , myPortEntry, otherIPEntry, otherPortEntry, nPlayersEntry;
	sfg::Button::Ptr startButton , joinButton;
};
#endif