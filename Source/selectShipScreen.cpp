#include "selectShipScreen.hpp"

void SelectShipScreen::SelectShipScreen() {
	currentShip = 0;
	leftShift = sfg::Button::Create();
	//sf::Image leftsfImage;
	//leftsfImage.loadFromFile("");
	// sfg::Image::Ptr leftsfgImage = sfg::Image::Create(leftsfImage);
	// leftShift->setImage(leftsfgImage);
	//sf::Image rightsfImage;
	//rightsfImage.loadFromFile("");
	// sfg::Image::Ptr rightsfgImage = sfg::Image::Create(rightsfImage);
	// rightShift->setImage(rightsfgImage);
	startJoin = sfg::Button::Create();
	resetSettings = sfg::Button::Create();
	XMouseSense = sfg::Scale::Create(0.f, 1.f, .01f, sfg::Scale::Orientation::HORIZONTAL);
	YMouseSense = sfg::Scale::Create(0.f, 1.f, .01f, sfg::Scale::Orientation::HORIZONTAL);
	ColourMeter = sfg::Scale::Create(0.f, 1.f, .01f, sfg::Scale::Orientation::HORIZONTAL);
	playerName = sfg::Label::Create("Your Name : ");
	//shipName = sfg::Label::Create(shipDisplayList->getName()); // default ship name goes here
	enterName = sfg::Entry::Create();
	leftShift->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &SelectShipScreen::onLeftShiftButtonClick, this ) );
	rightShift->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &SelectShipScreen::onRightShiftButtonClick, this ) );
	startJoin->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &SelectShipScreen::onStartJoinButtonClick, this ) );
	resetSettings->GetSignal(sfg::Widget::OnLeftClick ).Connect( std::bind(&SelectShipScreen::onResetSettingsButtonClick , this) );
	saveSettingss->GetSignal(sfg::Widget::OnLeftClick ).Connect( std::bind(&SelectShipScreen::onSaveSettingsButtonClick , this) );
}

void SelectShipScreen::~SelectShipScreen() {

}

void SelectShipScreen::onRightShiftButtonClick() {
	currentShip++;
	if(currentShip == (int) shipDisplayList.size()) {
		currentShip = 0;
	}
}

void SelectShipScreen::onLeftShiftButtonClick() {
	currentShip --;
	if(currentShip < 0) {
		currentShip = ((int) shipDisplayList.size()) - 1;
	}
}

void SelectShipScreen::onStartJoinButtonClick() {
	//go to next window
}

void SelectShipScreen::setMouseSensitivity() {
	usrptr->getSettings()->mouseSensitivity.setX(XMouseSense->GetValue());
	usrptr->getSettings()->mouseSensitivity.setY(YMouseSense->GetValue());	
}

void SelectShipScreen::setCrosshairColor() {

}

void SelectShipScreen::setUserName() {
	usrptr->getSettings()->name = enterName->GetText();
}

void SelectShipScreen::onResetSettingsButtonClick() {
	XMouseSense->SetValue( usrptr->getSettings()->mouseSensitivity.getX());
	YMouseSense->SetValue( usrptr->getSettings()->mouseSensitivity.getY());
	
}

void SelectShipScreen::onSaveSettingsButtonClick() {
	setUserName();
	setMouseSensitivity();
	setCrosshairColor();
	setUserSettings();
}

void SelectShipScreen::setUserSettings() {
	//ASSERT: userSettings.size() <= #(keyboard inputs)
	for(int i=0; i<userSettings.size(); ++i) {
		//KeyboardInput(i)
		std::string entryText = userSettings[i].second.GetText();
		sf::Keyboard::Key key = keyFromString(entryText);
		usrptr->getSettings()->updateKeyMap(key , (KeyboardInput)i );
	}
	usrptr->getSettings()->saveSettingss();
}

void SelectShipScreen::Run() {

}