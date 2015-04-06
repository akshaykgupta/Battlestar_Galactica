#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/vector.hpp>

struct State {
	int health;
	int ammo;
	vector<float> transform; //position, rotation.
	vector<float> linearVelocity, angularVelocity;
	OBJECT_TYPE objType;
	
	State(int h,int am, btTransform& t, btVector3& lv , btVector3& av, OBJECT_TYPE _t) {
		health = h;
		ammo = am;
		float temp[16];
		t.getOpenGLMatrix(temp);
		transform.assign(temp , temp + 15);

		linearVelocity.push_back(lv.getX());
		linearVelocity.push_back(lv.getY());
		linearVelocity.push_back(lv.getZ());

		angularVelocity.push_back(av.getX());
		angularVelocity.push_back(av.getY());
		angularVelocity.push_back(av.getZ());
		objType = _t;
	}

	void setData(int h,int am, btTransform& t, btVector3& lv , btVector3& av, OBJECT_TYPE _t) {
		health = h;
		ammo = am;
		float temp[16];
		t.getOpenGLMatrix(temp);
		transform.assign(temp , temp + 15);

		linearVelocity.clear();
		linearVelocity.push_back(lv.getX());
		linearVelocity.push_back(lv.getY());
		linearVelocity.push_back(lv.getZ());

		angularVelocity.clear();
		angularVelocity.push_back(av.getX());
		angularVelocity.push_back(av.getY());
		angularVelocity.push_back(av.getZ());
		objType = _t;
	}

	void getData(int& h, int& am, btTransform& t, btVector3& velo, btVector3& avelo , OBJECT_TYPE& _t) {
		h = health;
		am = ammo;
		float temp[16];
		for(int i=0; i<16; ++i) {
			temp[i] = transform[i];
		}
		t.setFromOpenGLMatrix(temp);
		velo.setX(linearVelocity[0]);
		velo.setY(linearVelocity[1]);
		velo.setZ(linearVelocity[2]);
		avelo.setX(linearVelocity[0]);
		avelo.setY(linearVelocity[1]);
		avelo.setZ(linearVelocity[2]);
		_t = objType;
	}

	template<typename Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar & health;
		ar & transform;
		ar & linearVelocity;
		ar & angularVelocity;
		ar & objType;
	}

};

struct Message {
	MESSAGE_PROTOCOL msgType;
	State ship; //general data - includes myShip details.
	//collision data, is essentially health and new transform.
	std::string chatMessage;	 //chat data.
	vector<float> laserFrom,laserTo; //laser data. LINE SEGMENT.
	WEAPON_TYPE wpnType;
	/* Connection data */
	std::string newConnectorIP;
	/*
		IDEA : Forward this message to everyone, and respond to the sender with my details.
	*/
	std::string worldData; //file name to load from.

	Message(MESSAGE_PROTOCOL& prot , 
		int& h, int& am, btTransform& t, btVector3& velo, btVector3& avelo , OBJECT_TYPE& _t, //For state
		btVector3& _laserFrom , btVector3& _laserTo , WEAPON_TYPE& _wpnType , 
		std::string ip = "" , std::string chatmsg = "" , std::string worldfile = "") : 
	    ship(h, am, t, velo, avelo , _t) {
		
		msgType = prot;
		wpnType = _wpnType;
		newConnectorIP = ip;
		chatMessage = chatmsg;

		laserFrom.push_back(_laserFrom.getX());
		laserFrom.push_back(_laserFrom.getY());
		laserFrom.push_back(_laserFrom.getZ());

		laserTo.push_back(_laserTo.getX());
		laserTo.push_back(_laserTo.getY());
		laserTo.push_back(_laserTo.getZ());
		
	}
	
	void setData(MESSAGE_PROTOCOL prot , 
		int& h, int& am, btTransform& t, btVector3& velo, btVector3& avelo , OBJECT_TYPE& _t, //For state
		btVector3& _laserFrom , btVector3& _laserTo ,WEAPON_TYPE& _wpnType,
		std::string ip = "" , std::string chatmsg = "" , std::string worldfile = "") {
		
		ship.setData(h, am, t, velo, avelo , _t);
		
		msgType = prot;
		wpnType = _wpnType;
		
		newConnectorIP = ip;
		chatMessage = chatmsg;
		worldData = worldfile;

		laserFrom.clear();
		laserFrom.push_back(_laserFrom.getX());
		laserFrom.push_back(_laserFrom.getY());
		laserFrom.push_back(_laserFrom.getZ());

		laserTo.clear();
		laserTo.push_back(_laserTo.getX());
		laserTo.push_back(_laserTo.getY());
		laserTo.push_back(_laserTo.getZ());
	}


	void getData(MESSAGE_PROTOCOL& prot , 
		int& h, int& am, btTransform& t, btVector3& velo, btVector3& avelo , OBJECT_TYPE& _t, //For state
		btVector3& _laserFrom , btVector3& _laserTo ,WEAPON_TYPE& _wpnType,
		std::string& ip, std::string& chatmsg, std::string& worldfile) {
		
		prot = msgType;
		_wpnType = wpnType;
		
		ip = newConnectorIP;
		worldfile = worldData;
		chatmsg = chatMessage;
		
		ship.getData(h, am, t, velo, avelo , _t);

		_laserFrom.setX(laserFrom[0]);
		_laserTo.setX(laserTo[0]);
		_laserFrom.setY(laserFrom[1]);
		_laserTo.setY(laserTo[1]);
		_laserFrom.setZ(laserFrom[2]);
		_laserTo.setZ(laserTo[2]);
	
	}

	template<typename Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar & msgType;
		ar & ship;
		ar & chatMessage;
		ar & laserFrom;
		ar & laserTo;
		ar & newConnectorIP;
		ar & worldData;
	}
};

#endif