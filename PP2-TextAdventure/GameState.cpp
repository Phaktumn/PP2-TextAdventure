#include "GameState.h"

GameState::GameState(sf::Font* font) : font(font) {
	
}

GameState::~GameState() {

}

void GameState::load() {
	drawText(200, 200, "Armor de Teste", font, sf::Color::Red, 24);
}

void GameState::update() {
	
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

	text.setPosition(0, WINDOW_HEIGHT - 50);
	window->draw(text);

	text.setPosition(0, 300);
	window->draw(text);
}