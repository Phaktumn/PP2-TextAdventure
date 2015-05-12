#include "GameState.h"

GameState::GameState(sf::Font* font) : font(font) {
	
}

GameState::~GameState() {

}

void GameState::load() {
	//teste------------------------------------------------------------------------------------------------------------------------
	addOptions(0, "Start");
	addOptions(1, "Exit");
	//teste------------------------------------------------------------------------------------------------------------------------

	drawText(50, 25, "Welcome friend, your journey starts here!!", font, sf::Color::Red, 22);
	drawText(50, 50, "lets se...and if i say that this is not Complete yet.", font, sf::Color::Red, 22);
	drawText(50, 75, "DEVELOPING GG", font, sf::Color::Red, 22);

	for (size_t i = 0; i < options.size(); i++)
	{
		std::string s = to_string(i + 1);
		drawText(25, 325 + i * 25, s + "> " +getOption(i), font, sf::Color::White, 22);
	}
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