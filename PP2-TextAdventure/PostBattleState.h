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
	
	struct HELPERS
	{
		int LEVEL;
		int XP;
		int TXP;
	}_player;

	sf::Clock clock;

	bool getloot();

	StateManager& state;
	sf::Font font;
	InputBox& inputBox;
};

