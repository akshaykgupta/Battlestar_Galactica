#ifndef CUBOID_CPP
#define CUBOID_CPP
/* Implementation of cuboid - TODO: Intersection algorithms etc.
	Note : I use cube and cuboid interchangibly.
	State of affairs : We can quickly check if axis aligned cube and a line intersect.
					And to check if two cubes intersect, we can just check if ANY point of one cube is inside the other.
*/
/** Movement functions */
#include "cuboid.h"

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
	/*l.start , l.end define the line segment. */
	/*glm::vec4 xaxis(1.0,0.0,0.0,0.0);
	glm::vec4 yaxis(0.0,1.0,0.0,0.0);
	glm::vec4 zaxis(0.0,0.0,1.0,0.0);
	*/
	/* The lstart and lend are with respect to the cuboid now */
	Position lstart = quatRot*(l.start - centre);
	Position lend = quatRot*(l.end - centre);

	//Now, to get the min and max of the box.
	Position bmin = getMinPoint();
	Position bmax = getMaxPoint();
	
	//If the line is on one side of the cube entirely, return false.
	if ( lstart.x < bmin.x && lend.x < bmin.x) { return false; }
	if ( lstart.x > bmax.x && lend.x > bmax.x) { return false; }
	if ( lstart.y < bmin.y && lend.y < bmin.y) { return false; }
	if ( lstart.y > bmax.y && lend.y > bmax.y) { return false; }
	if ( lstart.z < bmin.z && lend.z < bmin.z) { return false; }
	if ( lstart.z > bmax.z && lend.z > bmax.z) { return false; }
	/* trivial cases are done. */
	
	//Case: end points INSIDE the box.
	if ( (lstart.x>bmin.x && lstart.x<bmax.x && lstart.y>bmin.y && lstart.y<bmax.y && lstart.z>bmin.z && lstart.z<bmax.z)
		|| (lend.x>bmin.x && lend.x<bmax.x && lend.y>bmin.y && lend.y<bmax.y && lend.z>bmin.z && lend.z<bmax.z)
		) { return true; }

	//Case : It intersects with a face.
	Position pnt; //This is the point of intersection of lstart-lend with the faces of the cuboid.
	if ( ((get_intersection_on_plane(lstart.x-bmin.x , lend.x-bmin.x,lstart,lend,pnt))&&(in_aabb(pnt,X)))
		|| ((get_intersection_on_plane(lstart.x-bmax.x , lend.x-bmax.x,lstart,lend,pnt))&&(in_aabb(pnt,X)))
		|| ((get_intersection_on_plane(lstart.y-bmin.y , lend.y-bmin.y,lstart,lend,pnt))&&(in_aabb(pnt,Y)))
		|| ((get_intersection_on_plane(lstart.y-bmax.y , lend.y-bmax.y,lstart,lend,pnt))&&(in_aabb(pnt,Y)))
		|| ((get_intersection_on_plane(lstart.z-bmin.z , lend.z-bmin.z,lstart,lend,pnt))&&(in_aabb(pnt,Z)))
		|| ((get_intersection_on_plane(lstart.z-bmax.z , lend.z-bmax.z,lstart,lend,pnt))&&(in_aabb(pnt,Z)))
		) { return true; }
	return false;
}
bool Cuboid::intersects(Ray& r) {
	return false;
}
bool Cuboid::intersects(Line& l) {
	return false;
}
bool Cuboid::intersects(Cuboid& cub) {
	/** Idea: SAT. Seperating Axis Theorem. 
		Refer: http://www.geometrictools.com/Documentation/DynamicCollisionDetection.pdf
	*/
	//There are 15 possible seperating axis. If any of them returns a false, we return a false.
	// 0-> X , 1-> Y , 2-> Z.
	glm::vec4 x_axis(1.0,0.0,0.0,0.0);
	glm::vec4 y_axis(0.0,1.0,0.0,0.0);
	glm::vec4 z_axis(0.0,0.0,1.0,0.0);
	//Axes of the cuboids.
	glm::vec4 D = centre - cub.centre;
	glm::vec4 A0,A1,A2,B0,B1,B2;
	A0 = quatRot*x_axis;
	B0 = cub.quatRot*x_axis;
	A1 = quatRot*y_axis;
	B1 = cub.quatRot*y_axis;
	A2 = quatRot*z_axis;
	B2 = cub.quatRot*z_axis;
	
	std::vector<float> a(3);
	a[0] = dimensions.x;
	a[1] = dimensions.y;
	a[2] = dimensions.z;
	std::vector<float> b(3);
	b[0] = dimensions.x;
	b[1] = dimensions.y;
	b[2] = dimensions.z;

	vector< vector<float> > c(3 , vector<float>(3)); //c[i][j] = glm::dot(Ai , Bj)
	//9 lines of code for initialization.
	c[0][0] = glm::dot(A0,B0);
	c[0][1] = glm::dot(A0,B1);
	c[0][2] = glm::dot(A0,B2);
	c[1][0] = glm::dot(A1,B0);
	c[1][1] = glm::dot(A1,B1);
	c[1][2] = glm::dot(A1,B2);
	c[2][0] = glm::dot(A2,B0);
	c[2][1] = glm::dot(A2,B1);
	c[2][2] = glm::dot(A2,B2);
	//Possible optimization : calculate these things only when required.

	if ( abs(glm::dot(D,A0)) > ( a[0] + b[0]*abs(c[0][0]) + b[1]*abs(c[0][1]) + b[2]*abs(c[0][2])) ) { //A0
		return false;
	} else if ( abs(glm::dot(D,A1)) > ( a[1] + b[0]*abs(c[1][0]) + b[1]*abs(c[1][1]) + b[2]*abs(c[1][2])) ) { //A1
		return false;
	} else if ( abs(glm::dot(D,A2)) > ( a[2] + b[0]*abs(c[2][0]) + b[1]*abs(c[2][1]) + b[2]*abs(c[2][2])) ) { //A2
		return false;
	} else if ( abs(glm::dot(D,B0)) > ( b[0] + a[0]*abs(c[0][0]) + a[1]*abs(c[1][0]) + a[2]*abs(c[2][0])) ) { //B0
		return false;
	} else if ( abs(glm::dot(D,B1)) > ( b[1] + a[0]*abs(c[0][1]) + a[1]*abs(c[1][1]) + a[2]*abs(c[2][1])) ) { //B1
		return false;
	} else if ( abs(glm::dot(D,B2)) > ( b[2] + a[0]*abs(c[0][2]) + a[1]*abs(c[1][2]) + a[2]*abs(c[2][2])) ) { //B2
		return false;
	/*
	##################################END OF NORMAL CASES################################################
	*/
	} else if ( abs( c[1][0]*glm::dot(D,A2) - c[2][0]*glm::dot(D,A1) ) > ( ( a[1]*abs(c[2][0]) + a[2]*abs(c[1][0]) ) + ( b[1]*abs(c[0][2]) + b[2]*abs(c[0][1]) ) ) ) { //A0xB0
		return false;
	} else if ( abs( c[1][1]*glm::dot(D,A2) - c[2][1]*glm::dot(D,A1) ) > ( ( a[1]*abs(c[2][1]) + a[2]*abs(c[1][1]) ) + ( b[1]*abs(c[0][2]) + b[2]*abs(c[0][0]) ) ) ) { //A0xB1
		return false;
	} else if ( abs( c[1][2]*glm::dot(D,A2) - c[2][2]*glm::dot(D,A1) ) > ( ( a[1]*abs(c[2][2]) + a[2]*abs(c[1][2]) ) + ( b[1]*abs(c[0][1]) + b[2]*abs(c[0][0]) ) ) ) { //A0xB2
		return false;
	/*
	##################################END OF CROSS CASES-1################################################
	*/
	} else if ( abs( c[2][0]*glm::dot(D,A0) - c[0][0]*glm::dot(D,A2) ) > ( ( a[0]*abs(c[2][0]) + a[2]*abs(c[0][0]) ) + ( b[1]*abs(c[1][2]) + b[2]*abs(c[1][1]) ) ) ) { //A1xB0
		return false;
	} else if ( abs( c[2][1]*glm::dot(D,A0) - c[0][1]*glm::dot(D,A2) ) > ( ( a[0]*abs(c[2][1]) + a[2]*abs(c[0][1]) ) + ( b[0]*abs(c[1][2]) + b[2]*abs(c[1][0]) ) ) ) { //A1xB1
		return false;
	} else if ( abs( c[2][2]*glm::dot(D,A0) - c[0][2]*glm::dot(D,A2) ) > ( ( a[0]*abs(c[2][2]) + a[2]*abs(c[0][2]) ) + ( b[0]*abs(c[1][1]) + b[1]*abs(c[1][0]) ) ) ) { //A1xB2
		return false;
	/*
	##################################END OF CROSS CASES-2################################################
	*/
	} else if ( abs( c[0][0]*glm::dot(D,A1) - c[1][0]*glm::dot(D,A0) ) > ( ( a[0]*abs(c[1][0]) + a[1]*abs(c[0][0]) ) + ( b[1]*abs(c[2][2]) + b[2]*abs(c[2][1]) ) ) ) { //A2xB0
		return false;
	} else if ( abs( c[0][1]*glm::dot(D,A1) - c[1][1]*glm::dot(D,A0) ) > ( ( a[0]*abs(c[1][1]) + a[1]*abs(c[0][1]) ) + ( b[0]*abs(c[2][2]) + b[2]*abs(c[2][0]) ) ) ) { //A2xB1
		return false;
	} else if ( abs( c[0][2]*glm::dot(D,A1) - c[1][2]*glm::dot(D,A0) ) > ( ( a[0]*abs(c[1][2]) + a[1]*abs(c[0][2]) ) + ( b[0]*abs(c[2][1]) + b[1]*abs(c[2][0]) ) ) ) { //A2xB2
		return false;
	}
	return true;
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

Position Cuboid::getMinPoint() {
	Position p = glm::vec4( centre.x - (0.5*dimensions.x) , centre.y - (0.5*dimensions.y) , centre.z - (0.5*dimensions.z) , 1.0);
	return p;
}

Position Cuboid::getMaxPoint() {
	Position p = glm::vec4( centre.x + (0.5*dimensions.x) , centre.y + (0.5*dimensions.y) , centre.z + (0.5*dimensions.z) , 1.0);
	return p;
}

/** Auxillary functions . */
bool Cuboid::get_intersection_on_plane(double dist1, double dist2 , Position ls , Position le , Position& hitp) {
	if ( dist1*dist2 >= 0 || dist1==dist2 ) {
		return false;
	} else {
		Position delta = le-ls;
		double scle = ((-dist1)/(dist2-dist1));
		delta.x *= scle;
		delta.y *= scle;
		delta.z *= scle;
		hitp = ls + delta;
		return true;
	}
}
bool Cuboid::in_aabb(Position p, AXIS ax) {
	if(ax == X) {
		Position mi , mx;
		mi = getMinPoint();
		mx = getMaxPoint();
		return (p.z>mi.z && p.z<mx.z && p.y>mi.y && p.y<mx.y);
	} else if ( ax==Y) {
		Position mi , mx;
		mi = getMinPoint();
		mx = getMaxPoint();
		return (p.z>mi.z && p.z<mx.z && p.x>mi.x && p.x<mx.x);
	} else if (ax==Z) { 
		Position mi , mx;
		mi = getMinPoint();
		mx = getMaxPoint();
		return (p.y>mi.y && p.y<mx.y && p.x>mi.x && p.x<mx.x);
	}
	return false;
}
#endif