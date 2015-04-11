#define GAME_RUN(state) run(state);
#define GAME_STOP state = RUNNING;

#include "Log.h"
#include <SFML/Graphics.hpp>

enum GAME_STATE
{
	MAIN_MENU, IN_GAME_WORLD, IN_GAME_BATTLE
};

class Game
{
public:
	Game();
	~Game();

	void update();
	void draw();
	int run();

private:
	GAME_STATE state;
	sf::RenderWindow* window;
	Log* gameLog;
};