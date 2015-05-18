#pragma once
#include "Ability.h"
#include "DamageAbility.h"

class AutoAtack : public DamageAbility
{
public:
	AutoAtack(const sf::String _name, Resource _resource, int cost);
	~AutoAtack();

	void onBattleEvent(BattleManager* battleManager) override;
};

