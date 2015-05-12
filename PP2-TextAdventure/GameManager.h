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

class GameManager
{
public:
	GameManager();
	~GameManager();

	static void loadGlobals();
	static void loadItems(const std::string &filePath);
	static Item* getItem(const std::string &itemName);

private:
	static std::map<std::string, std::shared_ptr<Item>> itemDatabase;
};

