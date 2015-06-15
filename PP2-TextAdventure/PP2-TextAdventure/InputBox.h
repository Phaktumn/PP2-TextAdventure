#pragma once
#include <SFML/Graphics.hpp>
#include "LinkedList.h"

class InputBox
{
public:
	InputBox(float x, float y, sf::Font* font, int fontSize, sf::Color color);
	~InputBox();

	void update(sf::Event* windowEvent);
	void display(sf::RenderWindow* window);
	sf::String lastCommand();

private:
	LinkedList<std::string> log;
	sf::Font font;
	sf::Text text;
	sf::String string;
	float x, y;
	bool modified, sent;
};

