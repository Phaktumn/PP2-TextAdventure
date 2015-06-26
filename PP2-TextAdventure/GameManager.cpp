#include "GameManager.h"
#include "Globals.h"


std::map<int, std::shared_ptr<Item>> GameManager::itemDatabase;

std::map<std::string, sf::Text> drawnText;
std::map<std::string, std::shared_ptr<Attribute>> GameManager::attributesDatabase;

std::map<int, std::shared_ptr<Actor>> GameManager::mobsDatabase;
std::map<int, std::string> GameManager::auxMobNAMES;

std::map<int, std::string> GameManager::locationDatabase;
std::map<int, std::string> GameManager::locationsDescriptions;
std::map<int, int> GameManager::locationsLevels;

LinkedList<Attribute*> GameManager::attribute;
LinkedList<Ability*> GameManager::abilities;

LinkedList<Attribute*> GameManager::mob_1_Attributes;
LinkedList<Attribute*> GameManager::mob_2_Attributes;
LinkedList<Attribute*> GameManager::mob_3_Attributes;

Actor* GameManager::player;
Player* GameManager::playerPtr;
BattleStateMenu* GameManager::battleMenu;

int GameManager::global_Counter = 0;

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
	abilities.add(new DamageAbility("Auto Attack", Ability::NORESOURCE, 0, 30, DamageAbility::strength, 1.0f));
	abilities.add(new DamageAbility("Alpha Strike", Ability::RAGE, 100, 50, DamageAbility::strength, 3.0f));
	abilities.add(new DamageAbility("Death Strike", Ability::RAGE, 175, 75, DamageAbility::strength, 1.2f));
	abilities.add(new DamageAbility("Master Plan", Ability::RAGE, 200, 100, DamageAbility::strength, 1.5f));
	abilities.add(new DamageAbility("Darkness", Ability::RAGE, 300, 150, DamageAbility::strength, 2.5f));
	//=================================================================================================
	
	//ABILITIES MAGE================================================================================

	//==============================================================================================

	//PLAYER=========================================================================================
	player = new Player("jorge", GameManager::attribute, GameManager::abilities, WARRIOR_BASE_HP, 500, 1, 1000, 500, WARRIOR_BASE_HP);
	playerPtr = (Player*)player;
	//===============================================================================================

	//AIDS THE MOBS TO A MOB DATABASE
	//ACCESS TO THE DATABASE IS STATIC PUBLIC
	addMobs();
}

