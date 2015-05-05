#include <SFML\Graphics.hpp>

#pragma once
class Item
{
private:
	sf::Color Quality;
	sf::String name;
	int weaponDamage;
	int bonusStrength;
	int bonusIntelect;
	int bonusArmor;

public:
	enum Type
	{
		helmet,
		chest,
		hands,
		weapon,
		legs,
		feet,
	};
	Type type;
	Item(sf::Color quality, sf::String name, Type type, int bonusStrength, int bonusIntelect);
	~Item();

	sf::String getName() { return name; }
};


