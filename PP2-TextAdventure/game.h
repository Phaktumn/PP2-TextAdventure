#define GAME_RUN(state) run(state);
#define GAME_STOP state = RUNNING;

typedef enum STATE
{
	RUNNING, PAUSED, EXIT
} STATE;

STATE state;
void update();
void draw();
int run(STATE initial_state);