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
	glPushMatrix();
		glMultMatrix(mat_gl);
		//TODO for each cuboid, render the shape.
		for(int i=0; i<children.size(); ++i) {
			float mat_child[16];
			childrenTransform[i].getOpenGLMatrix(mat_child);
			glPushMatrix();
			glMultMatrix(mat_child);
				btvector3 = children->getHalfExtentsWithMargin();
				drawBox(btVector3& hdim);
			glPopMatrix();
		}
	glPopMatrix();
}

//not properly rendered.
void SpaceObject::drawBox(btVector3& dim) {
	btScalar x,y,z;
	x = dim.getX();
	y = dim.getY();
	z = dim.getZ();
	glBegin(GL_LINE);
		glVertex3f(x,y,z);
		glVertex3f(-x,y,z);
	glEnd();
	glBegin(GL_LINE);
		glVertex3f(x,y,z);
		glVertex3f(x,-y,z);
	glEnd();
	glBegin(GL_LINE);
		glVertex3f(x,y,z);
		glVertex3f(x,y,-z);
	glEnd();
	glBegin(GL_LINE);
		glVertex3f(-x,-y,-z);
		glVertex3f(-x,-y,z);
	glEnd();
	glBegin(GL_LINE);
		glVertex3f(-x,-y,-z);
		glVertex3f(-x,y,-z);
	glEnd();
	glBegin(GL_LINE);
		glVertex3f(-x,-y,-z);
		glVertex3f(x,-y,-z);
	glEnd();
	glBegin(GL_LINE);
		glVertex3f(-x,-y,z);
		glVertex3f(-x,y,z);
	glEnd();
	glBegin(GL_LINE);
		glVertex3f(-x,-y,z);
		glVertex3f(x,-y,z);
	glEnd();
	glBegin(GL_LINE);
		glVertex3f(-x,-y,z);
		glVertex3f(x,y,-z);
	glEnd();
	glBegin(GL_LINE);
		glVertex3f(x,y,z);
		glVertex3f(x,y,z);
	glEnd();
	glBegin(GL_LINE);
		glVertex3f(x,y,z);
		glVertex3f(x,y,z);
	glEnd();
	glBegin(GL_LINE);
		glVertex3f(x,y,z);
		glVertex3f(x,y,z);
	glEnd();
}
#endif