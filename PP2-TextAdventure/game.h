#define GAME_RUN(state) run(state);
#define GAME_STOP state = RUNNING;

enum GAME_STATE
{
	RUNNING, PAUSED, EXIT
};

<<<<<<< HEAD
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





=======
int state;
void update();
void draw();
int run(int initial_state);
>>>>>>> origin/master
