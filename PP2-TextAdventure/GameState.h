#pragma once
#include "State.h"
#include <string>

class GameState : public State
{
public:
	GameState();
	~GameState();

	void load();
	void update();
	void draw(sf::RenderWindow *window);

private:
	
};

