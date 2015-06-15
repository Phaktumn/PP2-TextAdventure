#include "Player.h"

Player::Player(std::string name, Attribute attributes[], Ability abilities[], int hp, int mana, int baseArmor) 
	: Actor(name, attributes, abilities, hp, mana, baseArmor)
{

}

Player::~Player()
{

}
