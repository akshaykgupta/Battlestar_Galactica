#ifndef START_JOIN_SCREEN_CPP
#define START_JOIN_SCREEN_CPP
#include "startJoinScreen.hpp"

StartJoinScreen::StartJoinScreen(Player* _usr) {
	usrptr = _usr;
}

StartJoinScreen::~StartJoinScreen() {

}

void StartJoinScreen::onStartButtonClick() {
	std::string myip = myIPEntry->GetText();
	std::string str_myport = myPortEntry->GetText();
	unsigned short myport = (unsigned short) stoul(str_myport);
	
	usrptr->setGameMode(myip, myport , /*joinmode=*/true);
}

void StartJoinScreen::onJoinButtonClick() {
	std::string myip = myIPEntry->GetText();
	std::string str_myport = myPortEntry->GetText();
	unsigned short myport = (unsigned short) stoul(str_myport);
	
	std::string otherip = otherIPEntry->GetText();
	unsigned short otherport = (unsigned short) stoul( otherPortEntry->GetText() );
	usrptr->setGameMode(myip, myport , /*joinmode=*/false , otherip , otherport );
}

void StartJoinScreen::Run() {

}
#endif