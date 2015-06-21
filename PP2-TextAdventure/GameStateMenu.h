#pragma once

#include <string>
#include "InputBox.h"
#include "World.h"

class GameStateMenu
{
public:
	GameStateMenu(sf::Font& font, InputBox& inputBox);
	~GameStateMenu();

	void update(InputBox& inputBox, World* world);
	void draw(sf::RenderWindow* window, World* world);
	void drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window);
	void drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window);

	bool auxPaths;
	bool auxInv;

private:
	sf::Font font;
};
