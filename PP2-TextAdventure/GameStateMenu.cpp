#include "GameStateMenu.h"
#include <typeinfo>

GameStateMenu::GameStateMenu(sf::Font& font, InputBox& inputBox, StateManager& stateManager, Player* _Player) : font(font), state(stateManager)
{
	auxPaths = false;
	auxInv = false;
	auxBag = false;
	eqp = false; 
	displayItem = false;
	item0 = false;
	item1 = false;
	item2 = false;
	item3 = false;
	item4 = false;
	item5 = false;
}

GameStateMenu::~GameStateMenu()
{
}

void GameStateMenu::drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window) 
{
	sf::Text _text;
	_text.setPosition(x, y);
	_text.setString(text);
	_text.setFont(font);
	_text.setCharacterSize(size);

	window->draw(_text);
}

void GameStateMenu::drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window)
{
	text.setPosition(x, y);
	text.setCharacterSize(size);

	window->draw(text);
}

void GameStateMenu::update(InputBox& inputBox, World* world, std::string command)
{
	if (auxMusic)
	{
		if (!music.openFromFile("songs/inGame.ogg")){ std::cout << "ERROR" << std::endl; } // error
		auxMusic = false;
		music.play();
	}
	_player.HP =  GameManager::playerPtr->getHp();
	_player.ARMOR = GameManager::playerPtr->getAttribute(ARMOR)->getValue() + GameManager::playerPtr->getAttribute(BONUS_ARMOR)->getValue();
	_player.STRENGTH = GameManager::playerPtr->getAttribute(STRENGTH)->getValue() + GameManager::playerPtr->getAttribute(BONUS_STRENGTH)->getValue();
	_player.INTELLECT = GameManager::playerPtr->getAttribute(INTELLECT)->getValue() + GameManager::playerPtr->getAttribute(BONUS_INTELLECT)->getValue();
	_player.LEVEL = GameManager::playerPtr->getLevel();
	_player.XP = GameManager::playerPtr->getXp();
	_player.TXP = GameManager::playerPtr->getTXp();

	if (command == "inventory") {
		auxInv = true;
		GameManager::playerPtr->update();
		GameManager::playerPtr->getInventory()->equipWeapon((Weapon*)GameManager::getItem(144));
		GameManager::playerPtr->getInventory()->equipArmor((Armor*)GameManager::getItem(12), GameManager::getItem(12)->type);
		GameManager::playerPtr->getInventory()->equipArmor((Armor*)GameManager::getItem(100), GameManager::getItem(100)->type);
		GameManager::playerPtr->getInventory()->equipArmor((Armor*)GameManager::getItem(80), GameManager::getItem(80)->type);
		GameManager::playerPtr->getInventory()->equipArmor((Armor*)GameManager::getItem(71), GameManager::getItem(71)->type);
		GameManager::playerPtr->getInventory()->equipArmor((Armor*)GameManager::getItem(119), GameManager::getItem(119)->type);

	}
	if (command == "quit") {
		music.stop();
		auxMusic = true;
		state.changeState("TitleMenuState");
		activeInput = false;
		item0 = false;
		item1 = false;
		item2 = false;
		item3 = false;
		item4 = false;
		item5 = false;
	}
	if (command == "paths") {
		auxPaths = true;
	}
	if (command == "bag"){
		auxBag = true;
		item0 = false;
		item1 = false;
		item2 = false;
		item3 = false;
		item4 = false;
		item5 = false;
	}
	if (command == "back") {
		auxInv = false;
		auxPaths = false;
		auxBag = false;
		displayItem = false;
		item0 = false;
		item1 = false;
		item2 = false;
		item3 = false;
		item4 = false;
		item5 = false;
	}
	if (auxInv){
		if (command == "0"){ 
			item0 = true;
			item1 = false;
			item2 = false;
			item3 = false;
			item4 = false;
			item5 = false;
		}
		if (command == "1"){ 
			item1 = true; 
			item0 = false;
			item2 = false;
			item3 = false;
			item4 = false;
			item5 = false;
		}
		if (command == "2"){ item2 = true;
		item0 = false;
		item1 = false;
		item3 = false;
		item4 = false;
		item5 = false;
		}
		if (command == "3"){ item3 = true;
		item0 = false;
		item1 = false;
		item2 = false;
		item4 = false;
		item5 = false;
		}
		if (command == "4"){ item4 = true;
		item0 = false;
		item1 = false;
		item2 = false;
		item3 = false;
		item5 = false;
		}
		if (command == "5"){ item5 = true;
		item0 = false;
		item1 = false;
		item2 = false;
		item3 = false;
		item4 = false;		
		}
	}
	if (auxPaths == true && command != "paths") {
		for (size_t i = 0; i < world->getConnections().size(); i++)
		{
			std::string nome = world->getConnections()[i]->getName();
			std::string transfomed = nome;
			std::transform(transfomed.begin(), transfomed.end(), transfomed.begin(), ::tolower);

			if (command == transfomed){
				world->moveTo(world->getConnections()[i]->getName());
				auxInv = false;
				auxPaths = false;
				srand(time(NULL));
				if (GameStateMenu::randomEncounter()){ 
					GameManager::playerPtr->goFullUpdate();
					music.stop();
					auxMusic = true;
					state.changeState("BattleState");
					ZONE_LEVEL = world->getLocation(nome)->getLocationLevel();
					GameManager::battleMenu = new BattleStateMenu(GameManager::playerPtr, GameManager::getRandMob(ZONE_LEVEL), state);
				}
			}
		}
	}
	if (auxBag)
	{
		for (size_t i = 0; i < _BAG_MAX_SLOTS; i++)
		{
			if (GameManager::playerPtr->getInventory()->getBag()[i] != nullptr)
			{
				std::string nome = GameManager::playerPtr->getInventory()->getBag()[i]->getName();
				std::string transfomed = nome;
				std::transform(transfomed.begin(), transfomed.end(), transfomed.begin(), ::tolower);
				if (command == transfomed)
				{		
					if (GameManager::playerPtr->getInventory()->getBag()[i]->weapon == GameManager::playerPtr->getInventory()->getBag()[i]->type){
						displayItem = true;
						GameManager::playerPtr->getInventory()->equipWeapon((Weapon*)GameManager::playerPtr->getInventory()->getBag()[i]);
						aux = GameManager::playerPtr->getInventory()->getBag()[i];
						GameManager::playerPtr->getInventory()->getBag().erase(i);
					}
					else{
						displayItem = true;
						GameManager::playerPtr->getInventory()->equipArmor((Armor*)GameManager::playerPtr->getInventory()->getBag()[i], GameManager::playerPtr->getInventory()->getBag()[i]->type);
						aux = GameManager::playerPtr->getInventory()->getBag()[i];
						GameManager::playerPtr->getInventory()->getBag().erase(i);
					}

					Inventory::getBag().removeAt(i);
				}
			}
		}
	}
	if (command == "battle")
		state.changeState("BattleState");
}


