#ifndef CUBOID_H
#define CUBOID_H

#include <iostream>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>


/** Defines the base class for cuboids.
	@author : B,H
	
	glm was used, luckily its a header only library.
	Ideally, for computations, one would use arbitray precision. But screw that, doubles, we love you.
	
	Possible Uses: 
		For mouse clicks, use Ray/Line.
		For lasers, use LineSeg.
		For cuboids, well...
*/
/** All the jugaad. */

using namespace std;

/** Pedagogical. Why? we shall use the fourth dimension correctly. For a point, w=1, for a direction(read: velocity, acc) , w=0. */
typedef  glm::vec4 Dimension; //w=0
typedef  glm::vec4 Orientation; //w=0
typedef  glm::vec4 Position; //w=1
typedef  glm::vec4 Direction; //w=0
typedef  glm::vec4 Velocity; //w=0
typedef  glm::vec4 Acceleration; //w=0

/** A class for line segments */
class LineSeg {
public:
	Position start,end;
	Length length;
	LineSeg();
	~LineSeg();
};
/** A class for infinite rays. */
class Ray { 
public:
	Position start ; 
	Direction direction;
	Ray();
	~Ray();
};
/** A class for complete lines. Should be absolutely useless. */
class Line {
public:
	Position start; //Every line must pass through a point. 
	Direction direction; //Extends in both directions. 
	Line();
	~Line();
};

class Cuboid { //acts a sthe bounding box for everything.
public: //Public was used for easy modification of cuboids.
	Position centre;
	Dimension dimensions;
	Orientation orientation;
	Cuboid() {} //Default constructor does nothing.
	~Cuboid() {}
	//Need a bunch of set/gets.
	/** Movement functions */
	glm::vec3 translate(glm::vec3 displacement); //Returns the new position of the centre.
	glm::vec3 rotate(glm::vec3 rotation); 		 //Should it return the rotation matrix?
	glm::vec3 scale(glm::vec3 vec_scale); 		 //Scale along each directions.
	/** Queries to the cuboid .*/
	bool inside(Position& p);
	bool outside(Position& p);
	bool onsurface(Position& p);
	bool intersects(LineSeg& l);
	bool intersects(Ray& r);
	bool intersects(Line& l);
	bool intersects(Cuboid& cub);
	/** Debugging functions -- The boolean is for toggle debug mode. */
	void dprint(bool debug_cuboid=false); //the d stands for Debug.
	void drender(bool debug_cuboid=false);
};

#endif