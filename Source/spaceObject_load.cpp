#ifndef SPACE_OBJECT_CPP
#define SPACE_OBJECT_CPP
#include "spaceObject.hpp"

/** file with functions for loading and initializing things.
	Bucket list : Use static VBOs while drawing complicated
*/

SpaceObject(OBJECT_TYPE _type) {
	obj_type = _type;
}

~SpaceObject() {

}

void print(bool dflag) {
	if (!dflag) {
		return;
	}
}
//inits
void SpaceObject::init(Player* _usr , BulletWorld* _world) {
	usr = _usr; //User pointer.
	physics_init();
	render_init();
	return;
}

void SpaceObject::physics_init() {
	switch (obj_type) {
		//TODO : set path names and load the file.
		case ASTEROID : {
			break;
		} case HEALTH : {
			break;
		} case TIE : {
			break;
		} default : {
			std::cout << " Unknown object type. Please ensure that OBJ_Type=" << obj_type << " is defined appropriately. \n";
			return;
		}
	}
}

void SpaceObject::render_init() {
	return;
}

void loadRenderGeometry() {
	return;
}

void loadPhysicsGeometry() {
	return;
}
#endif