#pragma once

#include <string>
#include "InputBox.h"
#include "World.h"
#include "StateManager.h"
#include "Actor.h"
#include "Player.h"

class GameStateMenu
{
public:
	GameStateMenu(sf::Font& font, InputBox& inputBox, StateManager& stateManager);
	~GameStateMenu();

	void update(InputBox& inputBox, World* world, std::string command);
	void draw(sf::RenderWindow* window, World* world);
	void drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window);
	void drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window);

	bool auxPaths;
	bool auxInv;

	Player* playerPtr;
	Actor* player;

	struct HELPERS
	{
		int HP;
		int STRENGTH;
		int ARMOR;
		int INTELLECT;
	}_player;


private:
	sf::Font font;

	StateManager& state;
};
