#include "GameStateMenu.h"


GameStateMenu::GameStateMenu(sf::Font& font, InputBox& inputBox)
{
	auxPaths = false;
	auxInv = false;
}


GameStateMenu::~GameStateMenu()
{
}

void GameStateMenu::drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window) {
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

void GameStateMenu::update(InputBox& inputBox, World* world)
{
	if (inputBox.lastCommand() == "> Inventory")
		auxInv = true;
	if (inputBox.lastCommand() == "> Quit")
		//fechar o jogo
	if (inputBox.lastCommand() == "> Paths")
		auxPaths = true;
	if (inputBox.lastCommand() == "> Back")
	{
		auxInv = false;
		auxPaths = false;
	}
	if (auxPaths == true ){
		for (size_t i = 0; i < world->getConnections().size(); i++)
		{
			if (inputBox.lastCommand() == world->getConnections()[i]->getName()){
				world->moveTo(world->getConnections()[i]->getName());
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
			drawText(15, 325 + i * 25, sfe::RichText(font) << std::to_string(i + 1) << ") " << world->getConnections()[i]->getName(), 24, window);
		}
		drawText(15, 400, "> Back", font, 24, window);
	}
	if (auxInv)
	{
		// MOSTRAR INVENTARIO!!!!!!!!!!
		drawText(15, 400, "> Back", font, 24, window);
	}
}