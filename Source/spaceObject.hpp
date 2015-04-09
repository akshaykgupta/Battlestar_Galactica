#ifndef SPACE_OBJECT_HPP
#define SPACE_OBJECT_HPP
/* bullets! */
#include <btBulletDynamicsCommon.h>
#include "helpers.hpp"

/**
	What follows are the file paths and so on.
*/

class SpaceObject {
public:
	/* constructors */
	SpaceObject(OBJECT_TYPE _type);
	~SpaceObject();
	/** functions for loading, etc. */
	void 	init(BulletWorld* _world);
	void 	physics_init();
	void 	readPhysicsFile();
	void 	createCompoundShape();
	void 	render_init();

	void 	loadRenderGeometry(/*objpath*/);
	void 	loadPhysicsGeometry(/*phypath*/);
		//void render_geometry(); declared in the rendering section.

	/* for debugging, if done. */
	void 	print(bool debug_flag = false);
	
	/* for rendering into opengl around the centre itself. */
	void 	render(bool debuf_flag = false);
	void 	render_geometry();
	void 	render_physics(bool dflag = false);
	void 	handleCollision(SpaceObject* other);

	OBJECT_TYPE getType();
	void 	setType(OBJECT_TYPE _type);

	void 	setVelocity(const btVector3&);
	void 	getVelocity(btVector3&);
	void 	setAcceleration(const btVector3&);
	void 	getAcceleration(btVector3&);
	void 	setRotation(const btVector3&);
	void 	getRotation(btVector3&);
	void 	setAngularVelocity(const btVector3&);
	void 	getAngularVelocity(btVector3&);
	int 	getHealth();
	void 	setHealth(int h);
	void 	getTrans(float* mat);
	Weapon* 	getActiveWeapon();
	void 	setActiveWeapon(int w);

	btRigidBody* getRigidBody();
	void 	drawBox(btVector3&);

	//functions to get the state and stuff.
	void 	initCommunications(State* state , Message* msg);
	void 	makeMessage(Message* msg); //generates default message, with health etc.
	

	/* actions that the spaceobject can do .*/
	void fire_laser();
	void hit_by_laser();
private:
	/* misc data */
	OBJECT_TYPE obj_type;
	std::string objpath;
	std::string phypath;
	int health;
	bool wasHit;
	btScalar maxVelocity;
	btScalar scalingAcceleration;
	std::vector<Weapon*> weapons;
	int activeWeapon;
	/*physics*/
	btScalar mass;
	std::vector<btTransform> childTransform;
	std::vector<btCollisionShape*> children;
	btCompoundShape* shape;
	btDefaultMotionState* dms; //default motion state.
	btVector3 moment_inertia;
	btRigidBody* body;
	BulletWorld* world;
	/*render*/

};

#endif