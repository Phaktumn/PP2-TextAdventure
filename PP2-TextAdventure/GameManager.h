#pragma once
#include <string>
#include "Item.h"
#include <jsoncons\json.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include "LinkedList.h"
#include "Armor.h"
#include "Weapon.h"
#include <memory>
#include "Actor.h"
#include "Ability.h"
#include "DamageAbility.h"
#include "World.h"
#include "Player.h"
#include "BattleStateMenu.h"

class BattleStateMenu;

class GameManager
{
public:
	GameManager();
	~GameManager();

	static void loadGlobals();
	static void loadItems(const std::string &filePath);
	static void loadMobs(const std::string &filePath);
	static void loadLocations(const std::string &filePath);

	static Item* getItem(const int key);
	static Ability* getAbility(const std::string &name);
	static Attribute* getAttribute(const std::string &name);
	static Attribute getAttribute_(const std::string &name);

	static std::map<int, std::shared_ptr<Item>> itemDatabase;

	static std::string getLocationName(unsigned int location);
	static std::string getLocationDescription(unsigned int location);
	static int getLocationLevel(unsigned int location);

	static void loadAbility(Ability* ability);
	static void initializeAttributes();

	static std::map<int, std::string> locationDatabase;

	static LinkedList<Attribute*> attribute;
	static LinkedList<Ability*> abilities;

	static Player* playerPtr;

	//gets and appropriate mob to battle with!
	static Actor* getRandMob(const int level);

	static Actor* getMob(const int code);
	//resets the mobs stats!
	static void reloadMOBS();

	static BattleStateMenu* battleMenu;

private:
	static int global_Counter;

	static std::map<int, std::shared_ptr<Actor>> mobsDatabase;
	static std::map<std::string, std::shared_ptr<Attribute>> attributesDatabase;
	
	static std::map<int, std::string> locationsDescriptions;
	static std::map<int, int> locationsLevels;

	static std::map<int, std::string> auxMobNAMES;

	//MOBS ATTRIBUTES!
	//MOB1
	static LinkedList<Attribute*> mob_1_Attributes;
	//
	//MOB2
	static LinkedList<Attribute*> mob_2_Attributes;
	//
	//MOB3
	static LinkedList<Attribute*> mob_3_Attributes;
	//
	//MOB4
	static LinkedList<Attribute*> mob_4_Attributes;


	static void addMobs();

	static Actor* player;
};

