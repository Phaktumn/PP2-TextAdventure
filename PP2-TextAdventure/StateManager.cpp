#include "StateManager.h"


StateManager::StateManager()
{
}


StateManager::~StateManager()
{

}

void StateManager::addState(const string &name, State* state) {
	states.add(state);
}

void StateManager::changeState(const string &name) {
	State* state = states.get(0);
	int i = 0;
	int count = states.getLength();

	while (i < count) {
		State* iteration = states.get(i);
		if (iteration->getName() == name) {
			currentState = iteration;
			return;
		}
	}
}

void StateManager::loadState(const string &name) {
	State* state = states.get(0);
	int i = 0;
	int count = states.getLength();

	while (i < count) {
		State* iteration = states.get(i);
		if (iteration->getName() == name) {
			iteration->load();
			return;
		}
	}
}

void StateManager::update() {
	currentState->update();
}

void StateManager::draw(RenderWindow *window) {
	currentState->draw(window);
}
