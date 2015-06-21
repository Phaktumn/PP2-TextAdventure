#pragma once

#include "State.h"
#include "StateManager.h"
#include <string>
#include "Globals.h"
#include "GameStateMenu.h"
#include "InputBox.h"
#include "World.h"
#include "LocationsManager.h"


class GameState : public State
{
public:
	GameState(sf::Font& font, InputBox& inputBox, StateManager& stateManager);
	~GameState();

	virtual void load() override;
	virtual void update() override;
	virtual void draw(sf::RenderWindow* window) override;

protected:
	sf::Font font;

	GameStateMenu* menu;

	std::map<int, sf::String> options;
	InputBox& inputBox;
	StateManager& stateManager;
	bool input = false;

	void processCommands(const std::string& command);

	World world;

private:

};

