#pragma once
#include "Ability.h"
#include "Actor.h"

class DamageAbility : public Ability
{
public:
	DamageAbility(const sf::String &name, Resource resource, int cost, int damage, float multiplier = 1);
	~DamageAbility();
	
	void dealDamage(Actor* target);

	int getDamage() { return damage; }
	float getMultiplier() { return multiplier; }
	void setMultiplier(float value) { multiplier = value; }

private:
	int damage;
	float multiplier;
};

