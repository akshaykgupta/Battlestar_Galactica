#ifndef SPACE_OBJECT_HPP
#define SPACE_OBJECT_HPP
/* bullets! */
#include <btBulletDynamicsCommon.h>
#include "helpers.hpp"

class SpaceObject {
public:
	/* constructors */
	SpaceObject();
	~SpaceObject();
	/** functions for loading, etc. */
	void init();
		void physics_init();
		void render_init();

	void loadRenderGeometry(std::string _path);
		//void render_geometry(); declared in the rendering section.

	/* for debugging, if done. */
	void print(bool debug_flag = false);
	
	/* for rendering into opengl around the centre itself. */
	void render(bool debuf_flag = false);
		void render_geometry();
			void finalizeVBO();
			void bindVBO();
		void mesh_render(bool dflag = false);


private:
	/* misc data */
	OBJECT_TYPE obj_type;
	OBJPath objpath;
	PHYPath phypath;

	/*user pointer types*/

	/*physics*/
	btCompoundShape* mesh;
	btRigidBody* body;
	/*render*/

};

#endif