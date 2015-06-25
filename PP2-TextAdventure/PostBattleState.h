#pragma once
#include "StateManager.h"
#include "GameManager.h"
#include "InputBox.h"
#include "Globals.h"
#include <SFML/Audio.hpp>

class PostBattleState : public State
{
public:	
	PostBattleState(sf::Font& font, InputBox& inputBox, StateManager& state);
	~PostBattleState();

	void load() override;
	void update() override;
	void draw(sf::RenderWindow *window) override;

	bool auxloot, firstTime;

	sf::Music music;

	bool auxMusic = true;
	
	struct HELPERS
	{
		int LEVEL;
		int XP;
		int TXP;
	}_player;

	sf::Clock clock;

	//gets the drop
	void getDrop();
	//generate a random number to drop
	int genRand();
	//calculate if get drop or not!
	bool CALCgetloot();
	bool droped;

	Item* dropedItem;

	StateManager& state;
	sf::Font font;
	InputBox& inputBox;
};

