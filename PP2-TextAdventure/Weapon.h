#include "Item.h"

#pragma once
class Weapon : public Item
{
private:
	int weaponDamage;
public:
	Weapon(sf::Color quality, sf::String name, int bonusStrength, int bonusIntelect, int weaponDamage);
	~Weapon();
};