void GameManager::addMobs()
{
	//Attributes MOBLv1
	mob_1_Attributes.add(GameManager::getAttribute("mobStrength1"));
	mob_1_Attributes.add(GameManager::getAttribute("mobIntellect1"));
	mob_1_Attributes.add(GameManager::getAttribute("mobArmor1"));
	//ABILITIES MOBLv1
	//

	//Attributes MOBLv2
	mob_2_Attributes.add(GameManager::getAttribute("mobStrength2"));
	mob_2_Attributes.add(GameManager::getAttribute("mobIntellect2"));
	mob_2_Attributes.add(GameManager::getAttribute("mobArmor2"));
	//
	//Attributes MOBLv3
	mob_3_Attributes.add(GameManager::getAttribute("mobStrength3"));
	mob_3_Attributes.add(GameManager::getAttribute("mobIntellect3"));
	mob_3_Attributes.add(GameManager::getAttribute("mobArmor3"));
	//
	//Attributes MOBLv4

	//



	//MOBS LV1
	mobsDatabase.emplace(0, std::shared_ptr<Actor>(new Actor("::Genesis::", GameManager::mob_1_Attributes, GameManager::abilities, 350, 150, 1, 350, 150, 350)));
	mobsDatabase.emplace(1, std::shared_ptr<Actor>(new Actor("::Dark Bulb::", GameManager::mob_1_Attributes, GameManager::abilities, 350, 150, 1, 350, 150, 350)));
	mobsDatabase.emplace(2, std::shared_ptr<Actor>(new Actor("::Dark Worshipper::", GameManager::mob_1_Attributes, GameManager::abilities, 350, 150, 1, 350, 150, 350)));
	mobsDatabase.emplace(3, std::shared_ptr<Actor>(new Actor("::Forest Ogre::", GameManager::mob_1_Attributes, GameManager::abilities, 350, 150, 1, 350, 150, 350)));
	mobsDatabase.emplace(4, std::shared_ptr<Actor>(new Actor("::Mummy::", GameManager::mob_1_Attributes, GameManager::abilities, 350, 150, 1, 350, 150, 350)));

	//MOBS LV2
	//                                                                                                                             hp, mana, level, basemaxhp, maResource, )));
	mobsDatabase.emplace(5, std::shared_ptr<Actor>(new Actor("||Soul eater||", GameManager::mob_2_Attributes, GameManager::abilities, 525, 600, 2, 525, 600, 525)));
	mobsDatabase.emplace(6, std::shared_ptr<Actor>(new Actor("||Mutated Grub||", GameManager::mob_2_Attributes, GameManager::abilities, 600, 600, 2, 525, 600, 600)));
	mobsDatabase.emplace(7, std::shared_ptr<Actor>(new Actor("||Mad Scientist||", GameManager::mob_2_Attributes, GameManager::abilities, 500, 600, 2, 600, 525, 525)));
	mobsDatabase.emplace(8, std::shared_ptr<Actor>(new Actor("||Tomb Horror||", GameManager::mob_2_Attributes, GameManager::abilities, 550, 600, 2, 525, 600, 525)));
	mobsDatabase.emplace(9, std::shared_ptr<Actor>(new Actor("||Necro Knight||", GameManager::mob_2_Attributes, GameManager::abilities, 525, 600, 2, 600, 525, 525)));

	//MOBS LV3
	mobsDatabase.emplace(10, std::shared_ptr<Actor>(new Actor("@Ghostwing@", GameManager::mob_3_Attributes, GameManager::abilities, 730, 600, 3, 750, 600, 730)));
	mobsDatabase.emplace(11, std::shared_ptr<Actor>(new Actor("@Bone Giant@", GameManager::mob_3_Attributes, GameManager::abilities, 730, 600, 3, 750, 600, 730)));
	mobsDatabase.emplace(12, std::shared_ptr<Actor>(new Actor("@Carnage@", GameManager::mob_3_Attributes, GameManager::abilities, 730, 600, 3, 750, 600, 730)));
	mobsDatabase.emplace(13, std::shared_ptr<Actor>(new Actor("@Animated Laborer@", GameManager::mob_3_Attributes, GameManager::abilities, 730, 600, 3, 750, 600, 730)));
	mobsDatabase.emplace(14, std::shared_ptr<Actor>(new Actor("@Boneguard Scout@", GameManager::mob_3_Attributes, GameManager::abilities, 730, 600, 3, 750, 600, 730)));

	//MOBS LV4
	mobsDatabase.emplace(15, std::shared_ptr<Actor>(new Actor("*High Warlord*", GameManager::mob_3_Attributes, GameManager::abilities, 1000, 800, 4, 1100, 800, 1000)));
	mobsDatabase.emplace(16, std::shared_ptr<Actor>(new Actor("*Shadow Demon*", GameManager::mob_3_Attributes, GameManager::abilities, 1000, 800, 4, 1100, 800, 1000)));
	mobsDatabase.emplace(17, std::shared_ptr<Actor>(new Actor("*Sister of Pain*", GameManager::mob_3_Attributes, GameManager::abilities, 1000, 800, 4, 1100, 800, 1000)));
	mobsDatabase.emplace(18, std::shared_ptr<Actor>(new Actor("*Sister of pleasure*", GameManager::mob_3_Attributes, GameManager::abilities, 1000, 800, 4, 1100, 800, 1000)));
	mobsDatabase.emplace(19, std::shared_ptr<Actor>(new Actor("*Aqueous Lord*", GameManager::mob_3_Attributes, GameManager::abilities, 1000, 800, 4, 1100, 800, 1000)));

	//MOBS LV5
	mobsDatabase.emplace(20, std::shared_ptr<Actor>(new Actor(">>Illidan Stormrage<<", GameManager::mob_3_Attributes, GameManager::abilities, 1200, 900, 5, 1300, 950, 1200)));
	mobsDatabase.emplace(21, std::shared_ptr<Actor>(new Actor(">>Tirion Fordring<<", GameManager::mob_3_Attributes, GameManager::abilities, 1200, 900, 5, 1300, 950, 1200)));
	mobsDatabase.emplace(22, std::shared_ptr<Actor>(new Actor(">>Muradin Bronzebeard<<", GameManager::mob_3_Attributes, GameManager::abilities, 1200, 900, 5, 1300, 950, 1200)));
	mobsDatabase.emplace(23, std::shared_ptr<Actor>(new Actor(">>Kil'jaeden<<", GameManager::mob_3_Attributes, GameManager::abilities, 1200, 900, 5, 1300, 950, 1200)));
	mobsDatabase.emplace(24, std::shared_ptr<Actor>(new Actor(">>Lady Vash<<", GameManager::mob_3_Attributes, GameManager::abilities, 1200, 900, 5, 1300, 950, 1200)));

	for (size_t i = 0; i < mobsDatabase.size(); i++){
		mobsDatabase[i].get()->goFullUpdate();
	}
}

