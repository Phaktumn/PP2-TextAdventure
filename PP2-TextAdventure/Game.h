#pragma once
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "GameState.h"
#include "InputBox.h"
#include "Globals.h"
#include "GameManager.h"
#include "LocationsManager.h"

class Game
{
public:
	Game();
	~Game();

	void update();
	void draw();
	int run();

private:
	sf::RenderWindow* window;
	StateManager stateManager;
};