#pragma once
#include <SFML/Graphics.hpp>
#include "LinkedList.h"
#include <functional>

class InputBox
{
public:
	InputBox(float x, float y, sf::Font* font, int fontSize, sf::Color color);
	~InputBox();

	void addListener(std::function<void(std::string)> function);

	void update(sf::Event* windowEvent);
	void display(sf::RenderWindow* window);
	std::string lastCommand();
	void handleInput();

	std::vector<std::string> log;

private:
	sf::Font font;
	sf::Text text;
	std::string string;
	float x, y;
	bool modified, sent;

	std::vector<std::function<void(std::string)>> listeners;
};

