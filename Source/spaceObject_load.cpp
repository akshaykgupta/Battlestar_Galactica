#ifndef SPACE_OBJECT_CPP
#define SPACE_OBJECT_CPP
#include "spaceObject.hpp"

/** file with functions for loading and initializing things.
	Bucket list : Use static VBOs while drawing complicated
*/

SpaceObject::SpaceObject(OBJECT_TYPE _type) {
	obj_type = _type;
	objpath = OBJ_RSC_DIR;
	phypath = PHY_RSC_DIR;
    activeWeapon = 0;
	//TODO
	weapons.resize(1);
	weapons[0] = new Weapon( STRONG_LASER , btVector3(200,200,0));

}

SpaceObject::~SpaceObject() {
	//figure out which order to delete things in.
	delete body;
	delete dms;
	delete shape;
}

void SpaceObject::print(bool dflag) {
	if (!dflag) {
		return;
	}
}
//inits
void SpaceObject::init(BulletWorld* _world) {
	
	world = _world;
	switch (obj_type) {
		//TODO : set path names and load the file.
		case ASTEROID : {
			objpath += ASTEROID_FNAME + OBJ_EXTENSION;
			phypath += ASTEROID_FNAME + PHY_EXTENSION;
			break;
		} case HEALTH : {
			objpath += HEALTH_FNAME + OBJ_EXTENSION;
			phypath += HEALTH_FNAME + PHY_EXTENSION;
			break;
		} case TIE : {
			objpath += AMMO_FNAME + OBJ_EXTENSION;
			phypath += AMMO_FNAME + PHY_EXTENSION;
			break;
		} case XWING : {
			objpath += XWING_FNAME + OBJ_EXTENSION;
			phypath += XWING_FNAME + PHY_EXTENSION;
			break;
		} case MF : {
			objpath += MF_FNAME + OBJ_EXTENSION;
			phypath += MF_FNAME + PHY_EXTENSION;
			break;
		} case UFO : {
			objpath += UFO_FNAME + OBJ_EXTENSION;
			phypath += UFO_FNAME + PHY_EXTENSION;
			break;
		} default : {
			std::cout << " Unknown object type. Please ensure that OBJ_Type=" << obj_type << " is defined appropriately. \n";
			return;
		}
	}
	physics_init();
	render_init();
	return;
}

void SpaceObject::physics_init() {
	//read the file format.
	readPhysicsFile(); //reads into children and childTransform
	// std::cout << "read phy file\n";
	//create the objects.
	createCompoundShape();
	// cout << "#brk2\n";
	body->setActivationState(DISABLE_DEACTIVATION);
	return;
}


void SpaceObject::createCompoundShape() {
	//Child transforms are all in the vectors.
	shape = new btCompoundShape();
	for(int i=0; i< children.size(); ++i) {
		shape->addChildShape(childTransform[i] , children[i]);
		 //cout << children[i]->getName() << "\n";
	}
	//my shape is now ready.
	dms = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
	shape->calculateLocalInertia(mass, moment_inertia);
	btRigidBody::btRigidBodyConstructionInfo bodyCI(mass, dms, (btCollisionShape*)shape , moment_inertia );
    body = new btRigidBody(bodyCI);
    body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_CUSTOM_MATERIAL_CALLBACK);
    body->setUserPointer(this);
    body->setDamping(linearDamping,angularDamping);
    body->setLinearFactor(btVector3(1,1,1));
    world->dynamicsWorld->addRigidBody(body);
}
void SpaceObject::render_init() {
	return;//TODO
}

void SpaceObject::loadRenderGeometry() {
	return;//TODO
}

void SpaceObject::loadPhysicsGeometry() {
	return;//TODO
}
void SpaceObject::readPhysicsFile(){
	fstream f;
	f.open(phypath);
	if(f.fail()){
		cout<<"Error in file path";
		return;
	}
	int count=0;
	string temp;
	float temp2;
	/*getline(f,temp);
	stringstream mTemp(temp);
	mTemp>>temp2;
	mass = temp2;
	count++;	*/
	while(getline(f,temp)){
		count++;
		vector<float> ans;
		istringstream s(temp);
		string line_type = "";
		s >> line_type;
		while(!s.eof()){
			s>>temp2;
			ans.push_back(temp2);
		}
		if(line_type == "Misc"){
			if(ans.size()!=9){
				cout<<"ERROR in file "<<phypath<<" line number "<<count<<"\n";
				exit(1);
			}
			else{
				mass = ans[0];
				maxVelocity = ans[1];
				scalingAcceleration = ans[2];
				linearDamping = ans[3];
				angularDamping = ans[4];
				maxOmega = ans[5];
				scalingOmega = ans[6];
				mouseScalePitch = ans[7];
				mouseScaleYaw = ans[8];
				cout<<mass<<" "<<maxVelocity<<" "<<scalingAcceleration<<" "<<linearDamping<<" "<<angularDamping<<"\n";
			}
		}else if ( line_type == "Box" ) {
			if(ans.size()!= 6){
				cout<<"ERROR in file "<<phypath<<" line number "<<count<<"\n";
				exit(1);
			}
			
				btCollisionShape* nbox = new btBoxShape(btVector3(ans[3],ans[4],ans[5]));
				btTransform t(btQuaternion(0,0,0,1) , btVector3(ans[0],ans[1],ans[2]));
				children.push_back(nbox);
				childTransform.push_back(t);
		}else if ( line_type == "Cam" ) {
			if(ans.size()!= 6){
				cout<<"ERROR in file "<<phypath<<" line number "<<count<<"\n";
				exit(1);
			}
			cameras.push_back(make_pair( btVector3(ans[0] , ans[1] , ans[2]) , btVector3(ans[3], ans[4] , ans[5]) ));
		} else if ( line_type == "Weapon" ) {

		}
	}
	f.close();
}
	
#endif