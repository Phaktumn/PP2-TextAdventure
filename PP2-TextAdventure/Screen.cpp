#include "Screen.h"


Screen::Screen(sf::Window* targetWindow) : targetWindow(targetWindow)
{
	inputBufferHeight = 20;
	inputBufferHeight = targetWindow->getSize().x;

	inputBufferX = 0;
	inputBufferY = 0;
}

Screen::~Screen()
{
}

void Screen::draw()
{
	
}