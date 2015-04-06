#define GAME_RUN(state) run(state);
#define GAME_STOP state = RUNNING;

enum GAME_STATE
{
	RUNNING, PAUSED, EXIT
};

int state;
void update();
void draw();
int run(int initial_state);