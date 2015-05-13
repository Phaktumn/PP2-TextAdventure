//ACABAR ISTO

#pragma once
#include <SFML\Graphics.hpp>

class Ability
{
public:
	typedef enum Resource {
		NORESOURCE,
		MANA,
		RAGE
	} Resource;

	Ability(const sf::String &name, Resource resource, int cost);
	~Ability();

	sf::String getName() { return name; }
	int getCost() { return cost; }

private:
	sf::String name;
	int cost;
protected:
	Resource resource;
};