void GameManager::reloadMOBS(){
	for (size_t i = 0; i < mobsDatabase.size(); i++){
		mobsDatabase[i].get()->goFullUpdate();
	}
}

Actor* GameManager::getRandMob(const int level){
	srand(time(NULL));
	auxMobNAMES.clear();
	int aux;
	int AUX_CONT = 0;

	for (int i = 0; i < mobsDatabase.size(); i++)
	{
		if (mobsDatabase[i].get()->getLevel() == level){
			auxMobNAMES.emplace(AUX_CONT, getMob(i)->getActorName());
			AUX_CONT++;
		}
	}
	if (auxMobNAMES.size() != 0)
		aux = rand() % auxMobNAMES.size();
	for (int i = 0; i < mobsDatabase.size(); i++)
	{
		if (mobsDatabase[i].get()->getActorName() == auxMobNAMES[aux])
			return mobsDatabase[i].get();
	}
}

Actor* GameManager::getMob(const int code){
	return mobsDatabase[code].get();
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
			global_Counter++;
			itemDatabase.emplace(global_Counter, std::shared_ptr<Item>(new Armor(sf::String(qualityString), sf::String(name), type, bonusStr, bonusInt, bonusArmor)));
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
			global_Counter++;
			itemDatabase.emplace(global_Counter, std::shared_ptr<Item>(new Armor(sf::String(qualityString), sf::String(name), type, bonusStr, bonusInt, bonusArmor)));
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
			global_Counter++;
			itemDatabase.emplace(global_Counter, std::shared_ptr<Item>(new Weapon(sf::String(qualityString), sf::String(name), type, baseStr, baseInt, damage)));
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
			int zoneLevel = locationObj["Level"].as<int>();

			locationDatabase.emplace(i, name);
			locationsDescriptions.emplace(i, description);
			locationsLevels.emplace(i, zoneLevel);
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
	attributesDatabase.emplace("mobStrength2", std::shared_ptr<Attribute>(new Attribute(STRENGTH, 10)));
	attributesDatabase.emplace("mobIntellect2", std::shared_ptr<Attribute>(new Attribute(INTELLECT, 10)));
	attributesDatabase.emplace("mobArmor2", std::shared_ptr<Attribute>(new Attribute(ARMOR, 25)));

	//mob lv3
	attributesDatabase.emplace("mobStrength3", std::shared_ptr<Attribute>(new Attribute(STRENGTH, 25)));
	attributesDatabase.emplace("mobIntellect3", std::shared_ptr<Attribute>(new Attribute(INTELLECT, 20)));
	attributesDatabase.emplace("mobArmor3", std::shared_ptr<Attribute>(new Attribute(ARMOR, 50)));
}

Item* GameManager::getItem(const int key){
	return itemDatabase[key].get();
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

int GameManager::getLocationLevel(unsigned int location){
	return locationsLevels[location];
}

