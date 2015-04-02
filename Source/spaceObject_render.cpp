#ifndef SPACE_OBJECT_RENDER_CPP
#define SPACE_OBJECT_RENDER_CPP

#include "spaceObject.hpp"
/** file with functions for rendering things. */
void SpaceObject::render_physics(bool dflag) {
	if ( !dflag ) { //not in debug mode.
		return; 
	}
	btTransform trans_com;
	body->getMotionState()->getWorldTransform(trans_com);
	float mat_gl[16];
	trans_com.getOpenGLMatrix(mat_gl);
	glPushMatrix(mat_gl);
		glMultMatrix(mat_gl);
		//TODO for each cuboid, render the shape.
	glPopMatrix();
}
#endif