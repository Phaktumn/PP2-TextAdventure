#include "GameManager.h"
#include "Globals.h"

std::map<std::string, std::shared_ptr<Item>> GameManager::itemDatabase;

GameManager::GameManager()
{
	
}


GameManager::~GameManager()
{
}

void GameManager::loadGlobals() {
	Item::loadProperties();
}

void GameManager::loadItems(const std::string &filePath)
{
	jsoncons::json armorFile = jsoncons::json::parse_file(filePath + "/armors.json");
	jsoncons::json weaponFile = jsoncons::json::parse_file(filePath + "/weapons.json");

	// Load armor
	for (size_t i = 0; i < armorFile.size(); i++) {
		try {
			jsoncons::json &armorObj = armorFile[i];

			std::string name = armorObj["Name"].as<std::string>();
			std::string description = armorObj["Description"].as<std::string>();
			std::string qualityString = armorObj["Quality"].as<std::string>();
			int typeInt = armorObj["Type"].as<int>();
			int baseStr = armorObj["BaseStrength"].as<int>();
			int baseInt = armorObj["BaseIntellect"].as<int>();
			int baseArmor = armorObj["BaseArmor"].as<int>();

			Item::Type type = static_cast<Item::Type>(typeInt);

			itemDatabase.emplace(name, std::shared_ptr<Item>(new Armor(sf::String(qualityString), sf::String(name), type, baseStr, baseInt, baseArmor)));
		}
		
		catch (const jsoncons::json_exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	// Load weapons
	for (size_t i = 0; i < weaponFile.size(); i++) {
		try {
			jsoncons::json &weaponObj = weaponFile[i];

			std::string name = weaponObj["Name"].as<std::string>();
			std::string description = weaponObj["Description"].as<std::string>();
			std::string qualityString = weaponObj["Quality"].as<std::string>();
			int Type = weaponObj["Type"].as<int>();
			int damage = weaponObj["Damage"].as<int>();
			int baseStr = weaponObj["BaseStrength"].as<int>();
			int baseInt = weaponObj["BaseIntellect"].as<int>();

			Item::Type type = static_cast<Item::Type>(Type);

			itemDatabase.emplace(name, std::shared_ptr<Item>(new Weapon(sf::String(qualityString), sf::String(name), type, baseStr, baseInt, damage)));
		}
		catch (const jsoncons::json_exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

Item* GameManager::getItem(const std::string &itemName)
{
	return itemDatabase[itemName].get();
}