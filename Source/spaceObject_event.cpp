#ifndef SPACE_OBJECT_CPP
#define SPACE_OBJECT_CPP
#include "spaceObject.hpp"

void SpaceObject::handleCollision(SpaceObject* other) {
	wasHit = true;
	health -= 10; //TODO : Make it proper, correct for each spaceship.
	return;
}
#endif