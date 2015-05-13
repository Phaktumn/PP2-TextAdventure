#include "GameState.h"

GameState::GameState(sf::Font* font, InputBox* inputBox, StateManager* stateManager) : font(font), inputBox(inputBox), stateManager(stateManager) {
	
}

GameState::~GameState() {

}

void GameState::load() {

}

void GameState::update() {

	input = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
	if (input){
		if (inputBox->lastCommand() == "1")
			stateManager->changeState("BattleState");
	}
}

void GameState::draw(sf::RenderWindow* window) {
	State::draw(window);

	sf::String hello(SEPARATOR);
	
	sf::Text text;
	text.setFont(*font);
	text.setColor(sf::Color::White);
	text.setCharacterSize(24);
	text.setPosition(0, 0);

	text.setString(hello);
	window->draw(text);

	drawText(50, 25, "Welcome friend, your journey starts here!!", font, sf::Color::Red, 22);
	drawText(50, 50, "lets se...and if i say that this is not Complete yet.", font, sf::Color::Red, 22);
	drawText(50, 75, "DEVELOPING GG", font, sf::Color::Red, 22);

	text.setPosition(0, 300);
	window->draw(text);

	text.setPosition(0, WINDOW_HEIGHT - 50);
	window->draw(text);
}