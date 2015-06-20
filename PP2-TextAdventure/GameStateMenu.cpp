#include "GameStateMenu.h"


GameStateMenu::GameStateMenu(sf::Font& font, InputBox& inputBox)
{
	auxOptions = false;
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
	if (inputBox.lastCommand() == "> Paths")
		auxOptions = false;
	if (inputBox.lastCommand() == "> Back")
		auxOptions = true;

}


void GameStateMenu::draw(sf::RenderWindow* window, World* world)
{
	if (auxOptions)
	{
		drawText(15, 325, "> Paths", font, 24, window);
		drawText(15, 350, "> Inventory", font, 24, window);
		drawText(15, 375, "> Quit", font, 24, window);
	}
	if (auxOptions == false)
	{
		for (int i = 0; i < world->getConnections().size(); i++)
		{
			drawText(15, 325 + i * 25, sfe::RichText(font) << std::to_string(i + 1) << ") " << world->getConnections()[i]->getName(), 24, window);
		}
		drawText(15, 400, "> Back", font, 24, window);
	}
}