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
	int atuamae;

public:
	Item(sf::Color quality, sf::String name, int bonusStrength, int bonusIntelect);
	~Item();

	sf::String getName() { return name; }
};

