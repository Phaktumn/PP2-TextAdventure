#include "BattleState.h"


BattleState::BattleState(sf::Font& font, InputBox& inputBox) : font(font), inputBox(inputBox)
{
	battleMenu = new BattleStateMenu(GameManager::playerPtr, shit);
}


BattleState::~BattleState()
{

}

void BattleState::load()
{
	playerPtr = GameManager::playerPtr;
}

void BattleState::update()
{
	battleMenu->update(&inputBox);
}

void BattleState::draw(sf::RenderWindow* window)
{
	State::draw(window);
	drawText(0, 0, SEPARATOR, font, CHARACTER_SIZE, window);
	drawText(0, 300, SEPARATOR, font, CHARACTER_SIZE, window);
	drawText(0, WINDOW_HEIGHT - 50, SEPARATOR, font, CHARACTER_SIZE, window);

	battleMenu->draw(window, font);
}
