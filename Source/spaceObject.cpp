#ifndef SPACE_OBJECT_CPP
#define SPACE_OBJECT_CPP

#include <iostream>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>

#include "cuboid.h"

/** Some more jugaad. */
typedef std::vector<Cuboid>::iterator iter;

/** This is the mother of all things BattlestarGalactica. All ships, asteroids etc derive from this. */
class SpaceObject {
public:
	/** Each space object is a collection of Cuboids. Ideally, the Collection would be a vector<Cuboid> */	
	std::vector<Cuboid> pieces; //Do we need a better datastructure? 
	
	/*
	//DECISION NEEDED! Should these be here?

	Position com; //Centre of Mass.
	Velocity v;
	Acceleration a;
	*/
	
	/** Queries. */

	/** Updates */


	/** Debugging tools. */
	void dprint(bool debug_spaceobj=false);
	void drender(bool debug_spaceobj=false);
};

#endif