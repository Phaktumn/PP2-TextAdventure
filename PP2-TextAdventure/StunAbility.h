#pragma once
#include "Ability.h"
#include "BattleState.h"

class StunAbility : public Ability
{
public:
	StunAbility(const sf::String &name, Resource resource, int cost, unsigned int duration);
	~StunAbility();
	void onBattleEvent(BattleState* battleState) override;

private:
	unsigned int duration;
};

