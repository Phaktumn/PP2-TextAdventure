#include "DamageAbility.h"


DamageAbility::DamageAbility(const sf::String &name, Resource _resource,int cost, int damage, float multiplier) 
	: Ability(name, _resource, cost), damage(damage), multiplier(multiplier)
{

}

DamageAbility::~DamageAbility()
{

}

void DamageAbility::dealDamage(Actor* target) {
	target->takeDamage(damage * multiplier);
}
