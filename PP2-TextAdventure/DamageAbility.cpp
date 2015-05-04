#include "DamageAbility.h"


DamageAbility::DamageAbility(const sf::String &name, int cost, int damage, float multiplier) 
	: Ability(name, cost), damage(damage), multiplier(multiplier)
{

}

DamageAbility::~DamageAbility()
{

}

void DamageAbility::dealDamage(Actor* target) {
	target->takeDamage(damage * multiplier);
}
