#include "Game.h"

Game::Game() {

}

Game::~Game() {
	
}

int Game::run() {
	window = new sf::RenderWindow(sf::VideoMode(960, 540), "Text Adventure", sf::Style::Titlebar);
	window->setFramerateLimit(120);

	stateManager.addState("GameState", new GameState());
	stateManager.loadState("GameState");
	stateManager.changeState("GameState");

	sf::Font font;
	font.loadFromFile("Munro.ttf");

	std::string s;
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setColor(sf::Color::White);

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}

			if (event.type == sf::Event::TextEntered) {
				if (event.KeyPressed == sf::Keyboard::BackSpace && s.size() != 0) {
					s.pop_back();
				}
				else if (event.text.unicode < 128) {
					s += static_cast<char>(event.text.unicode);
					text.setString(s);
				}
			}
		}

		window->clear(sf::Color(0, 0, 0));

		update();
		draw();

		window->draw(text);
		window->display();
	}

	return 1;
}

void Game::update() {
	stateManager.update();
}

void Game::draw() {
	stateManager.draw(window);
}