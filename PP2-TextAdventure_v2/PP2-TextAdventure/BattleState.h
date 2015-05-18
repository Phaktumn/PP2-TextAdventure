#pragma once
#include "StateManager.h"
#include "Globals.h"

class BattleState : public State
{
public:
	BattleState(sf::Font* font);
	~BattleState();

	void load() override;
	void update() override;
	void draw(sf::RenderWindow *window) override;

private:
	sf::Font* font;
};

