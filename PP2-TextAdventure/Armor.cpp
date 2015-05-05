#include "Armor.h"


Armor::Armor(sf::Color quality, sf::String name, Type armorType, int bonusStrength, int bonusIntelect, int bonusArmor)
: Item(quality, name, armorType, bonusStrength, bonusIntelect), bonusArmor(bonusArmor)
{

}


Armor::~Armor()
{

}
