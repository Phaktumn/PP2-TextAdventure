#pragma once
#include "Ability.h"
class StunAbility : public Ability
{
public:
	StunAbility(const sf::String &name, Resource resource, int cost, unsigned int duration, unsigned int cooldown);
	~StunAbility();

private:
	unsigned int duration;
	unsigned int cooldown;
};

