#include "Game.h"

Game::Game() : gameLog(new Log())
{

}

Game::~Game()
{
	
}

int Game::run()
{
	window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Text Adventure");
	window->setFramerateLimit(120);
	state = MAIN_MENU;

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

}

void Game::draw()
{

}