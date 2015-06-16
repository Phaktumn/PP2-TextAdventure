#include "BattleManager.h"


BattleManager::BattleManager()
{ }


BattleManager::~BattleManager()
{ }

void BattleManager::applyBuff(UtilityAbility* utility, Player* player)
{

}

/*
calcular o damage em relacao ao armor!
*/
int BattleManager::calculateDamage(int tagetArmor, int abilityDamage){
	float reduction = (tagetArmor * 0.75) / 1000 > 0.75;
	if (reduction > 0.75){
		reduction = 0.75;
	}
	return abilityDamage - abilityDamage * reduction;
}

void BattleManager::applyDamage(Actor* caster, DamageAbility* damageAbility, Actor* target)
{
	int targetArmor = target->getAttribute("Armor").getValue();

	//full damage da ability tendo em conta as stats do player
	int abilityDamage = damageAbility->getFullDamage(caster);

	target->takeDamage(calculateDamage(targetArmor, abilityDamage));
}

