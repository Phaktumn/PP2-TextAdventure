#include "LinkedList.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h" 

#pragma once
class Inventory
{
private:
	Item* chest;
	Item* head;
	Item* hands;
	Item* weapon;
	Item* legs;
	Item* feet;

public:
	Inventory();
	~Inventory();

	void equipWeapon(Weapon* weapon);
	void equipArmor(Armor* armor, Item::Type type);
};

