#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "GameState.h"
#include "InputBox.h"

class Game
{
public:
	const int WINDOW_WIDTH = 960;
	const int WINDOW_HEIGHT = 540;
	const char* SEPARATOR = "+----------------------------------------------+";

	Game();
	~Game();

	void update();
	void draw();
	int run();

private:
	sf::RenderWindow* window;
	StateManager stateManager;
};