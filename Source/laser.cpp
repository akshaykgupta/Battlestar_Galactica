#ifndef LASER_CPP
#define LASER_CPP

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
	
	cout << "LASER DATA:" << "\n\tFrom=" << from.getX() << "," << from.getY() << "," << from.getZ();
	cout << "\n\tTo=" << to.getX() << "," << to.getY() << "," << to.getZ() << "\n";
	weapons[activeWeapon] -> fireProjectile(from,to);
	
	//Perform ray test.
	btCollisionWorld::ClosestRayResultCallback rayCallback( from, to );
	world->dynamicsWorld->rayTest(from,to,rayCallback);
	//get results.
	if ( rayCallback.hasHit() ) {
		((SpaceObject*)rayCallback.m_collisionObject->getUserPointer())->hit_by_laser();
	} //else, do nothing.
}
void SpaceObject::hit_by_laser() {
	std::cout << "i was hit by a laser. ";
}
#endif