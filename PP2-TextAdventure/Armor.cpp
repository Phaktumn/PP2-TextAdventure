#include "Armor.h"


Armor::Armor(sf::String quality, sf::String name, sf::String description, Type armorType, int bonusStrength, int bonusIntelect, int bonusArmor)
: Item(quality, name, description, armorType, bonusStrength, bonusIntelect), bonusArmor(bonusArmor)
{

}


Armor::~Armor()
{

}



