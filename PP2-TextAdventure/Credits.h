#pragma once
#include "StateManager.h"
#include "GameManager.h"
#include "InputBox.h"

class Credits : public State
{
public:
	Credits();
	~Credits();

	void load() override;
	void update() override;
	void draw(sf::RenderWindow *window) override;

	StateManager& state;
	sf::Font font;
	InputBox& inputBox;

	int auxpos;
};

