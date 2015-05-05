#include "Weapon.h"


Weapon::Weapon(sf::Color _quality, sf::String _name, Type weaponType, int _bonusStrength, int _bonusIntelect, int _weaponDamage)
: Item(_quality, _name, weaponType, _bonusStrength, _bonusIntelect), weaponDamage(weaponDamage)
{
}


Weapon::~Weapon()
{

}
