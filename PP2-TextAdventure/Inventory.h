#pragma once

#include "Player.h"
#include "LinkedList.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h" 
#include "Actor.h"
#include "RichText.hpp"

class Player;

class Inventory
{
public:
	Inventory(Player* player);
	~Inventory();

	void equipWeapon(Weapon* weapon);
	void equipArmor(Armor* armor, Item::Type type);

	void draw(sf::RenderWindow* window, sf::Font &font);
	void drawPos(sf::RenderWindow* window, sf::Font &font, int x, int y);

	void drawBag(sf::RenderWindow* window, sf::Font &font);

	Weapon* getEquipedWeapon();

	LinkedList<Item*> bag;

	bool addToBags(Item* _item);

private:

	void drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window);
	void drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window);

	Armor* chest;
	Armor* head;
	Armor* hands;
	Weapon* weapon;
	Armor* legs;
	Armor* feet;

	Player* player;
};

