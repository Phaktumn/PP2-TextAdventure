#include "GameState.h"

GameState::GameState(sf::Font& font, InputBox& inputBox, StateManager& stateManager) : font(font), inputBox(inputBox), stateManager(stateManager)
{
	
}

GameState::~GameState() {

}

void GameState::load() {

}

void GameState::update() {
	if (inputBox.lastCommand() == "1")
		stateManager.changeState("BattleState");
}

void GameState::draw(sf::RenderWindow* window)
{
	State::draw(window);
	drawText(0, 0, SEPARATOR, font, 24, window);
	drawText(0, 300, SEPARATOR, font, 24, window);
	drawText(0, WINDOW_HEIGHT - 50, SEPARATOR, font, 24, window);

	drawText(0, 100, sfe::RichText(font) << "This is white, this is " << sf::Color::Red << "red " << sf::Color::White << "and this is " << sf::Color::Green << "green" << sf::Color::White << ".", 24, window);
}