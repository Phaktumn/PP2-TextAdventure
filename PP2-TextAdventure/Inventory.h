#pragma once

#include "Player.h"
#include "LinkedList.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h" 
#include "Actor.h"

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
	Armor* chest;
	Armor* head;
	Armor* hands;
	Item* weapon;
	Armor* legs;
	Armor* feet;

	Player* player;
};

