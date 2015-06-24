#pragma once
#include "StateManager.h"
#include "GameManager.h"
#include "InputBox.h"
#include "Globals.h"

class PostBattleState : public State
{
public:
	PostBattleState(sf::Font& font, InputBox& inputBox, StateManager& state);
	~PostBattleState();

	void load() override;
	void update() override;
	void draw(sf::RenderWindow *window) override;

	bool auxloot, firstTime;

	bool getLoot();

	StateManager& state;
	sf::Font font;
	InputBox& inputBox;
};

