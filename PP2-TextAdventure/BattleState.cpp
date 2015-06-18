#include "BattleState.h"


BattleState::BattleState(sf::Font& font) : font(font)
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

}

void BattleState::draw(sf::RenderWindow* window)
{
	State::draw(window);
	drawText(0, 0, SEPARATOR, font, 24, window);
	drawText(0, 300, SEPARATOR, font, 24, window);
	drawText(0, WINDOW_HEIGHT - 50, SEPARATOR, font, 24, window);
	drawText(15, 15, "HI GUYS BATTLE STATE",font, 24, window);
}
