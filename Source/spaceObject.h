#ifndef SPACE_OBJECT_CPP
#define SPACE_OBJECT_CPP

#include <iostream>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>

#include "cuboid.h"

/** Some more jugaad. */
typedef std::vector<Cuboid>::iterator iter;
typedef std::string OBJFilepath;
typedef double Mass;
/** This is the mother of all things. All ships, asteroids etc derive from this. */

class SpaceObject {
public:
	/** Each space object is a collection of Cuboids. Ideally, the Collection would be a vector<Cuboid> */	

	/** Creation/Loading */
	SpaceObject() {}
	~SpaceObject() {}

	/** get/sets */
	Position getPosition();
	Orientation getOrientation();
	Velocity getVelocity();
	Acceleration getAcceleration();
	void setPosition(Position& p);
	void setOrientaiton(Orientation& _o);
	void setVelocity(Velocity& _v);
	void setAcceleration(Acceleration& _acc);

	/** rendering things. */
	void loadOBJ();
	void renderOBJ();

	/** Queries. */
	bool inside(Position& p);
	bool outside(Position& p);
	bool onsurface(Position& p);
	bool intersects(LineSeg& l);
	bool intersects(Ray& r);
	bool intersects(Line& l);
	bool intersects(Cuboid& cub);
	
	bool intersects(SpaceObject& spaceobj);
	/***/
	
	/** Updates */
	glm::vec3 translate(glm::vec3 displacement); //Returns the new position of the centre.
	glm::vec3 rotate(glm::vec3 rotation); 		 //Should it return the rotation matrix?
	glm::vec3 scale(glm::vec3 vec_scale); 		 //Scale along each directions.
	
	/** Debugging tools. */
	void dprint(bool debug_spaceobj=false);
	void drender(bool debug_spaceobj=false);
private:
	////
	std::vector<Cuboid> pieces; //Do we need a better data-structure? If we were using more complicated shapes, we'd use a AABBTree. 
	OBJFilepath objfile; /* Different space ships */
	
	/** Physics and rendering stuff. */
	Mass mass;
	Position com;
	Orientation o;
	Velocity v;
	Acceleration a;
};

#endif