#include "GameStateMenu.h"

GameStateMenu::GameStateMenu(sf::Font& font, InputBox& inputBox, StateManager& stateManager, Player* _Player) : font(font), state(stateManager)
{
	auxPaths = false;
	auxInv = false;
	auxBag = false;
	eqp = false;
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
	_player.HP =  GameManager::playerPtr->getHp();
	_player.ARMOR = GameManager::playerPtr->getAttribute(ARMOR)->getValue() + GameManager::playerPtr->getAttribute(BONUS_ARMOR)->getValue();
	_player.STRENGTH = GameManager::playerPtr->getAttribute(STRENGTH)->getValue() + GameManager::playerPtr->getAttribute(BONUS_STRENGTH)->getValue();
	_player.INTELLECT = GameManager::playerPtr->getAttribute(INTELLECT)->getValue() + GameManager::playerPtr->getAttribute(BONUS_INTELLECT)->getValue();
	_player.LEVEL = GameManager::playerPtr->getLevel();
	_player.XP = GameManager::playerPtr->getXp();
	_player.TXP = GameManager::playerPtr->getTXp();

	if (command == "inventory") {
		auxInv = true;
	}
	if (command == "quit") {
		state.changeState("TitleMenuState");
		activeInput = false;
	}
	if (command == "paths") {
		auxPaths = true;
	}
	if (command == "bag"){
		auxBag = true;
	}
	if (command == "back") {
		auxInv = false;
		auxPaths = false;
		auxBag = false;
	}
	if (command == "equip" && !eqp)
	{
		GameManager::playerPtr->getInventory()->equipWeapon((Weapon*)GameManager::getItem("Rusted Sword"));
		GameManager::playerPtr->getInventory()->equipArmor((Armor*)GameManager::getItem("GreatHelm"), GameManager::getItem("GreatHelm")->type);
		GameManager::playerPtr->getInventory()->equipArmor((Armor*)GameManager::getItem("Tyrant's Greaves"), GameManager::getItem("Tyrant's Greaves")->type);
		GameManager::playerPtr->getInventory()->equipArmor((Armor*)GameManager::getItem("Amberplate Grips"), GameManager::getItem("Amberplate Grips")->type);
		GameManager::playerPtr->getInventory()->equipArmor((Armor*)GameManager::getItem("Ravager's Armor"), GameManager::getItem("Ravager's Armor")->type);
		GameManager::playerPtr->getInventory()->equipArmor((Armor*)GameManager::getItem("Plate Legguards"), GameManager::getItem("Plate Legguards")->type);
		eqp = true;
	}
	if (auxPaths == true && command != "paths") {
		for (size_t i = 0; i < world->getConnections().size(); i++)
		{
			std::string nome = world->getConnections()[i]->getName();
			std::transform(nome.begin(), nome.end(), nome.begin(), ::tolower);

			if (command == nome) {
				world->moveTo(world->getConnections()[i]->getName());
				auxInv = false;
				auxPaths = false;
				if (GameStateMenu::randomEncounter()) state.changeState("BattleState");
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
		drawText(15, 375, "> Bags", font, 24, window);
		drawText(15, 400, "> Quit", font, 24, window);

	}
	if (auxBag){
		GameManager::playerPtr->getInventory()->drawBag(window, font);
	}

	if (auxPaths)
	{
		for (int i = 0; i < world->getConnections().size(); i++){
			int j = i + 1;
			drawText(15, 325 + i * 25, sfe::RichText(font) << std::to_string(j) << ") " << world->getConnections()[i]->getName(), 24, window);
		}
		drawText(15, 400, "> Back", font, 24, window);
	}

	if (auxInv)
	{
		drawText(30, 70 + 250, "ITEMS", font, CHARACTER_SIZE, window);

		GameManager::playerPtr->getInventory()->drawPos(window, font, 30, 345);

		drawText(425, 70 + 250, "ATRIBUTES", font, CHARACTER_SIZE, window);
		drawText(425, 70 + 275, sfe::RichText(font) << "Level: " << sf::Color::Red << std::to_string(_player.LEVEL), CHARACTER_SIZE, window);
		drawText(425, 70 + 300, sfe::RichText(font)  << STRENGTH << ": " << sf::Color::Red << std::to_string(_player.STRENGTH), CHARACTER_SIZE, window);
		drawText(425, 70 + 325, sfe::RichText(font)  << INTELLECT << ": " << sf::Color::Red << std::to_string(_player.INTELLECT), CHARACTER_SIZE, window);
		drawText(425, 70 + 350, sfe::RichText(font)  << ARMOR << ": " << sf::Color::Red << std::to_string(_player.ARMOR), CHARACTER_SIZE, window);
		drawText(425, 70 + 375, sfe::RichText(font) << "HitPoints" << ": " << sf::Color::Red << std::to_string(_player.HP), CHARACTER_SIZE, window);

		drawText(700, 70 + 275, sfe::RichText(font) << "XP:  " << sf::Color::Red << std::to_string(_player.XP) << " (" << std::to_string(_player.TXP)<< ")", CHARACTER_SIZE, window);

		sf::String aux;
		aux = std::to_string(GameManager::playerPtr->getDamage());
		drawText(425, 70 + 400, sfe::RichText(font) << "Weapon Damage" << ": " << sf::Color::Red << aux, CHARACTER_SIZE, window);

		drawText(15, 475, "> Back", font, 24, window);
	}
	if (!auxInv && !auxBag && !auxPaths)
		world->draw(window);
}

bool GameStateMenu::randomEncounter()
{
	int aux;
	aux = rand() % 100;

	if (aux > 50) return true;
	else return false;
}