#include "Actors.h"
#include <SFML/Graphics.hpp>

Actor::Actor(Attribute _attributes[], Ability _abilities[])
{
	int lengthAtribute = sizeof(_attributes)/sizeof(*_attributes);
	int lengthAbility = sizeof(_abilities) / sizeof(*_abilities);
	for (int i = 0; i < lengthAtribute; i++){
		attributes.add(_attributes[i]);
	}
	for (int i = 0; i < lengthAbility; i++){
		abilities.add(_abilities[i]);
	}
}

Actor::~Actor()
{

}

void Actor::load()
{

}

void Actor::update()
{

}

void Actor::draw()
{

}

