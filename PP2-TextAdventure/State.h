#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class State
{
public:
	State();
	~State();

	void load();
	void update();
	void draw(sf::RenderWindow *window);
	std::string getName();

protected:
	std::string name;
};

