#ifndef CUBOID_CPP
#define CUBOID_CPP
/* Implementation of cuboid - TODO: Intersection algorithms etc.
	Note : I use cube and cuboid interchangibly.
	State of affairs : We can quickly check if axis aligned cube and a line intersect.
					And to check if two cubes intersect, we can just check if ANY point of one cube is inside the other.
*/

bool Cuboid::inside(Position& _p) {
	//Need to check if a point p is inside the cuboid or not.
	/*
	
	*/
	Position pwrtc = _p - centre; //Relative position of the point from the centre. in Oriented world.	
}
#endif