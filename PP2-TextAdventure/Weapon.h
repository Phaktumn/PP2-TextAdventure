#include "Item.h"

#pragma once
class Weapon : public Item
{
private:
	int weaponDamage;
public:
	Weapon(sf::Color quality, sf::String name, Type weaponType, int bonusStrength, int bonusIntelect, int weaponDamage);
	~Weapon();
};

