#ifndef SPACE_OBJECT_EVENT_CPP
#define SPACE_OBJECT_EVENT_CPP
#include "spaceObject.hpp"

//TODO: Add a few functions to the spaceObject.hpp
void SpaceObject::initCommunications(State* state, Message* msg) {
	state = new State(); //default constructor.
	msg = new Message(); //default message.
}

void SpaceObject::makeMessage(State* state,  Message* msg) {
	btTransform myTransform;
	body->getMotionState()->getWorldTransform(myTransform);
	btVector3 lv = body->getLinearVelocity();
	btVector3 av = body->getAngularVelocity();
	state->setData( health, weapons[activeWeapon]->ammo , myTransform , lv ,  av , obj_type);

	msg->setData(
		GENDATA , 
		state ,
		weapons[activeWeapon]
		);
}

void SpaceObject::handleCollision(SpaceObject* other) {
	wasHit = true;
	health -= 10; //TODO : Make it proper, correct for each spaceship.
	return;
}

void SpaceObject::toggle_weapon() {
	activeWeapon = (activeWeapon+1)%(weapons.size());
}

void SpaceObject::rotate(double pitch, double yaw) {
	btVector3 localXAxis  = quatRotate(body->getOrientation(),btVector3(1,0,0));
	localXAxis*=mouseScalePitch*pitch;
	body->applyTorque(localXAxis);

	btVector3 localYAxis  = quatRotate(body->getOrientation(),btVector3(0,1,0));
	localYAxis*=mouseScaleYaw*yaw;
	body->applyTorque(localYAxis);
	return;
}

//--------LIMIT ALL TO MAX VELOCITY----------//

//KEYBOARD FUNCTIONS AHEAD!
void SpaceObject::accelerate() {
	btVector3 localZAxis  = quatRotate(body->getOrientation(),btVector3(0,0,-1));
	localZAxis*=scalingAcceleration;
	cout<<localZAxis.getX()<<" "<<localZAxis.getY()<<" "<<localZAxis.getZ()<<"\n";
	body->applyCentralImpulse(localZAxis);
}
void SpaceObject::decelerate() {
	btVector3 localZAxis  = quatRotate(body->getOrientation(),btVector3(0,0,1));
	localZAxis*=scalingAcceleration;
	body->applyCentralImpulse(localZAxis);
}
void SpaceObject::strafe_left() {
	btVector3 localXAxis  = quatRotate(body->getOrientation(),btVector3(-1,0,0));
	localXAxis*=scalingAcceleration;
	body->applyCentralImpulse(localXAxis);
}
void SpaceObject::strafe_right() {
	btVector3 localXAxis  = quatRotate(body->getOrientation(),btVector3(1,0,0));
	localXAxis*=scalingAcceleration;
	body->applyCentralImpulse(localXAxis);
}
void SpaceObject::ascend() {
	btVector3 localYAxis  = quatRotate(body->getOrientation(),btVector3(0,1,0));
	localYAxis*=scalingAcceleration;
	body->applyCentralImpulse(localYAxis);
}
void SpaceObject::descend() {
	btVector3 localYAxis  = quatRotate(body->getOrientation(),btVector3(0,-1,0));
	localYAxis*=scalingAcceleration;
	body->applyCentralImpulse(localYAxis);
}


void SpaceObject::pitch_up() {
	btVector3 localXAxis  = quatRotate(body->getOrientation(),btVector3(1,0,0));
	localXAxis*=scalingOmega;
	body->applyTorque(localXAxis);

}
void SpaceObject::pitch_down() {
	btVector3 localXAxis  = quatRotate(body->getOrientation(),btVector3(-1,0,0));
	localXAxis*=scalingOmega;
	body->applyTorque(localXAxis);
}
void SpaceObject::yaw_left() {
	btVector3 localYAxis  = quatRotate(body->getOrientation(),btVector3(0,1,0));
	localYAxis*=scalingOmega;
	body->applyTorque(localYAxis);
}
void SpaceObject::yaw_right() {
	btVector3 localYAxis  = quatRotate(body->getOrientation(),btVector3(0,-1,0));
	localYAxis*=scalingOmega;
	body->applyTorque(localYAxis);
}
void SpaceObject::roll_left() {
	btVector3 localZAxis  = quatRotate(body->getOrientation(),btVector3(0,0,1));
	localZAxis*=scalingOmega;
	body->applyTorque(localZAxis);
}
void SpaceObject::roll_right() {
	btVector3 localZAxis  = quatRotate(body->getOrientation(),btVector3(0,0,-1));
	localZAxis*=scalingOmega;
	body->applyTorque(localZAxis);
}


#endif