#include "BattleManager.h"


BattleManager::BattleManager()
{ }


BattleManager::~BattleManager()
{ }

void BattleManager::applyBuff(UtilityAbility* utility, Player* player)
{

}

void BattleManager::applyDamage(DamageAbility* damageAbility, Actor* target)
{
	target->takeDamage(damageAbility->getFullDamage());
}
