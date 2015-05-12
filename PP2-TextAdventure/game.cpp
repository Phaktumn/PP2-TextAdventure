#include "Game.h"
#include "Item.h"
#include "GameManager.h"

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

	stateManager.addState("GameState", new GameState(&font));
	stateManager.loadState("GameState");
	stateManager.changeState("GameState");

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}

			inputBox.update(&event);
		}

		window->clear(sf::Color(0, 0, 0));

<<<<<<< HEAD
=======
		GameManager::getItem("Armor de Teste")->draw(window, &font, 100, 100);
		GameManager::getItem("Weapon de Teste")->draw(window, &font, 100, 125);
		GameManager::getItem("Holy Cleaver")->draw(window, &font, 100, 150);
		GameManager::getItem("Black Cleaver")->draw(window, &font, 100, 175);
		GameManager::getItem("Redemption")->draw(window, &font, 100, 200);
		GameManager::getItem("Your MOM tho!")->draw(window, &font, 100, 225);

>>>>>>> origin/master
		update();
		draw();

		inputBox.display(window);
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