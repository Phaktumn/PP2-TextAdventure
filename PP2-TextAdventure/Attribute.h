#include <string>
#include <SFML/Graphics.hpp>


#pragma once
class Attribute
{
public:
	Attribute(sf::String name);
	~Attribute();

private:
	sf::String name;
	int value;
};

