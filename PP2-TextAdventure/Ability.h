#include <SFML\Graphics.hpp>

#pragma once
class Ability
{
private:
	sf::String name;
	int value;

public:
	Ability(sf::String _name, int value);
	~Ability();
};

