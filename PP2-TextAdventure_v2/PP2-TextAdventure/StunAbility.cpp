#include "StunAbility.h"


StunAbility::StunAbility(const sf::String & _name,Resource _resource, int _cost, unsigned int duration, unsigned int cooldown)
	:Ability(_name, _resource, _cost), duration(duration), cooldown(cooldown)
{

}


StunAbility::~StunAbility()
{

}
