#include <string>
#include <SFML/Graphics.hpp>


#pragma once
class Attribute
{
public:
	Attribute(sf::String name, int value);
	~Attribute();

	sf::String getName(){ return name; }
	int getValue(){ return value; }

	void changeValue(int value);

private:
	sf::String name;
	int value;
};

