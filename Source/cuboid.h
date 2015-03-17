#ifndef CUBOID_H
#define CUBOID_H value

#include <iostream>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>


/** Defines the base class for cuboids.
	@author : B,H
	
	glm was used, luckily its a header only library.

	Ideally, for computations, one would use arbitray precision. But screw that, doubles, we love you.
*/


/** All the jugaad. */
typedef Length double;
typedef Orientation double;

typedef Position glm::vec3;
typedef Velocity glm::vec3;
typedef Acceleration glm::vec3;
/** A class for line segments */
class LineSeg {
public:
	Position start,end;
	Length length;
};
/** A class for infinite rays. */
class Ray { 
public:
	Position start , direction;
};
/** A class for complete lines. Should be absolutely useless. */
class Line {
public:
	Position start, direction; //Extends in both directions. 
};

class Cuboid { //acts a sthe bounding box for everything.
public: //Public was used for easy modification of cuboids.
	Position centre;
	Length l_x,l_y,l_z;
	Orientation o_x,o_y,o_z;

	Cuboid() {} //Default constructor does nothing.
	~Cuboid() {}
	//Need a bunch of set/gets.
	/** Movement functions */
	glm::vec3 translate(glm::vec3 displacement); //Returns the new position of the centre.
	glm::vec3 rotate(glm::vec3 rotation); 		 //Should it return the rotation matrix?
	glm::vec3 scale(glm::vec3 vec_scale); 		 //Scale along each directions.
	/** Queries to the cuboid .*/
	bool intersects(LineSeg& l);
	bool intersects(Ray& r);
	bool intersects(Line& l);
	bool intersects(Cuboid& cub);

	/** Debugging functions -- The boolean is for toggle debug mode. */
	void dprint(bool debug_cuboid=false); //the d stands for Debug.
	void drender(bool debug_cuboid=false);
};

#endif