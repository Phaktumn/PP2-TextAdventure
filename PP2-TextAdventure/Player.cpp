#include "Player.h"

Player::Player(std::string name, LinkedList<Attribute*> _attributes, LinkedList<Ability*> _abilities, int hp, int mana, int level)
	: Actor(name, _attributes, _abilities, hp, mana, level)
{
	inventory = new Inventory(this);
	TotalExperience = 500;
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
	Actor::getAttribute(BONUS_INTELLECT)->changeValue(Bonus_Intellect);
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

void Player::afterBattle(int xp){
	Experience += xp;
	if (Experience >= TotalExperience){
		level++;
		Experience = Experience - TotalExperience;
		TotalExperience = TotalExperience * 1.5;
	}
}
