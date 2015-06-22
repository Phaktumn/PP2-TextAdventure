#include "GameStateMenu.h"

GameStateMenu::GameStateMenu(sf::Font& font, InputBox& inputBox, StateManager& stateManager) : font(font), state(stateManager)
{
	auxPaths = false;
	auxInv = false;
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
		// MOSTRAR INVENTARIO!!!!!!!!!!
		drawText(15, 400, "> Back", font, 24, window);
	}
}