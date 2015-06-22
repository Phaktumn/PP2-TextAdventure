#include "Player.h"

Player::Player(std::string name, LinkedList<Attribute*> _attributes, LinkedList<Ability*> _abilities, int hp, int mana)
	: Actor(name, _attributes, _abilities, hp, mana)
{
	inventory = new Inventory(this);
}

Player::~Player()
{

}
/*
	Increase bonusArmor
	Decrease bonusArmor

	Increase bonusDamage
	Decrease bonusDamage

	Increase bonusIntellect
	Decrease bonusIntellect
*/
void Player::addBonusArmor(int Bonus_Armor){
	Actor::getAttribute(BONUS_ARMOR)->changeValue(Bonus_Armor);
}
void Player::removeBonusArmor(int value){
	Actor::getAttribute(BONUS_ARMOR)->changeValue(-(value));
}


void Player::addBonusDamage(int Bonus_Strength){
	Actor::getAttribute(BONUS_STRENGTH)->changeValue(Bonus_Strength);
}
void Player::removeBonusDamage(int value){
	Actor::getAttribute(BONUS_STRENGTH)->changeValue(-(value));
}


void Player::addBonusIntellect(int Bonus_Intellect){
	Actor::getAttribute(BONUS_ARMOR)->changeValue(Bonus_Intellect);
}
void Player::removeBonusIntellect(int value){
	Actor::getAttribute(BONUS_INTELLECT)->changeValue(-(value));
}

void Player::addDamage(int Damage){
	Actor::setDamage(Damage);
}
void Player::removeDamage(int value){
	Actor::setDamage(-(value));
}
