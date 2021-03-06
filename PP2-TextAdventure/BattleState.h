#pragma once
#include "StateManager.h"
#include "Globals.h"
#include "Actor.h"
#include "InputBox.h"
#include "BattleStateMenu.h"
#include "GameManager.h"
#include "Actor.h"

class BattleState : public State
{
public:
	BattleState(sf::Font& font, InputBox& inputBox, StateManager& state);
	~BattleState();

	void load() override;
	void update() override;
	void draw(sf::RenderWindow *window) override;

private:
	InputBox& inputBox;
	sf::Font font;

	StateManager& state;

	Actor* player;
	Player* playerPtr;
	Actor* enemy;
};

