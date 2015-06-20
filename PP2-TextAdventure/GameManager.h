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

class GameManager
{
public:
	GameManager();
	~GameManager();

	static void loadGlobals();
	static void loadItems(const std::string &filePath);
	static void loadMobs(const std::string &filePath);
	static void loadLocations(const std::string &filePath);

	static Item* getItem(const std::string &name);
	static Ability* getAbility(const std::string &name);
	static Attribute* getAttribute(const std::string &name);

	static std::string getLocationName(unsigned int location);
	static std::string getLocationDescription(unsigned int location);

	static void loadAbility(Ability* ability);
	static void initializeAttributes();

	static std::map<int, std::string> locationDatabase;

private:
	static std::map<std::string, std::shared_ptr<Item>> itemDatabase;
	static std::map<std::string, std::shared_ptr<Actor>> mobsDatabase;
	static std::map<std::string, std::shared_ptr<Attribute>> attributesDatabase;
	static std::map<int, std::string> locationsDescriptions;
};

