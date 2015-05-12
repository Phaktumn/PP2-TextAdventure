//ACABAR ISTO

#pragma once
#include <SFML\Graphics.hpp>

class Ability
{
public:
	Ability(const sf::String &name, int cost);
	~Ability();

	sf::String getName() { return name; }

	typedef enum Resource {
		MANA, RAGE
	} Resource;

private:
	sf::String name;
	int cost;
	Resource resource;
};

