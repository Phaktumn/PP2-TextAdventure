#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

int Game::run(STATE initial_state)
{
	while (state != EXIT) {
		update();
		draw();
	}

	return 1;
}

void Game::update()
{

}

void Game::draw()
{

}