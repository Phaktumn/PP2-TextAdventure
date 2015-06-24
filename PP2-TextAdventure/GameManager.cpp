#include "GameManager.h"
#include "Globals.h"


std::map<std::string, std::shared_ptr<Item>> GameManager::itemDatabase;
std::map<std::string, sf::Text> drawnText;
std::map<std::string, std::shared_ptr<Attribute>> GameManager::attributesDatabase;

std::map<std::string, std::shared_ptr<Actor>> GameManager::mobsDatabase;

std::map<int, std::string> GameManager::locationDatabase;
std::map<int, std::string> GameManager::locationsDescriptions;

LinkedList<Attribute*> GameManager::attribute;
LinkedList<Ability*> GameManager::abilities;

LinkedList<Attribute*> GameManager::mob_1_Attributes;
LinkedList<Attribute*> GameManager::mob_2_Attributes;

Actor* GameManager::player;
Player* GameManager::playerPtr;

GameManager::GameManager()
{
	
}

GameManager::~GameManager()
{
}

void GameManager::loadGlobals() {
	Item::loadProperties();

	//ATTRIBUTES WARRIOR===========================================================
	attribute.add(GameManager::getAttribute(ATTRIBUTES_DATABASE__WARRIOR_ASSET1_1));
	attribute.add(GameManager::getAttribute(ATTRIBUTES_DATABASE__WARRIOR_ASSET1_2));
	attribute.add(GameManager::getAttribute(ATTRIBUTES_DATABASE__WARRIOR_ASSET2_1)); 
	attribute.add(GameManager::getAttribute(ATTRIBUTES_DATABASE__WARRIOR_ASSET2_2)); 
	attribute.add(GameManager::getAttribute(ATTRIBUTES_DATABASE__WARRIOR_ASSET3_1));
	attribute.add(GameManager::getAttribute(ATTRIBUTES_DATABASE__WARRIOR_ASSET3_2));
	//==============================================================================

	//ABILITIES WARRIOR================================================================================
	abilities.add(new DamageAbility("Alpha Strike", Ability::MANA, 15, 5, DamageAbility::strength));
	abilities.add(new DamageAbility("Death Strike", Ability::MANA, 15, 10, DamageAbility::strength));
	abilities.add(new DamageAbility("Master Plan", Ability::MANA, 15, 15, DamageAbility::strength));
	abilities.add(new DamageAbility("Darkness", Ability::MANA, 50, 15, DamageAbility::strength));
	//=================================================================================================
	
	//ABILITIES MAGE================================================================================

	//==============================================================================================

	//PLAYER=========================================================================================
<<<<<<< HEAD
	player = new Player("jorge", GameManager::attribute, GameManager::abilities, WARRIOR_BASE_HP, 250);
=======
	player = new Player("jorge", GameManager::attribute, GameManager::abilities, 1000, 250, 1);
>>>>>>> origin/master
	playerPtr = (Player*)player;
	//===============================================================================================

	//AIDS THE MOBS TO A MOB DATABASE
	//ACCESS TO THE DATABASE IS STATIC PUBLIC
	addMobs();
}

void GameManager::addMobs()
{
	//Attributes MOB1
	mob_1_Attributes.add(GameManager::getAttribute("mobStrength1"));
	mob_1_Attributes.add(GameManager::getAttribute("mobIntellect1"));
	mob_1_Attributes.add(GameManager::getAttribute("mobArmor1"));
	//
	//Attributes MOB2
	mob_2_Attributes.add(GameManager::getAttribute("mobStrength2"));
	mob_2_Attributes.add(GameManager::getAttribute("mobIntellect2"));
	mob_2_Attributes.add(GameManager::getAttribute("mobArmor2"));
	//
	//Attributes MOB3

	//
	mobsDatabase.emplace("mob1", std::shared_ptr<Actor>(new Actor("mob1", GameManager::mob_1_Attributes, GameManager::abilities, 50, 10,1)));
	mobsDatabase.emplace("mob2", std::shared_ptr<Actor>(new Actor("mob2", GameManager::mob_2_Attributes, GameManager::abilities, 65, 25,1)));
}

