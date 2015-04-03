#ifndef PLAYER_CPP
#define PLAYER_CPP
#include "player.hpp"

Player::Player() {
	//Do things.
	init_bulletWorld();
	settings.fov = 90.0f;
}

Player::~Player() {
	//Do things.
	music->stop();
	delete music;
	//delete bulletWorld;
}
void Player::init_bulletWorld() {
	bulletWorld = new BulletWorld();
}

void Player::init_fighter() {
	fighter = new SpaceObject(fighterType);
	fighter->init(bulletWorld);
	//fighter->setVelocity(btVector3(0,0,-5.0));
}
void Player::debug() {

}

void Player::playMusic(bool dflag){
	if(!dflag){
		return;
	}
	bool isSoundThere = false;
    string path = MUSIC_RSC_DIR+SW_MUSIC+MUSIC_EXTENSION;
	//sf::Music music;
    music = new sf::Music;
    cout<<path.c_str()<<"\n";
    cout<<isSoundThere<<"\n";
    if(music->openFromFile(path.c_str())){
        isSoundThere=true;
    }
    if(isSoundThere){
    cout<<isSoundThere<<"\n";
    music->play();
    cout<<isSoundThere<<"\n";
    }
    
}
void Player::update_state(double dt) {
	
}

void Player::render_state(double dt) {
	bulletWorld->dynamicsWorld->stepSimulation(dt);
	fighter->render(true);
}
void Player::setup_game_screen(double winX, double winY) {
	glEnable(GL_DEPTH_TEST);
	//glDepthMask(GL_TRUE);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(settings.fov/2,winX/winY,1.0f,1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0,0,10 , 0,0,0 ,0,1.0,0);
	glViewport(0, 0, winX, winY);
    glFlush();
}


bool Player::collisionCallback(btManifoldPoint& cp,
	const btCollisionObject* obj1,int id1,int index1,
	const btCollisionObject* obj2,int id2,int index2) {

	((SpaceObject*)(obj1->getUserPointer()))->handleCollision(((SpaceObject*)(obj2->getUserPointer())));
	((SpaceObject*)(obj2->getUserPointer()))->handleCollision(((SpaceObject*)(obj1->getUserPointer())));

}

#endif