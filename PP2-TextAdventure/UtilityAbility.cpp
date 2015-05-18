#include "UtilityAbility.h"


UtilityAbility::UtilityAbility(const sf::String &_name, Resource _resource, int _cost, unsigned int duration, float _damageReduction) 
: Ability(_name, _resource, _cost), duration(duration), damageReduction(_damageReduction)
{

}


UtilityAbility::~UtilityAbility()
{

}

float UtilityAbility::getReduction(){
	return damageReduction;
}

void UtilityAbility::onBattleEvent(BattleState* battleState){

}


