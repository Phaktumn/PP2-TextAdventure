#include "Item.h"

#pragma once
class Armor : public Item
{
private:
	int bonusArmor;
public:
	Armor(sf::Color quality, sf::String name, int bonusStrength, int bonusIntelect, int bonusArmor);
	~Armor();
};

