#include <string>
#include <SFML/Graphics.hpp>


#pragma once
class Attribute
{
public:
	Attribute(sf::String name, int value);
	~Attribute();

private:
	sf::String name;
	int value;
};

