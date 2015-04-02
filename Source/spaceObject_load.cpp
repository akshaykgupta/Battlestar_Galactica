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
	delete dms;
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
	world = _world;
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
			objpath += XWING_FNAME + OBJ_EXTENSION;
			phypath += XWING_FNAME + PHY_EXTENSION;
			break;
		} case MF : {
			objpath += MF_FNAME + OBJ_EXTENSION;
			phypath += MF_FNAME + PHY_EXTENSION;
			break;
		} case UFO : {
			objpath += UFO_FNAME + OBJ_EXTENSION;
			phypath += UFO_FNAME + PHY_EXTENSION;
			break;
		} default : {
			std::cout << " Unknown object type. Please ensure that OBJ_Type=" << obj_type << " is defined appropriately. \n";
			return;
		}
	}
	physics_init();
	render_init();
	return;
}

void SpaceObject::physics_init() {
	//read the file format.
	readPhysicsFile(); //reads into children and childTransform
	//create the objects.
	createCompoundShape();
	return;
}


void SpaceObject::createCompoundShape() {
	//Child transforms are all in the vectors.
	for(int i=0; i< children.size(); ++i) {
		shape->addChildShape(childrenTransform[i] , children[i]);
	}
	//my shape is now ready.
	dms = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
	shape->calculateLocalInertia(mass, moment_inertia);
	
	btRigidBody::btRigidBodyConstructionInfo bodyCI(mass, dms, (btCollisionShape*)shape , moment_inertia );
    body = new btRigidBody(fallRigidBodyCI);
    
    world->dynamicsWorld->addRigidBody(body);
}
void SpaceObject::render_init() {
	return;//TODO
}

void SpaceObject::loadRenderGeometry() {
	return;//TODO
}

void SpaceObject::loadPhysicsGeometry() {
	return;//TODO
}
#endif