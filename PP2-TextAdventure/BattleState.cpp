#include "BattleState.h"


BattleState::BattleState(sf::Font& font, InputBox& inputBox, StateManager& state) 
: font(font), inputBox(inputBox), state(state)
{

}


BattleState::~BattleState()
{

}

void BattleState::load()
{

}

void BattleState::update()
{
	GameManager::battleMenu->update(&inputBox, font);
}

void BattleState::draw(sf::RenderWindow* window)
{
	State::draw(window);
	drawText(0, 0, SEPARATOR, font, CHARACTER_SIZE, window);
	drawText(0, 300, SEPARATOR, font, CHARACTER_SIZE, window);
	drawText(0, WINDOW_HEIGHT - 50, SEPARATOR, font, CHARACTER_SIZE, window);

	GameManager::battleMenu->draw(window, font);
}
