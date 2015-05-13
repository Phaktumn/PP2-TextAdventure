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

	void load() override;
	void update() override;
	void draw(sf::RenderWindow *window) override;

private:
	sf::Font* font;
};

