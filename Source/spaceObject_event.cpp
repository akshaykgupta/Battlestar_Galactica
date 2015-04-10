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
	btQuaternion localRotation(yaw*(3.14159/180),pitch*(3.14159/180),0.0);
	btTransform trans(body->getCenterOfMassTransform());
	trans.setRotation( localRotation*(body->getCenterOfMassTransform().getRotation() ));
	body->setCenterOfMassTransform(trans);
	return;

	/*
	btVector3 localXAxis = quatRotate(body->getOrientation(),btVector3(1,0,0));
	btVector3 localYAxis = quatRotate(body->getOrientation(),btVector3(0,1,0));
	btQuaternion qy = btQuaternion( localXAxis , yaw);
	btQuaternion qp = btQuaternion( localYAxis , pitch);
	btQuaternion apply = qp*qy;
	body->rotate(apply);*/

}


//KEYBOARD FUNCTIONS AHEAD!
void SpaceObject::accelerate() {
	//--------LIMIT ALL TO MAX VELOCITY----------//
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
	//-------TODO------------Scale It Down---------------------------//
	btVector3 localYAxis  = quatRotate(body->getOrientation(),btVector3(0,1,0));
	localYAxis*=scalingAcceleration;
	body->applyCentralImpulse(localYAxis);
}
void SpaceObject::descend() {
	//------TODO-------------Scale It Down---------------------------//
	btVector3 localYAxis  = quatRotate(body->getOrientation(),btVector3(0,-1,0));
	localYAxis*=scalingAcceleration;
	body->applyCentralImpulse(localYAxis);
}
void SpaceObject::pitch_up() {
	//TODO
	btVector3 localXAxis  = quatRotate(body->getOrientation(),btVector3(1,0,0));
	localXAxis*=scalingOmega;
	body->applyTorque(localXAxis);

}
void SpaceObject::pitch_down() {
	//TODO
	btVector3 localXAxis  = quatRotate(body->getOrientation(),btVector3(-1,0,0));
	localXAxis*=scalingOmega;
	body->applyTorque(localXAxis);
}
void SpaceObject::yaw_left() {
	//TODO
	btVector3 localYAxis  = quatRotate(body->getOrientation(),btVector3(0,1,0));
	localYAxis*=scalingOmega;
	body->applyTorque(localYAxis);
}
void SpaceObject::yaw_right() {
	//TODO
	btVector3 localYAxis  = quatRotate(body->getOrientation(),btVector3(0,-1,0));
	localYAxis*=scalingOmega;
	body->applyTorque(localYAxis);
}
void SpaceObject::roll_left() {
	//TODO
	btVector3 localZAxis  = quatRotate(body->getOrientation(),btVector3(0,0,1));
	localZAxis*=scalingOmega;
	body->applyTorque(localZAxis);
}
void SpaceObject::roll_right() {
	//TODO
	btVector3 localZAxis  = quatRotate(body->getOrientation(),btVector3(0,0,-1));
	localZAxis*=scalingOmega;
	body->applyTorque(localZAxis);
}


#endif