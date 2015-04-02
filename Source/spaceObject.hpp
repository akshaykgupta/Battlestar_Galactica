#ifndef SPACE_OBJECT_HPP
#define SPACE_OBJECT_HPP
/* bullets! */
#include <btBulletDynamicsCommon.h>
#include "helpers.hpp"

/**
	What follows are the file paths and so on.
*/

const std::string PHY_RSC_DIR =  "../Resource/Physics/";
const std::string OBJ_RSC_DIR = "../Resource/Render/";
const std::string TIEF_FNAME  = "tiefighter"

class SpaceObject {
public:
	/* constructors */
	SpaceObject(OBJECT_TYPE _type);
	~SpaceObject();
	/** functions for loading, etc. */
	void init(Player* _usr, BulletWorld* _world);
		void physics_init();
		void render_init();


	void loadRenderGeometry(/*objpath*/);
	void loadPhysicsGeometry(/*phypath*/);
		//void render_geometry(); declared in the rendering section.

	/* for debugging, if done. */
	void print(bool debug_flag = false);
	
	/* for rendering into opengl around the centre itself. */
	void render(bool debuf_flag = false);
		void render_geometry();
			void finalizeVBO();
			void bindVBO();
		void render_physics(bool dflag = false);

	void tick(double dt);


private:
	/* misc data */
	OBJECT_TYPE obj_type;
	std::string objpath;
	std::string phypath;

	/*user pointer types*/
	Player* usr;
	
	/*physics*/
	btCompoundShape* mesh;
	btRigidBody* body;
	BulletWorld* world;
	/*render*/

};

#endif