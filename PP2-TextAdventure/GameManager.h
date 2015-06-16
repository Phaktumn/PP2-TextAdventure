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

class GameManager
{
public:
	GameManager();
	~GameManager();

	static void loadGlobals();
	static void loadItems(const std::string &filePath);
	static void loadMobs(const std::string &filePath);
	static Item* getItem(const std::string &name);
	static Ability* getAbility(const std::string &name);
	static void loadAbility(Ability* ability);

private:
	static std::map<std::string, std::shared_ptr<Item>> itemDatabase;
	static std::map<std::string, std::shared_ptr<Actor>> mobsDatabase;
	static std::map<std::string, std::shared_ptr<Attribute>> attributesDatabase;
};

