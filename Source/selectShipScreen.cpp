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
	XMouseSense = sfg::Scale::Create(0.f, 1.f, .01f, sfg::Scale::Orientation::HORIZONTAL);
	YMouseSense = sfg::Scale::Create(0.f, 1.f, .01f, sfg::Scale::Orientation::HORIZONTAL);
	ColourMeter = sfg::Scale::Create(0.f, 1.f, .01f, sfg::Scale::Orientation::HORIZONTAL);
	playerName = sfg::Label::Create("Your Name : ");
	//shipName = sfg::Label::Create(shipDisplayList->getName()); // default ship name goes here
	enterName = sfg::Entry::Create();
	leftShift->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &SelectShipScreen::onLeftShiftButtonClick, this ) );
	rightShift->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &SelectShipScreen::onRightShiftButtonClick, this ) );
	startJoin->GetSignal( sfg::Widget::OnLeftClick ).Connect( std::bind( &SelectShipScreen::onStartJoinButtonClick, this ) );

}

void SelectShipScreen::~SelectShipScreen() {

}

void SelectShipScreen::onRightShiftButtonClick() {
	currentShip++;
	if(currentShip == (int) shipDisplayList.size())
		currentShip = 0;
}

void SelectShipScreen::onLeftShiftButtonClick() {
	currentShip --;
	if(currentShip < 0)
		currentShip = ((int) shipDisplayList.size()) - 1;
}

void SelectShipScreen::onStartJoinButtonClick() {
	//go to next window
}

void SelectShipScreen::setMouseSensitivity() {
	usrptr->settings->mouseSensitivity.setX(XMouseSense->GetValue());
	usrptr->settings->mouseSensitivity.setY(YMouseSense->GetValue());
}

void SelectShipScreen::setUserSettings() {

}

void SelectShipScreen::Run() {

}