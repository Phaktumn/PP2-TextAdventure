#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
	
}

int Game::run()
{
	window = new sf::RenderWindow(sf::VideoMode(960, 540), "Text Adventure", sf::Style::Titlebar);
	window->setFramerateLimit(120);

	stateManager.addState("GameState", new GameState());
	stateManager.loadState("GameState");
	stateManager.changeState("GameState");

	while (window->isOpen()) {
		window->clear(sf::Color(0, 0, 0));

		update();
		draw();

		window->display();

		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window->close();
		}
	}
	return 1;
}

void Game::update()
{
	stateManager.update();
}

void Game::draw()
{
	stateManager.draw(window);
}