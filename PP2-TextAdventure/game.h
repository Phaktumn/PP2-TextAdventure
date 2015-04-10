#define GAME_RUN(state) run(state);
#define GAME_STOP state = RUNNING;

typedef enum STATE
{
	RUNNING, PAUSED, EXIT
} STATE;

class Game
{
public:
	Game();
	~Game();

	void update();
	void draw();
	int run(STATE initial_state);

private:
	STATE state;

};





