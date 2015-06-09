#include "UtilityAbility.h"
#include "DamageAbility.h"
#include "Player.h"

#pragma once
class BattleManager
{
public:
    BattleManager();
	~BattleManager();
	static void applyBuff(UtilityAbility* utility, Player* player);
	static void applyDamage(DamageAbility* damageAbility, Actor* target);

private:

};

