#pragma once
#include "Ability.h"
#include "Actor.h"
#include "Globals.h"

class DamageAbility : public Ability
{
public:
	enum attribute
	{
		strength,
		intellect,
	};

	attribute attributeMultiplyer;

	DamageAbility(const sf::String &name, Resource resource, int cost, int damage,attribute multiplierAttribute, float multiplier = 1);
	~DamageAbility();
	
	int getFullDamage(Actor* caster);

	int getDamage() { return damage; }
	float getMultiplier() { return multiplier; }
	void setMultiplier(float value) { multiplier = value; }

private:
	int damage;
	float multiplier;
};

