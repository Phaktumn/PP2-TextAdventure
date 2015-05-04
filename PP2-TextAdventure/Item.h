#include <SFML\Graphics.hpp>

#pragma once
class Item
{
private:
	sf::Color Quality;
	sf::String name;
	float weaponDamage;
	float bonusStrength;
	float bonusIntelect;
	float bonusArmor;

public:
	Item();
	~Item();

	sf::String getName() { return name; }
};

