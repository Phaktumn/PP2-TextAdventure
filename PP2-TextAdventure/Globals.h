#pragma once
#include <SFML\Graphics.hpp>
#include "LinkedList.h"
#include "Item.h"

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 540

#define LOCATION_DESCRIPTION_POSITION_X 15
#define LOCATION_DESCRIPTION_POSITION_Y 70
#define LOCATION_NAME_POSITION_X 15
#define LOCATION_NAME_POSITION_Y 30

#define BIG_CHARACTER_SIZE 26
#define NORMAL_CHARACTER_SIZE 22

extern sf::String SEPARATOR;
extern bool activeInput;

extern sf::String STRENGTH;
extern sf::String BONUS_STRENGTH;

extern sf::String INTELLECT;
extern sf::String BONUS_INTELLECT;

extern sf::String ARMOR;
extern sf::String BONUS_ARMOR;

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
#define WARRIOR_BONUS_STRENGTH 0
#define WARRIOR_BASE_INTELLECT 5
#define WARRIOR_BONUS_INTELLECT 0
#define WARRIOR_BASE_ARMOR 20
#define WARRIOR_BONUS_ARMOR 0

#define MAGE_BASE_STRENGTH 5
#define MAGE_BONUS_STRENGTH 0
#define MAGE_BASE_INTELLECT 20
#define MAGE_BONUS_INTELLECT 0
#define MAGE_BASE_ARMOR 15
#define MAGE_BONUS_ARMOR 0

#define ATTRIBUTES_DATABASE__WARRIOR_ASSET1_1 "WarriorStrenght"
#define ATTRIBUTES_DATABASE__WARRIOR_ASSET1_2 "WarriorBonusStrenght"
#define ATTRIBUTES_DATABASE__WARRIOR_ASSET2_1 "WarriorIntellect"
#define ATTRIBUTES_DATABASE__WARRIOR_ASSET2_2 "WarriorBonusIntellect"
#define ATTRIBUTES_DATABASE__WARRIOR_ASSET3_1 "WarriorArmor"
#define ATTRIBUTES_DATABASE__WARRIOR_ASSET3_2 "WarriorBonusArmor"

#define ATTRIBUTES_DATABASE__MAGE_ASSET1_1 "MageStrenght"
#define ATTRIBUTES_DATABASE__MAGE_ASSET1_2 "MageBonusStrenght"
#define ATTRIBUTES_DATABASE__MAGE_ASSET2_1 "MageIntellect"
#define ATTRIBUTES_DATABASE__MAGE_ASSET2_2 "MageBonusIntellect"
#define ATTRIBUTES_DATABASE__MAGE_ASSET3_1 "MageArmor"
#define ATTRIBUTES_DATABASE__MAGE_ASSET3_2 "MageSBonusArmor"

extern std::map<int, sf::String> World_Locations_Names;