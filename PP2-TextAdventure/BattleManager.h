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
	static void applyDamage(Actor* caster, DamageAbility* damageAbility, Actor* target);

	static int getDamage(int damage){ return damage; }

private:
	static int calculateDamage(int targetArmor,int abilityDamage);
};

