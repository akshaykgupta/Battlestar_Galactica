#ifndef SPACE_OBJECT_RENDER_CPP
#define SPACE_OBJECT_RENDER_CPP

#include "spaceObject.hpp"
/** file with functions for rendering things. */
void SpaceObject::render(bool dflag) {
	if (dflag) {
		// std::cout<<"About to enter render_physics \n";
		render_physics(true);
		// std::cout<<"Exited render physics \n";
	}
	render_geometry();
}

void SpaceObject::render_geometry() {
	return;
}

void SpaceObject::render_physics(bool dflag) {
	if ( !dflag ) { //not in debug mode.
		return; 
	}
    // cout<<"In render physics \n";
	btTransform trans_com;
	body->getMotionState()->getWorldTransform(trans_com);

    //debugging
    // cout << trans_com.getOrigin().getZ() << "\n";
	
    float mat_gl[16];
	trans_com.getOpenGLMatrix(mat_gl);

	glPushMatrix();
		glMultMatrixf(mat_gl);
		//TODO for each cuboid, render the shape.
		for(int i=0; i<children.size(); ++i) {
			// cout<<"Calculating for child\n";
			float mat_child[16];
			childTransform[i].getOpenGLMatrix(mat_child);
			glPushMatrix();
			glMultMatrixf(mat_child);
				btVector3 hdim = ((btBoxShape*)children[i])->getHalfExtentsWithMargin();
				drawBox(hdim);
			// for (int i=0;i<16;i++)
				// cout<<mat_gl[i]<<" ";
			// cout<<"\n";
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
	 // cout<<x<<" "<<y<<" "<<z<<"\n";
    glLineWidth(1.0);
	//Back face
        glBegin(GL_LINE_LOOP);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, y, -z);
        glVertex3f(x, y, -z);
        glVertex3f(x, -y, -z);
        glEnd();
        
        //Front face
        glBegin(GL_LINE_LOOP);
        glVertex3f(-x, -y, z);
        glVertex3f(-x, y, z);
        glVertex3f(x, y, z);
        glVertex3f(x, -y, z);
        glVertex3f(-x, -y, z);
        glEnd();
        
        
        
        //Left face
        glBegin(GL_LINE_LOOP);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, -y, z);
        glVertex3f(-x, y, z);
        glVertex3f(-x, y, -z);
        glEnd();
        
        //Right face
        glBegin(GL_LINE_LOOP);
        glVertex3f(x, -y, -z);
        glVertex3f(x, -y, z);
        glVertex3f(x, y, z);
        glVertex3f(x, y, -z);
        glEnd();
        
        
        
        //Top face
        glBegin(GL_LINE_LOOP);
        glVertex3f(-x, y, -z);
        glVertex3f(x, y, -z);
        glVertex3f(x, y, z);
        glVertex3f(-x, y, z);
        glEnd();
        
        //Bottom face
        glBegin(GL_LINE_LOOP);
        glVertex3f(-x, -y, -z);
        glVertex3f(x, -y, -z);
        glVertex3f(x, -y, z);
        glVertex3f(-x, -y, z);
        glEnd();
}
#endif