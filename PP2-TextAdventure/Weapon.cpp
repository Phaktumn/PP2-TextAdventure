#include "Weapon.h"


Weapon::Weapon(sf::String _quality, sf::String _name, sf::String description, Type weaponType, int _bonusStrength, int _bonusIntelect, int _weaponDamage)
: Item(_quality, _name, description, weaponType, _bonusStrength, _bonusIntelect), weaponDamage(_weaponDamage)
{
}


Weapon::~Weapon()
{

}
