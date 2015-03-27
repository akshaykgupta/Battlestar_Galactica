#ifndef CUBOID_H
#define CUBOID_H

/** Defines the base class for cuboids.
	@author : B,H
	
	glm was used, luckily its a header only library.
	Ideally, for computations, one would use arbitray precision. But screw that, doubles, we love you.
	
	Possible Uses: 
		For mouse clicks, use Ray/Line.
		For lasers, use LineSeg.
		For cuboids, well...

	Collision testing:
		point-cuboid, check if inside etc.
		line-cuboid, 
		cuboid-cuboid : Seperating Axis Theorem.
*/

#include <iostream>
#include <cmath>
#include <vector>

/* TODO: Include a bunch of glm things, for transformation matrices. */
/* go hand in hand. */
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp> //Quaternions!
/** All the jugaad. */

using namespace std;

#include "helpers.h"

class Cuboid { //acts a sthe bounding box for everything.
public: //Public was used for easy modification of cuboids.
	Cuboid() {} //Default constructor does nothing.
	~Cuboid() {}
	//Need a bunch of set/gets.
	/** Movement functions */
	glm::vec4 translate(glm::vec4 displacement); //Returns the new position of the centre.
	Quat rotate(glm::vec3 rotation); 		 //Should it return the rotation matrix?
	Quat rotate(Quat q);
	//glm::vec4 scale(glm::vec4 vec_scale); 		 //Scale along each directions. --unimplemented.
	/** Queries to the cuboid .*/
	bool inside(Position p);
	bool outside(Position p);
	bool onsurface(Position p);
	
	bool intersects(LineSeg& l);
	bool intersects(Ray& r);
	bool intersects(Line& l);
	bool intersects(Cuboid& cub);
	
	/** Solving collision related stuff. It should probably also check if a collision DOES occur. */
	std::pair<Position,Direction> solveCollision(LineSeg& l);
	std::pair<Position,Direction> solveCollision(Ray& r);
	std::pair<Position,Direction> solveCollision(Line& l);
	std::pair<Position,Direction> solveCollision(Cuboid& cub);

	/** Debugging functions -- The boolean is for toggle debug mode. */
	void dprint(bool debug_cuboid=false); //the d stands for Debug.
	void drender(bool debug_cuboid=false);
	
	/** Getters and setters. */
	Position getCentre();
	Dimension getDimension();
	Quat getQuatRotation();

	void setCentre(Position _p);
	void setDimension(Dimension _d);
	void setRotation(glm::vec3 eulerAngles);
	void setRotation(Quat _q);
	Position getMinPoint();
	Position getMaxPoint();


private:
	Position centre;
	Dimension dimensions;
	Quat quatRot;
	glm::mat4 matRotation, matTranslation;

	float outerBoundingRadius, innerBoundingRadius; //Use this to speed up bounding etc.
	/** Auxillary functions. */
	bool get_intersection_on_plane(double dist1, double dist2 , Position ls , Position le , Position& hitp);	
	bool in_aabb(Position p, AXIS ax);
};

#endif