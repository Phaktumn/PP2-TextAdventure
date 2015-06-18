#include "Player.h"

Player::Player(std::string name, Attribute attributes[], Ability abilities[], int hp, int mana) 
	: Actor(name, attributes, abilities, hp, mana)
{
	
}

Player::~Player()
{

}

void Player::addBonusArmor(int Bonus_Armor)
{
	Actor::getAttribute(BONUS_ARMOR).changeValue(Bonus_Armor);
}

void Player::addBonusDamage(int Bonus_Strength)
{
	Actor::getAttribute(BONUS_STRENGTH).changeValue(Bonus_Strength);
}

void Player::addBonusIntellect(int Bonus_Intellect)
{
	Actor::getAttribute(BONUS_ARMOR).changeValue(Bonus_Intellect);
}
