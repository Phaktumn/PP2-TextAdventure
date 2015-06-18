#pragma once
#include "State.h"
#include "game.h"
#include <string>
#include "Globals.h"
#include "InputBox.h"
#include "World.h"

class GameState : public State
{
public:
	GameState(sf::Font& font, InputBox& inputBox, StateManager& stateManager);
	~GameState();

	void load() override;
	void update() override;
	void draw(sf::RenderWindow* window) override;

private:
	sf::Font font;

	InputBox& inputBox;
	StateManager& stateManager;
	bool input = false;

	World world;
};

