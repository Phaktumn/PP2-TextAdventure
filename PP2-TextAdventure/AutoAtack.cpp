#include "AutoAtack.h"


AutoAtack::AutoAtack(const sf::String _name, Resource _resource, int _cost) 
	: DamageAbility(_name, _resource, _cost, 10, DamageAbility::attribute::strength, 10)
{

}


AutoAtack::~AutoAtack()
{

}
