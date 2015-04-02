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
	void init(Player* _usr, BulletWorld* _world);
		void physics_init();
			void readPhysicsFile();
			void createCompoundShape();
		void render_init();

	void loadRenderGeometry(/*objpath*/);
	void loadPhysicsGeometry(/*phypath*/);
		//void render_geometry(); declared in the rendering section.

	/* for debugging, if done. */
	void print(bool debug_flag = false);
	
	/* for rendering into opengl around the centre itself. */
	void render(bool debuf_flag = false);
		void render_geometry();
			// void finalizeVBO();
			// void bindVBO();
		void render_physics(bool dflag = false);

	
	void setVelocity(btVector3);
	void getVelocity(btVector3&);
	void setAcceleration(btVector3);
	void getAcceleration(btVector3&);
	void setRotation(btVector3);
	void getRotation(btVector3&);
	void setRotation(btVector3);
	void getRotation(btVector3&);

	void tick(double dt);
	void drawBox(btVector3&);
private:
	/* misc data */
	OBJECT_TYPE obj_type;
	std::string objpath;
	std::string phypath;

	/*user pointer types*/
	Player* usr;
	
	
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