#include "Player.h"

Player::Player(std::string name, Attribute attributes[], Ability abilities[], int hp, int mana) 
	: Actor(name, attributes, abilities, hp, mana)
{

}

Player::~Player()
{

}
