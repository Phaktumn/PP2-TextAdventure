#include "LinkedList.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h" 
#include "Actor.h"
#include "Player.h"

#pragma once
class Inventory
{
private:
	LinkedList<Item> bag;
	Item* chest;
	Item* head;
	Item* hands;
	Item* weapon;
	Item* legs;
	Item* feet;

public:
	Inventory();
	~Inventory();

	void equipWeapon(Weapon* weapon, Player* player);
	void equipArmor(Armor* armor, Item::Type type, Player* player); 
};

