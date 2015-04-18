#ifndef START_JOIN_SCREEN_CPP
#define START_JOIN_SCREEN_CPP
#include "startJoinScreen.hpp"

StartJoinScreen::StartJoinScreen(Player* _usr) {
	usrptr = _usr;
	internalRunning = true;
	myIPLabel	=	sfg::Label::Create("ConnectTo-IP:");
	myPortLabel 	=	sfg::Label::Create("ConnectTo-Port:");
	helpLabel 	=	sfg::Label::Create("Start-Join Screen to setup multiplayer.");
	nPlayersLabel	=	sfg::Label::Create("How Many Players?");
	nAIPlayersLabel	=	sfg::Label::Create("How Many AIPlayers?");
	myIPEntry	=	sfg::Entry::Create("Whatsmyip?");
	myPortEntry 	=	sfg::Entry::Create("Whatsmyport?");
	otherIPEntry 	=	sfg::Entry::Create();
	otherPortEntry 	=	sfg::Entry::Create();
	nPlayersEntry 	=	sfg::Entry::Create();
	nAIPlayersEntry	=	sfg::Entry::Create();
	startButton 	=	sfg::Button::Create("Host a round!");
	joinButton	=	sfg::Button::Create("Join a round.");
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
	sf::Window wnd(sf::VideoMode(usrptr->getSettings()->defaultScreenSizeX , usrptr->getSettings()->defaultScreenSizeY), "Select your ship!" , sf::Style::Titlebar | sf::Style::Close/*, sf::ContextSettings(32)*/);
	sfg::SFGUI sfgui;

	//Now, to construct all the widgets.
	auto lonelyTable = sfg::Table::Create();
	//Sorry for a lack of init functions.
	lonelyTable->SetRowSpacings(5.f);
	lonelyTable->SetColumnSpacings(5.f);

	lonelyTable->Attach(helpLabel , sf::Rect<sf::Uint32>(2,0,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	
	lonelyTable->Attach(myIPLabel , sf::Rect<sf::Uint32>(0,2,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	lonelyTable->Attach(myPortLabel , sf::Rect<sf::Uint32>(0,3,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	lonelyTable->Attach(myIPEntry , sf::Rect<sf::Uint32>(1,2,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	lonelyTable->Attach(myPortEntry , sf::Rect<sf::Uint32>(1,3,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	
	lonelyTable->Attach(nPlayersLabel , sf::Rect<sf::Uint32>(0,5,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	lonelyTable->Attach(nAIPlayersLabel , sf::Rect<sf::Uint32>(0,6,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	lonelyTable->Attach(nPlayersEntry , sf::Rect<sf::Uint32>(1,5,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	lonelyTable->Attach(nAIPlayersEntry , sf::Rect<sf::Uint32>(1,6,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	
	lonelyTable->Attach(otrIPLabel , sf::Rect<sf::Uint32>(4,2,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	lonelyTable->Attach(otrPortLabel , sf::Rect<sf::Uint32>(4,3,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	lonelyTable->Attach(otherIPEntry , sf::Rect<sf::Uint32>(5,2,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	lonelyTable->Attach(otherPortEntry , sf::Rect<sf::Uint32>(5,3,1,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );

	lonelyTable->Attach(startButton , sf::Rect<sf::Uint32>(,,2,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );
	lonelyTable->Attach(joinButton , sf::Rect<sf::Uint32>(,,2,1) , sfg::Table::EXPAND|sfg::Table::FILL ,sfg::Table::EXPAND|sfg::Table::FILL );



	//ASSERT : Table is ready.
	auto sfgwnd = sfg::Window::Create("Start Game/Join Game");
	sfgwnd->Add(lonelyTable);
	sfg::Desktop desktop;
	desktop.Add(sfgwnd);

	sf::Event event;
	while(internalRunning) {
		while(wnd.pollEvent(event)) {
			desktop.HandleEvent(event);
			if ( event.type == sf::Event::Closed) {
				internalRunning = false;
			}
		}

		desktop.Update(0.0f);
		sfgui.Display(wnd);
		wnd.display();
	}
}
#endif