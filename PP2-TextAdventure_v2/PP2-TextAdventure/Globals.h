#pragma once
#include <SFML\Graphics.hpp>
#include "LinkedList.h"
#include "Item.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern int MAX_ARMOR;
extern sf::String SEPARATOR;
extern std::map<int, sf::String> options;
extern bool activeInput;

//just a fcking test
extern void addOptions(int i, sf::String asset);
extern sf::String getOption(int i);
//just a fcking test
