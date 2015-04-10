#include "Game.h"

<<<<<<< HEAD
Game::Game()
{
}

Game::~Game()
{
}

int Game::run(STATE initial_state)
=======
int run(int initial_state)
>>>>>>> origin/master
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