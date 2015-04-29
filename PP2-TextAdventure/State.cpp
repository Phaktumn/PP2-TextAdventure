#include "State.h"


State::State()
{
}

State::~State()
{
}

void State::load() {

}

void State::update() {
	printf("Hello!!!!");
}

void State::draw(sf::RenderWindow *window) {

}

std::string State::getName() {
	return name;
}