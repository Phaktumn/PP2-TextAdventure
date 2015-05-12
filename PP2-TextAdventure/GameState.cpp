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

	//teste------------------------------------------------------------------------------------------------------------------------
	//eu tava a tentar usar um for assim:
	/*for (size_t i = 0; i < options.size(); i++)
	{
		drawText(25, 300 * i + 25, ("{0} {1}", i,  getOption(i)), font, sf::Color::White, 22);
	}*/
	//mas parece que tipo nao podes usar int...logo tens de converter! hmm! e depois as chavetas tbem nao funcionam!
	//nao encontro na net cenas que ajudem!
	drawText(25, 325, "0-> " + getOption(0), font, sf::Color::White, 22);
	drawText(25, 350, "1-> " + getOption(1), font, sf::Color::White, 22);
	//teste
	//teste------------------------------------------------------------------------------------------------------------------------
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