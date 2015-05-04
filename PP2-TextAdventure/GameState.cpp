#include "GameState.h"

GameState::GameState(sf::Font* font) : font(font) {
	
}

GameState::~GameState() {

}

void GameState::load() {
	
}

void GameState::update() {
	
}

void GameState::draw(sf::RenderWindow* window) {
	sf::String(SEPARATOR);
	sf::Text text;
	text.setFont(*font);
	text.setColor(sf::Color::Red);
	text.setPosition(0, 0);

	window->draw(text);
}