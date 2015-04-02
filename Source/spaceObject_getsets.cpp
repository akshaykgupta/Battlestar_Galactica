#ifndef SPACE_OBJECT_GET_SETS_CPP
#define SPACE_OBJECT_GET_SETS_CPP

#include "spaceObject.hpp"

//TODO
void SpaceObject::setVelocity(const btVector3& _vec) {
	//TODO : Check for max velocity maybe.
	body->setLinearVelocity(_vec);
	return;
}
void SpaceObject::getVelocity(btVector3& _vec) {

	return;
}
void SpaceObject::setAcceleration(const btVector3& _vec) {

	return;
}
void SpaceObject::getAcceleration(btVector3& _vec) {

	return;
}
void SpaceObject::setRotation(const btVector3& _vec) {

	return;
}
void SpaceObject::getRotation(btVector3& _vec) {

	return;
}
void SpaceObject::setAngularVelocity(const btVector3& _vec) {

	return;
}
void SpaceObject::getAngularVelocity(btVector3& _vec) {

	return;
}

btRigidBody* SpaceObject::getRigidBody() {
	return body;
}

#endif