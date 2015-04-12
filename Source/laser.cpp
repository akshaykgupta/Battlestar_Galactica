#ifndef LASER_CPP
#define LASER_CPP
using namespace std;

#include "player.hpp"
#include "spaceObject.hpp"
/* it renders a laser on the screen. It is shot from the Location to the front. */
void Player::fire_laser() {
	fighter->fire_laser();
}

void SpaceObject::fire_laser() {
	btTransform trans;
	body->getMotionState()->getWorldTransform(trans);
	btVector3 from = trans.getOrigin();
	std::cout << body->getOrientation().getX() << "," << body->getOrientation().getY() << "," << body->getOrientation().getZ() << "," << body->getOrientation().getW() << "\n";
	btVector3 to = from + quatRotate(trans.getRotation() , btVector3(0,0,-500));
	
	
	
	//Perform ray test.
	btCollisionWorld::ClosestRayResultCallback rayCallback( from, to );
	world->dynamicsWorld->rayTest(from,to,rayCallback);
	//get results.
	if ( rayCallback.hasHit() ) {
		((SpaceObject*)rayCallback.m_collisionObject->getUserPointer())->hit_by_laser();
		to = ((SpaceObject*)rayCallback.m_collisionObject->getUserPointer())->getRigidBody()->getCenterOfMassPosition();
	} //else, do nothing.
	weapons[activeWeapon] -> fireProjectile(from,to);
}

void SpaceObject::hit_by_laser() {
	std::cout << "i was hit by a laser. ";
}
#endif