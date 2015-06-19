#pragma once
#include "StateManager.h"
#include "Globals.h"
#include "Player.h"
#include "Actor.h"
#include "InputBox.h"

class BattleState : public State
{
public:
	BattleState(sf::Font& font, InputBox& inputBox);
	~BattleState();

	void load() override;
	void update() override;
	void draw(sf::RenderWindow *window) override;

private:
	Actor* player;

	InputBox& inputBox;

	sf::Font font;
};

