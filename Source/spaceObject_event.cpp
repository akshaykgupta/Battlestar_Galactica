#ifndef SPACE_OBJECT_EVENT_CPP
#define SPACE_OBJECT_EVENT_CPP
#include "spaceObject.hpp"

void SpaceObject::handleCollision(SpaceObject* other) {
	wasHit = true;
	health -= 10; //TODO : Make it proper, correct for each spaceship.
	return;
}

void SpaceObject::toggle_weapon() {
	activeWeapon = (activeWeapon+1)%(weapons.size());
}

void SpaceObject::rotate(double pitch, double yaw) {

}


//KEYBOARD FUNCTIONS AHEAD!
void SpaceObject::accelerate() {
	//TODO
}
void SpaceObject::decelerate() {
	//TODO
}
void SpaceObject::strafe_left() {
	//TODO
}
void SpaceObject::strafe_right() {
	//TODO
}
void SpaceObject::ascend() {
	//TODO
}
void SpaceObject::descend() {
	//TODO
}
void SpaceObject::pitch_up() {
	//TODO
}
void SpaceObject::pitch_down() {
	//TODO
}
void SpaceObject::yaw_left() {
	//TODO
}
void SpaceObject::yaw_right() {
	//TODO
}
void SpaceObject::roll_left() {
	//TODO
}
void SpaceObject::roll_right() {
	//TODO
}

#endif