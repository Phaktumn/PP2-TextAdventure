#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "GameState.h"

class Game
{
public:
	Game();
	~Game();

	void update();
	void draw();
	int run();

private:
	sf::RenderWindow* window;
	StateManager stateManager;
};