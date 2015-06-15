#include "Game.h"
#include "Item.h"
#include "GameManager.h"
#include "TitleMenuState.h"
#include "BattleState.h"

Game::Game() {

}

Game::~Game() {
	
}

int Game::run() {
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Text Adventure", sf::Style::Titlebar);
	window->setFramerateLimit(120);

	sf::Font font;
	if (!font.loadFromFile("Munro.ttf")) {
		printf("Font failed to load.");
		return 0;
	}

	GameManager::loadItems("data");
	GameManager::loadGlobals();
	
	InputBox inputBox(5, WINDOW_HEIGHT - 20 - 5, &font, 20, sf::Color::White);

	GameState gameState(font, inputBox, stateManager);
	TitleMenuState titleMenuState(font, stateManager);
	BattleState battleState(font);

	stateManager.addState("GameState", &gameState);
	stateManager.addState("TitleMenuState", &titleMenuState);
	stateManager.addState("BattleState", &battleState);
	stateManager.loadState("TitleMenuState");
	stateManager.loadState("GameState");
	stateManager.loadState("BattleState");
	stateManager.changeState("TitleMenuState");

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}

			if (activeInput) inputBox.update(&event);
		}

		window->clear(sf::Color(0, 0, 0));

		update();
		draw();

		if(activeInput) inputBox.display(window);
		
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