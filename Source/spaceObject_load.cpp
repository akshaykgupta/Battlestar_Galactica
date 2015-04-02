#ifndef SPACE_OBJECT_CPP
#define SPACE_OBJECT_CPP
#include "spaceObject.hpp"

/** file with functions for loading and initializing things.
	Bucket list : Use static VBOs while drawing complicated
*/

SpaceObject(OBJECT_TYPE _type) {
	obj_type = _type;
	objpath = OBJ_RSC_DIR;
	phypath = PHY_RSC_DIR;

}

~SpaceObject() {
	//figure out which order to delete things in.
	delete body;
	delete shape;
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
	int nchildren;
	switch (obj_type) {
		//TODO : set path names and load the file.
		case ASTEROID : {
			objpath += ASTEROID_FNAME + OBJ_EXTENSION;
			phypath += ASTEROID_FNAME + PHY_EXTENSION;
			break;
		} case HEALTH : {
			objpath += HEALTH_FNAME + OBJ_EXTENSION;
			phypath += HEALTH_FNAME + PHY_EXTENSION;
			break;
		} case TIE : {
			objpath += AMMO_FNAME + OBJ_EXTENSION;
			phypath += AMMO_FNAME + PHY_EXTENSION;
			break;
		} case XWING : {
			objpath += XWING + OBJ_EXTENSION;
			phypath += XWING + PHY_EXTENSION;
			break;
		} case MF : {
			objpath += MF + OBJ_EXTENSION;
			phypath += MF + PHY_EXTENSION;
			break;
		} case UFO : {
			objpath += UFO + OBJ_EXTENSION;
			phypath += UFO + PHY_EXTENSION;
			break;
		} default : {
			std::cout << " Unknown object type. Please ensure that OBJ_Type=" << obj_type << " is defined appropriately. \n";
			return;
		}
	}
}

void SpaceObject::render_init() {
	return;//TODO
}

void loadRenderGeometry() {
	return;//TODO
}

void loadPhysicsGeometry() {
	return;//TODO
}
#endif