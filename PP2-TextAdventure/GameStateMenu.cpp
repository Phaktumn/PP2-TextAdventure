#include "GameStateMenu.h"

GameStateMenu::GameStateMenu(sf::Font& font, InputBox& inputBox, StateManager& stateManager) : font(font), state(stateManager)
{
	auxPaths = false;
	auxInv = false;
	playerPtr = (Player*)player;
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
	_player.HP = player->getHp();
	_player.ARMOR = player->getAttribute(ARMOR)->getValue() + player->getAttribute(BONUS_ARMOR)->getValue();
	_player.STRENGTH = player->getAttribute(STRENGTH)->getValue() + player->getAttribute(BONUS_STRENGTH)->getValue();
	_player.INTELLECT = player->getAttribute(INTELLECT)->getValue() + player->getAttribute(BONUS_INTELLECT)->getValue();

	if (command == "1")
		state.changeState("BattleState");
	if (command == "inventory") {
		auxInv = true;
	}
	if (command == "quit") {
		//fechar o jogo
	}
	if (command == "paths") {
		auxPaths = true;
	}
	if (command == "back") {
		auxInv = false;
		auxPaths = false;
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
			}
		}
	}
}


void GameStateMenu::draw(sf::RenderWindow* window, World* world)
{
	if (auxPaths == false && auxInv == false)
	{
		drawText(15, 325, "> Paths", font, 24, window);
		drawText(15, 350, "> Inventory", font, 24, window);
		drawText(15, 375, "> Quit", font, 24, window);

	}

	if (auxPaths)

	{
		for (int i = 0; i < world->getConnections().size(); i++)
		{
			int j = i + 1;
			drawText(15, 325 + i * 25, sfe::RichText(font) << std::to_string(j) << ") " << world->getConnections()[i]->getName(), 24, window);
		}

		drawText(15, 400, "> Back", font, 24, window);
	}
	if (auxInv)
	{
		playerPtr->getInventory()->draw(window, font);

		drawText(BATTLE_PLAYER_NAME_POSITION_X + 300, BATTLE_PLAYER_NAME_POSITION_Y + 25, "ATRIBUTES", font, CHARACTER_SIZE, window);

		drawText(BATTLE_PLAYER_NAME_POSITION_X + 300, BATTLE_PLAYER_NAME_POSITION_Y + 50,
			sfe::RichText(font) << "Unleash the " << STRENGTH << ": " << sf::Color::Red << std::to_string(_player.STRENGTH), CHARACTER_SIZE, window);

		drawText(BATTLE_PLAYER_NAME_POSITION_X + 300, BATTLE_PLAYER_NAME_POSITION_Y + 75,
			sfe::RichText(font) << "Unleash the " << INTELLECT << ": " << sf::Color::Red << std::to_string(_player.INTELLECT), CHARACTER_SIZE, window);

		drawText(BATTLE_PLAYER_NAME_POSITION_X + 300, BATTLE_PLAYER_NAME_POSITION_Y + 100,
			sfe::RichText(font) << "Unleash the " << ARMOR << ": " << sf::Color::Red << std::to_string(_player.ARMOR), CHARACTER_SIZE, window);

		drawText(BATTLE_PLAYER_NAME_POSITION_X + 300, BATTLE_PLAYER_NAME_POSITION_Y + 125,
			sfe::RichText(font) << "Unleash the HitPoints" << ": " << sf::Color::Red << std::to_string(_player.HP), CHARACTER_SIZE, window);

		drawText(15, 400, "> Back", font, 24, window);
	}
}