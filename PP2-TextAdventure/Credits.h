#pragma once
#include "StateManager.h"
#include "GameManager.h"
#include "InputBox.h"

class Credits : public State
{
public:
	Credits(sf::Font& font, InputBox& inputBox, StateManager& state);
	~Credits();

	void load() override;
	void update() override;
	void draw(sf::RenderWindow *window) override;

	StateManager& state;
	sf::Font font;
	InputBox& inputBox;

	sf::Clock clock;

	int auxpos;
};

