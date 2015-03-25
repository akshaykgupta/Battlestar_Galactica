#ifndef CUBOID_CPP
#define CUBOID_CPP
/* Implementation of cuboid - TODO: Intersection algorithms etc.
	Note : I use cube and cuboid interchangibly.
	State of affairs : We can quickly check if axis aligned cube and a line intersect.
					And to check if two cubes intersect, we can just check if ANY point of one cube is inside the other.
*/
/** Movement functions */
glm::vec4 Cuboid::translate(glm::vec4 displacement) {
	centre = centre+displacement;
	//Do i want to update my translation matrix?
	return centre;
}

Quat Cuboid::rotate(glm::vec3 eulerangles) { //rotate by euler angles. in degrees.
	Quat q((glm::radians(eulerangles)));
	quatRot = q*quatRot;
	return quatRot;
}

Quat Cuboid::rotate(Quat q) { //rotate by quaternion.
	quatRot = q*quatRot;
	return quatRot;
}



/** Query functions. */
bool Cuboid::inside(Position _p) {
	Position pwrtc = quatRot*(_p-centre);
	glm::vec4 xaxis(1.0,0.0,0.0,0.0);
	glm::vec4 yaxis(0.0,1.0,0.0,0.0);
	glm::vec4 zaxis(0.0,0.0,1.0,0.0);
	float absdotx = abs(glm::dot(pwrtc,xaxis));
	float absdoty = abs(glm::dot(pwrtc,yaxis));
	float absdotz = abs(glm::dot(pwrtc,zaxis));
	return ((absdotz<0.5*dimensions.x)&&(absdoty<0.5*dimensions.y)&&(absdotz<0.5*dimensions.z));
} //needs testing and optimizaton.

bool Cuboid::outside(Position _p) {
	Position pwrtc = quatRot*(_p-centre);
	glm::vec4 xaxis(1.0,0.0,0.0,0.0);
	glm::vec4 yaxis(0.0,1.0,0.0,0.0);
	glm::vec4 zaxis(0.0,0.0,1.0,0.0);
	float absdotx = abs(glm::dot(pwrtc,xaxis));
	float absdoty = abs(glm::dot(pwrtc,yaxis));
	float absdotz = abs(glm::dot(pwrtc,zaxis));
	return ((absdotz>0.5*dimensions.x)||(absdoty>0.5*dimensions.y)||(absdotz>0.5*dimensions.z));
} //needs testing and optimization

bool Cuboid::onsurface(Position _p) {
	Position pwrtc = quatRot*(_p-centre);
	glm::vec4 xaxis(1.0,0.0,0.0,0.0);
	glm::vec4 yaxis(0.0,1.0,0.0,0.0);
	glm::vec4 zaxis(0.0,0.0,1.0,0.0);
	float absdotx = abs(glm::dot(pwrtc,xaxis));
	float absdoty = abs(glm::dot(pwrtc,yaxis));
	float absdotz = abs(glm::dot(pwrtc,zaxis));
	return ((absdotz==0.5*dimensions.x)&&(absdoty<0.5*dimensions.y)&&(absdotz<0.5*dimensions.z))
	 || ((absdotz<0.5*dimensions.x)&&(absdoty==0.5*dimensions.y)&&(absdotz<0.5*dimensions.z))
	 || ((absdotz<0.5*dimensions.x)&&(absdoty<0.5*dimensions.y)&&(absdotz==0.5*dimensions.z));
} //needs testing and optimization.

/** */
bool Cuboid::intersects(LineSeg& l) {
	return false;
}
bool Cuboid::intersects(Ray& r) {
	return false;
}
bool Cuboid::intersects(Line& l) {
	return false;
}
bool Cuboid::intersects(Cuboid& cub) {
	return false;
}

/** physics stuff */
std::pair<Position,Direction> Cuboid::solveCollision(LineSeg& l) {
	Position p;
	Direction d;
	return std::make_pair(p,d);
}
std::pair<Position,Direction> Cuboid::solveCollision(Ray& r) {
	Position p;
	Direction d;
	return std::make_pair(p,d);
}
std::pair<Position,Direction> Cuboid::solveCollision(Line& l) {
	Position p;
	Direction d;
	return std::make_pair(p,d);
}
std::pair<Position,Direction> Cuboid::solveCollision(Cuboid& cub) {
	Position p;
	Dimension d;
	return std::make_pair(p,d);
}

/** debugging stuff. */
void Cuboid::dprint(bool debug_cuboid) { //the d stands for Debug.
	
}
void Cuboid::drender(bool debug_cuboid) {
//TODO:
}

Position Cuboid::getCentre() {
	return centre;
}
Dimension Cuboid::getDimension() {
	return dimensions;
}
Quat Cuboid::getQuatRotation() {
	return quatRot;
}

void Cuboid::setCentre(Position _p) {
	centre = _p;
}
void Cuboid::setDimension(Dimension _d) {
	dimensions = _d;
}	
void Cuboid::setRotation(glm::vec3 eulerAngles) {
	Quat nq(glm::radians(eulerAngles));
	quatRot = nq;
}
void Cuboid::setRotation(Quat _q) {
	quatRot = _q;
}

#endif