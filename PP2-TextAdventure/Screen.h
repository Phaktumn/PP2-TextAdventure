#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Screen
{
private:
	sf::Window* targetWindow;

	float inputBufferWidth, inputBufferHeight;
	float inputBufferX, inputBufferY;
	sf::String inputBuffer;

public:
	Screen(sf::Window* targetWindow);
	~Screen();

	void update();
	void draw();
};