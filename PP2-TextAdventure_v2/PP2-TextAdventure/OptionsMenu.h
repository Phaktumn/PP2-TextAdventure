#pragma once
#include "LinkedList.h"
#include <SFML/Graphics.hpp>

class OptionsMenu
{
public:
	OptionsMenu();
	~OptionsMenu();
	
private:
	LinkedList<sf::String> options;

};

