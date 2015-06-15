#include "StateManager.h"

StateManager::StateManager()
{

}


StateManager::~StateManager()
{

}

void StateManager::addState(const string &name, State* state) {
	if (states.find(name) != states.end()) {
		printf("Error: Specified state already exists in memory.");
		return;
	}

	states.insert(std::pair<std::string, State*>(name, state));
}

void StateManager::changeState(const string &name) {
	if (states.find(name) == states.end()) {
		printf("Error: Specified state could not be found.");
		return;
	}

	currentState = states[name];
}

void StateManager::loadState(const string &name) {
	if (states.find(name) == states.end()) {
		printf("Error: Specified state could not be found.");
		return;
	}

	states[name]->load();
}

void StateManager::update() {
	currentState->update();
}

void StateManager::draw(RenderWindow* window) {
	currentState->draw(window);
}
