#pragma once
#include "Actor.h"
#include "Globals.h"
#include "Inventory.h"

class Inventory;

class Player : public Actor
{
private:
	Inventory* inventory;

public:
	Player(std::string name, LinkedList<Attribute*> _attributes, LinkedList<Ability*> _abilities, int hp, int mana, int level);
	~Player();

	int Experience, TotalExperience;
	bool leveled = false;


	void update()override;

	int getXp(){ return Experience;}
	int getTXp(){ return TotalExperience; }

	void afterBattle(int Xp);

	void addBonusArmor(int Bonus_Armor);
	void removeBonusArmor(int value);

	void addBonusDamage(int Bonus_Damage);
	void removeBonusDamage(int value);

	void addBonusIntellect(int Bonus_Intellect);
	void removeBonusIntellect(int value);

	void addDamage(int DAMAGE);
	void removeDamage(int value);

	Inventory* getInventory(){ return inventory; }

};

