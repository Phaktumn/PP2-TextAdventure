#include "Actor.h"
#include "Globals.h"

#pragma once
class Player : public Actor
{
private:
	//inventory here! tho
public:
	Player(std::string name, Attribute attributes[], Ability abilities[], int hp, int mana);
	~Player();

	void addBonusArmor(int Bonus_Armor);
	void removeBonusArmor(int value);

	void addBonusDamage(int Bonus_Damage);
	void removeBonusDamage(int value);

	void addBonusIntellect(int Bonus_Intellect);
	void removeBonusIntellect(int value);
};

