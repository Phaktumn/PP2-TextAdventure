#pragma once
#include "Ability.h"
#include "BattleState.h"
class UtilityAbility : public Ability
{
public:
	UtilityAbility(const sf::String &name, Resource resource, int cost,unsigned int duration, float damageReduction);
	~UtilityAbility();

	void onBattleEvent(BattleState* battleState) override;

	float getReduction();

private:
	unsigned int duration;
	float damageReduction;

};

