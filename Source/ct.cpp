#include "spaceObject.hpp"
#include "spaceObject_load.cpp"
#include "spaceObject_event.cpp"
#include "spaceObject_render.cpp"

using namespace std;

int main(int argc, char** argv) {
	SpaceObject* ufo;
	ufo = new SpaceObject(UFO);
	// Cuboid cub;
	// Position p;
	// Position _p =glm::vec4(2.0,2.0,2.0,1.0);
	// cub.setCentre(_p);
	// Dimension _d = glm::vec4(1.0,1.0,1.0,0.0);
	// cub.setDimension(_d);
	// glm::vec3 e_angle(90,0,0);
	// Quat aboutx(glm::radians(e_angle));
	// cub.rotate(aboutx);
	
	// p = glm::vec4(1.7,1.7,1.7,1.0);
	// Position p2 = glm::vec4(1.7,1.7,1.3,1.0);
	// cout << cub.inside(p) << "\n";
	// cout << cub.outside(p2);
	// return 0;
	cout << "creation successful \n";
	delete ufo;
	return 0;
}