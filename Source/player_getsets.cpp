#ifndef PLAYER_GET_SET_CPP
#define PLAYER_GET_SET_CPP
#include "player.hpp"

BulletWorld* Player::getBulletWorld() { return bulletWorld; }
void Player::setFighterType(OBJECT_TYPE _type) { fighterType = _type;}
OBJECT_TYPE Player::getFighterType() { return fighterType; }
SpaceObject* Player::getFighter() { return fighter; }
#endif