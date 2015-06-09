#pragma once
#include "Ability.h"
class UtilityAbility : public Ability
{
public:
	UtilityAbility(const sf::String &name, Resource resource, int cost,unsigned int duration, float damageReduction);
	~UtilityAbility();

	float getReduction();

private:
	unsigned int duration;
	float damageReduction;
};

