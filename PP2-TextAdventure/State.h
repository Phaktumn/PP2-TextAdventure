#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class State
{
public:
	virtual void load() = 0;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow *window) = 0;
};

