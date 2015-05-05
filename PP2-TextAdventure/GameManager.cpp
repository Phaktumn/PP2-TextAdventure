#include "GameManager.h"

std::map<std::string, std::shared_ptr<Item>> GameManager::itemDatabase;

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
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
			int baseStr = armorObj["BaseStrength"].as<int>();
			int baseInt = armorObj["BaseIntellect"].as<int>();
			int baseArmor = armorObj["BaseArmor"].as<int>();

			itemDatabase.emplace(name, std::shared_ptr<Item>(new Armor(sf::Color::Red, sf::String(name), baseStr, baseInt, baseArmor)));
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
			int damage = weaponObj["Damage"].as<int>();
			int baseStr = weaponObj["BaseStrength"].as<int>();
			int baseInt = weaponObj["BaseIntellect"].as<int>();

			itemDatabase.emplace(name, std::shared_ptr<Item>(new Weapon(sf::Color::Red, sf::String(name), baseStr, baseInt, damage)));
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