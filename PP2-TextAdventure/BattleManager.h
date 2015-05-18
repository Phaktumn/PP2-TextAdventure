
#include "Player.h"

#pragma once
class BattleManager
{
public:
    BattleManager();
	~BattleManager();
	static void applyBuff();
	static void applyDamage(int damage);

private:
	bool canAttack();
	int calculateDamage();
};

