#include "DamageAbility.h"


DamageAbility::DamageAbility(const sf::String &name, Resource _resource,int cost, int damage, float multiplier) 
	: Ability(name, _resource, cost), damage(damage), multiplier(multiplier)
{

}

DamageAbility::~DamageAbility()
{

}

/// <summary>
/// Deals damage to the target Actor.
/// </summary>
/// <param name="target">Pointer to the target actor.</param>
int DamageAbility::getFullDamage() {
	return damage * multiplier;
}
