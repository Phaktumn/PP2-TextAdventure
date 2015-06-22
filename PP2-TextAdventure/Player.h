#pragma once
#include "Actor.h"
#include "Globals.h"

class Player : public Actor
{
private:

public:
	Player(std::string name, LinkedList<Attribute*> _attributes, LinkedList<Ability*> _abilities, int hp, int mana);
	~Player();

	void addBonusArmor(int Bonus_Armor);
	void removeBonusArmor(int value);

	void addBonusDamage(int Bonus_Damage);
	void removeBonusDamage(int value);

	void addBonusIntellect(int Bonus_Intellect);
	void removeBonusIntellect(int value);
};

