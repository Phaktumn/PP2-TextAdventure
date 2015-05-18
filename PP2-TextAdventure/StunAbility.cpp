#include "StunAbility.h"


StunAbility::StunAbility(const sf::String & _name,Resource _resource, int _cost, unsigned int duration)
	:Ability(_name, _resource, _cost), duration(duration)
{

}


StunAbility::~StunAbility()
{

}

void StunAbility::onBattleEvent(BattleState* battleState){

}