void GameStateMenu::draw(sf::RenderWindow* window, World* world)
{
	if (auxPaths == false && auxInv == false && !auxBag)
	{
		drawText(15, 325, "> Paths", font, 24, window);
		drawText(15, 350, "> Inventory", font, 24, window);
		drawText(15, 375, "> Bag", font, 24, window);
		drawText(15, 400, "> Quit", font, 24, window);

	}
	if (auxBag){
		GameManager::playerPtr->getInventory()->drawBag(window, font);
		drawText(15, 325, "-> Write down the name of the item you want to equip.", font, 24, window);
		drawText(15, 475, "> Back", font, 24, window);
		if (displayItem){
			sf::String auxInt = std::to_string(aux->getBonusIntellevt());
			sf::String auxStr = std::to_string(aux->getBonusStrenght());
			aux->draw(window, &font, 15, 350);
			drawText(15, 375, sfe::RichText(font) << aux->Description(), CHARACTER_SIZE, window);
			drawText(15, 425, sfe::RichText(font) << "Bonus Strength: " << sf::Color::Red << auxStr, CHARACTER_SIZE, window);
			drawText(15, 450, sfe::RichText(font) << "Bonus Intellect: " << sf::Color::Red << auxInt, CHARACTER_SIZE, window);
			if (aux->type == Item::Type::weapon){
				AuxWep = (Weapon*)aux;
				sf::String auxDmg = std::to_string(AuxWep->getWeaponDamage());
				drawText(15, 400, sfe::RichText(font) << "Damage: " << sf::Color::Red << auxDmg, CHARACTER_SIZE, window);
			}
			else{
				AuxArmor = (Armor*)aux;
				sf::String auxArmor = std::to_string(AuxArmor->getBonusArmor());
				drawText(15, 400, sfe::RichText(font) << "Armor: " << sf::Color::Red << auxArmor, CHARACTER_SIZE, window);
			}
		}
	}

	if (auxPaths)
	{
		for (int i = 0; i < world->getConnections().size(); i++){
			int j = i + 1;
			drawText(15, 325 + i * 25, sfe::RichText(font) << std::to_string(j) << ") " << world->getConnections()[i]->getName(), 24, window);
			drawText(300, 325 + i * 25, sfe::RichText(font) <<  sf::Color::Red  << " Level " << std::to_string(world->getConnections()[i]->getLocationLevel()), CHARACTER_SIZE, window);
		}
		drawText(15, 400, "> Back", font, 24, window);
	}

	if (auxInv)
	{
		if (item0){
			GameManager::playerPtr->getInventory()->drawEquipedItem(0, window, font);
		}
		if (item1){
			GameManager::playerPtr->getInventory()->drawEquipedItem(1, window, font);
		}
		if (item2){
			GameManager::playerPtr->getInventory()->drawEquipedItem(2, window, font);
		}
		if (item3){
			GameManager::playerPtr->getInventory()->drawEquipedItem(3, window, font);
		}
		if (item4){
			GameManager::playerPtr->getInventory()->drawEquipedItem(4, window, font);
		}
		if (item5){
			GameManager::playerPtr->getInventory()->drawEquipedItem(5, window, font);
		}
		drawText(30, 70 + 250, "ITEMS", font, CHARACTER_SIZE, window);

		GameManager::playerPtr->getInventory()->drawPos(window, font, 30, 345);

		drawText(425, 70 + 250, "ATRIBUTES", font, CHARACTER_SIZE, window);
		drawText(425, 70 + 275, sfe::RichText(font) << "Level: " << sf::Color::Red << std::to_string(_player.LEVEL), CHARACTER_SIZE, window);
		drawText(425, 70 + 300, sfe::RichText(font) << STRENGTH << ": " << sf::Color::Red << std::to_string(_player.STRENGTH), CHARACTER_SIZE, window);
		drawText(425, 70 + 325, sfe::RichText(font) << INTELLECT << ": " << sf::Color::Red << std::to_string(_player.INTELLECT), CHARACTER_SIZE, window);
		drawText(425, 70 + 350, sfe::RichText(font) << ARMOR << ": " << sf::Color::Red << std::to_string(_player.ARMOR), CHARACTER_SIZE, window);
		drawText(425, 70 + 375, sfe::RichText(font) << "HitPoints" << ": " << sf::Color::Red << std::to_string(_player.HP), CHARACTER_SIZE, window);

		drawText(700, 70 + 275, sfe::RichText(font) << "XP:  " << sf::Color::Red << std::to_string(_player.XP) << " (" << std::to_string(_player.TXP)<< ")", CHARACTER_SIZE, window);

		sf::String aux;
		aux = std::to_string(GameManager::playerPtr->getDamage());
		drawText(425, 70 + 400, sfe::RichText(font) << "Weapon Damage" << ": " << sf::Color::Red << aux, CHARACTER_SIZE, window);

		drawText(15, 475, "> Back", font, 24, window);
	}
	if (!auxInv && !auxBag && !auxPaths)
	{
		world->draw(window, font);
	}
}

bool GameStateMenu::randomEncounter()
{
	int aux;
	aux = rand() % 100;

	if (aux > 1) return true;
	else return false;
}