#include "DamageAbility.h"


DamageAbility::DamageAbility(const sf::String &name, Resource _resource, int cost, int damage, attribute _attribute__Mult, float multiplier)
	: Ability(name, _resource, cost), damage(damage), multiplier(multiplier)
{
	attributeMultiplyer = _attribute__Mult;
}

DamageAbility::~DamageAbility()
{

}

/// <summary>
/// Deals damage to the target Actor.
/// </summary>
/// <param name="target">Pointer to the target actor.</param>
int DamageAbility::getFullDamage(Actor* caster){

	int multiplierDMG = 0;
	int casterPower;
	int casterIntellect;
	if (caster->getAttribute(BONUS_STRENGTH) == nullptr && caster->getAttribute(BONUS_INTELLECT) == nullptr)
	{
		casterPower = caster->getAttribute(STRENGTH)->getValue();
		casterIntellect = caster->getAttribute(INTELLECT)->getValue();
	}
	else
	{
		casterPower = caster->getAttribute(STRENGTH)->getValue() + caster->getAttribute(BONUS_STRENGTH)->getValue();
		casterIntellect = caster->getAttribute(INTELLECT)->getValue() + caster->getAttribute(BONUS_INTELLECT)->getValue();
	}
	switch (attributeMultiplyer)
	{
	case DamageAbility::strength:
		multiplierDMG = casterIntellect * multiplier;
		break;
	case DamageAbility::intellect:
		multiplierDMG = casterPower * multiplier;
		break;
	default: 
		break;
	}

	return damage + multiplierDMG;
}
