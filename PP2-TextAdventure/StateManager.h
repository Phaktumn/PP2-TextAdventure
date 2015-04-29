#pragma once
#include "State.h"
#include "LinkedList.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class StateManager
{
public:
	StateManager();
	~StateManager();

	void addState(const string &name, State* state);
	void changeState(const string &name);
	void loadState(const string &name);
	void update();
	void draw(RenderWindow *window);

private:
	State *currentState;
	std::map<std::string, State*> states;
};

