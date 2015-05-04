#include "Armor.h"


Armor::Armor(sf::Color quality, sf::String name, int bonusStrength, int bonusIntelect, int bonusArmor)
: Item(quality, name, bonusStrength, bonusIntelect), bonusArmor(bonusArmor)
{

}


Armor::~Armor()
{

}