Actor* GameManager::getMob(const std::string &name)
{
	return mobsDatabase[name].get();
}

void GameManager::loadItems(const std::string &filePath)
{
	jsoncons::json armorClothFile = jsoncons::json::parse_file(filePath + "/armorscloth.json");
	jsoncons::json weaponFile = jsoncons::json::parse_file(filePath + "/weapons.json");
	jsoncons::json armorPlateFile = jsoncons::json::parse_file(filePath + "/armorsplate.json");

	// Load armor
	for (size_t i = 0; i < armorClothFile.size(); i++) {
		try {
			jsoncons::json &armorObj = armorClothFile[i];

			std::string name = armorObj["Name"].as<std::string>();
			std::string description = armorObj["Description"].as<std::string>();
			std::string qualityString = armorObj["Quality"].as<std::string>();
			int typeInt = armorObj["Type"].as<int>();
			int bonusStr = armorObj["BaseStrength"].as<int>();
			int bonusInt = armorObj["BaseIntellect"].as<int>();
			int bonusArmor = armorObj["BaseArmor"].as<int>();

			Item::Type type = static_cast<Item::Type>(typeInt);

			itemDatabase.emplace(name, std::shared_ptr<Item>(new Armor(sf::String(qualityString), sf::String(name), type, bonusStr, bonusInt, bonusArmor)));
		}
		
		catch (const jsoncons::json_exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}

	for (size_t i = 0; i < armorPlateFile.size(); i++) {
		try {
			jsoncons::json &armorObj = armorPlateFile[i];

			std::string name = armorObj["Name"].as<std::string>();
			std::string description = armorObj["Description"].as<std::string>();
			std::string qualityString = armorObj["Quality"].as<std::string>();
			int typeInt = armorObj["Type"].as<int>();
			int bonusStr = armorObj["BaseStrength"].as<int>();
			int bonusInt = armorObj["BaseIntellect"].as<int>();
			int bonusArmor = armorObj["BaseArmor"].as<int>();

			Item::Type type = static_cast<Item::Type>(typeInt);

			itemDatabase.emplace(name, std::shared_ptr<Item>(new Armor(sf::String(qualityString), sf::String(name), type, bonusStr, bonusInt, bonusArmor)));
		}

		catch (const jsoncons::json_exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	//==============================================================================================================


	int _i = 0;
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

void GameManager::loadMobs(const std::string &filePath){

	jsoncons::json mobFile = jsoncons::json::parse_file(filePath + "/Mobs.json");

	//load mobs
	for (size_t i = 0; i < mobFile.size(); i++){
		try{
			jsoncons::json &mobObj = mobFile[i];

			std::string name = mobObj["Name"].as<std::string>();
			int Hp = mobObj["Hp"].as<int>();
			int Mana = mobObj["Mana"].as<int>();

			//hmm uma database de abilities sempre que crias uma basicamente GameManager::habilitiesDatabase.emplace(stuff here)
			//depois um get GameManager::getAbilitie(std::string name);
			//para adicionar aqui i dunno!
			//mobsDatabase.emplace(name, std::shared_ptr<Actor>(new Actor()));
		}
		catch(const jsoncons::json_exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
}

void GameManager::loadLocations(const std::string &filePath)
{
	jsoncons::json locationFile = jsoncons::json::parse_file(filePath + "/locations.json");

	//load locations
	for (size_t i = 0; i < locationFile.size(); i++)
	{
		try{
			jsoncons::json &locationObj = locationFile[i];

			std::string name = locationObj["Name"].as<std::string>();
			std::string description = locationObj["Description"].as<std::string>();

			locationDatabase.emplace(i, name);
			locationsDescriptions.emplace(i, description);
		}
		catch(const jsoncons::json_exception& e){
			std::cerr << e.what() << std::endl;
		}
	}
}

void GameManager::initializeAttributes(){
	attributesDatabase.emplace(ATTRIBUTES_DATABASE__WARRIOR_ASSET1_1, std::shared_ptr<Attribute>(new Attribute(STRENGTH, WARRIOR_BASE_STRENGTH)));
	attributesDatabase.emplace(ATTRIBUTES_DATABASE__WARRIOR_ASSET1_2, std::shared_ptr<Attribute>(new Attribute(BONUS_STRENGTH, WARRIOR_BONUS_STRENGTH)));
	attributesDatabase.emplace(ATTRIBUTES_DATABASE__WARRIOR_ASSET2_1, std::shared_ptr<Attribute>(new Attribute(INTELLECT, WARRIOR_BASE_INTELLECT)));
	attributesDatabase.emplace(ATTRIBUTES_DATABASE__WARRIOR_ASSET2_2, std::shared_ptr<Attribute>(new Attribute(BONUS_INTELLECT, WARRIOR_BONUS_INTELLECT)));
	attributesDatabase.emplace(ATTRIBUTES_DATABASE__WARRIOR_ASSET3_1, std::shared_ptr<Attribute>(new Attribute(ARMOR, WARRIOR_BASE_ARMOR)));
	attributesDatabase.emplace(ATTRIBUTES_DATABASE__WARRIOR_ASSET3_2, std::shared_ptr<Attribute>(new Attribute(BONUS_ARMOR, WARRIOR_BONUS_ARMOR)));

	attributesDatabase.emplace(ATTRIBUTES_DATABASE__MAGE_ASSET1_1, std::shared_ptr<Attribute>(new Attribute(STRENGTH, MAGE_BASE_STRENGTH)));
	attributesDatabase.emplace(ATTRIBUTES_DATABASE__MAGE_ASSET1_2, std::shared_ptr<Attribute>(new Attribute(BONUS_STRENGTH, MAGE_BONUS_STRENGTH)));
	attributesDatabase.emplace(ATTRIBUTES_DATABASE__MAGE_ASSET2_1, std::shared_ptr<Attribute>(new Attribute(INTELLECT, MAGE_BASE_INTELLECT)));
	attributesDatabase.emplace(ATTRIBUTES_DATABASE__MAGE_ASSET2_2, std::shared_ptr<Attribute>(new Attribute(BONUS_INTELLECT, MAGE_BONUS_INTELLECT)));
	attributesDatabase.emplace(ATTRIBUTES_DATABASE__MAGE_ASSET3_1, std::shared_ptr<Attribute>(new Attribute(ARMOR, MAGE_BASE_ARMOR)));
	attributesDatabase.emplace(ATTRIBUTES_DATABASE__MAGE_ASSET3_2, std::shared_ptr<Attribute>(new Attribute(BONUS_ARMOR, MAGE_BONUS_ARMOR)));

	//mob Lv1
	attributesDatabase.emplace("mobStrength1", std::shared_ptr<Attribute>(new Attribute(STRENGTH, 5)));
	attributesDatabase.emplace("mobIntellect1", std::shared_ptr<Attribute>(new Attribute(INTELLECT, 5)));
	attributesDatabase.emplace("mobArmor1", std::shared_ptr<Attribute>(new Attribute(ARMOR, 5)));

	//mob Lv2
	attributesDatabase.emplace("mobStrength2", std::shared_ptr<Attribute>(new Attribute(STRENGTH, 7)));
	attributesDatabase.emplace("mobIntellect2", std::shared_ptr<Attribute>(new Attribute(INTELLECT, 7)));
	attributesDatabase.emplace("mobArmor2", std::shared_ptr<Attribute>(new Attribute(ARMOR, 10)));
}

Item* GameManager::getItem(const std::string &itemName){
	return itemDatabase[itemName].get();
}

Attribute* GameManager::getAttribute(const std::string &attributeName){
	return attributesDatabase[attributeName].get();
}

std::string GameManager::getLocationName(unsigned int location){
	int i = 0;
	while (true)
	{
		if (locationDatabase[i] == ""){
			break;
		}
		i++;
	}
	if (location > i) return "out of range";
	else return locationDatabase[location];
}

std::string GameManager::getLocationDescription(unsigned int location){
	if (location >= locationsDescriptions.size()) return "out of range";
	return locationsDescriptions[location];
}

