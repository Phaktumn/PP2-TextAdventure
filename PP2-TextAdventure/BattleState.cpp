#include "BattleState.h"


BattleState::BattleState(sf::Font& font, InputBox& inputBox, StateManager& state) 
: font(font), inputBox(inputBox), state(state)
{
	enemy = GameManager::getMob("mob1");
	playerPtr = GameManager::playerPtr;
	battleMenu = new BattleStateMenu(playerPtr, GameManager::getMob("mob1"), state);
}


BattleState::~BattleState()
{

}

void BattleState::load()
{

}

void BattleState::update()
{
	if (!enemy->isAlive()){
		LAST_ENEMY_LEVEL = enemy->getLevel();
		playerPtr->afterBattle(enemy->getLevel() * 100);
		state.changeState("PostBattleState");
	}
	else battleMenu->update(&inputBox, font);
}

void BattleState::draw(sf::RenderWindow* window)
{
	State::draw(window);
	drawText(0, 0, SEPARATOR, font, CHARACTER_SIZE, window);
	drawText(0, 300, SEPARATOR, font, CHARACTER_SIZE, window);
	drawText(0, WINDOW_HEIGHT - 50, SEPARATOR, font, CHARACTER_SIZE, window);

	battleMenu->draw(window, font);
}
