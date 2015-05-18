//ACABAR ISTO

#include "Ability.h"
#include <SFML\Graphics.hpp>
#include "BattleManager.h"

Ability::Ability(const sf::String &name, Resource _resource, int cost) : name(name), cost(cost), resource(_resource)
{

}


Ability::~Ability()
{

}

void Ability::onBattleEvent(BattleManager* battleState){

}