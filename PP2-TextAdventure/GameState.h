#pragma once
#include "State.h"
#include "game.h"
#include <string>
#include "Globals.h"

class GameState : public State
{
public:
	GameState(sf::Font* font);
	~GameState();

	void load();
	void update();
	void draw(sf::RenderWindow *window);

private:
	sf::Font* font;
};

