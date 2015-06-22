#pragma once

#include "LinkedList.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h" 
#include "Player.h"

class Player;

class Inventory
{
public:
	Inventory(Player* player);
	~Inventory();

	void equipWeapon(Weapon* weapon);
	void equipArmor(Armor* armor, Item::Type type);

	void draw(sf::RenderWindow* window);

private:
	LinkedList<Item> bag;
	Item* chest;
	Item* head;
	Item* hands;
	Item* weapon;
	Item* legs;
	Item* feet;

	Player* player;
};

