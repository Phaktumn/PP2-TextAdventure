#pragma once
#include <SFML\Graphics.hpp>
#include "LinkedList.h"
#include "Item.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern sf::String SEPARATOR;
extern std::map<int, sf::String> options;
extern bool activeInput;

extern sf::String STRENGTH;
extern sf::String INTELLECT;
extern sf::String ARMOR;

/*
WARRIOR
	base armor
	base strength
	base intellect

MAGE	
	base armor
	base strength
	base intellect
*/
#define WARRIOR_BASE_STRENGTH 15
#define WARRIOR_BASE_INTELLECT 5
#define WARRIOR_BASE_ARMOR 20

#define MAGE_BASE_STRENGTH 5
#define MAGE_BASE_INTELLECT 20
#define MAGE_BASE_ARMOR 15

#define ATTRIBUTES_DATABASE__WARRIOR_ASSET1 "WarriorStrenght"
#define ATTRIBUTES_DATABASE__WARRIOR_ASSET2 "WarriorIntellect"
#define ATTRIBUTES_DATABASE__WARRIOR_ASSET3 "WarriorArmor"

#define ATTRIBUTES_DATABASE__MAGE_ASSET1 "MageStrenght"
#define ATTRIBUTES_DATABASE__MAGE_ASSET2 "MageIntellect"
#define ATTRIBUTES_DATABASE__MAGE_ASSET3 "MageArmor"

//just a fcking test
extern void addOptions(int i, sf::String asset);
extern sf::String getOption(int i);
//just a fcking test
