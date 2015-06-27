#include "Item.h"

#pragma once
class Weapon : public Item
{
private:
	int weaponDamage;
public:
	Weapon(sf::String quality, sf::String name, sf::String description, Type weaponType, int bonusStrength, int bonusIntelect, int weaponDamage);
	~Weapon();

	int getWeaponDamage(){ return weaponDamage; }
};

