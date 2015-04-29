#define GAME_RUN(state) run(state);
#define GAME_STOP state = RUNNING;

#include <SFML/Graphics.hpp>

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
};