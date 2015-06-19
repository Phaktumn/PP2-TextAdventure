#include "Actor.h"
#include <SFML/Graphics.hpp>

Actor::Actor(std::string name, Attribute _attributes[], Ability _abilities[], int hp, int mana)
{
	int length = sizeof(_attributes)/sizeof(*_attributes);
	for (int i = 0; i < length; i++){
		attributes.add(_attributes[i]);
	}
	
	if (_abilities != nullptr) {
		length = sizeof(_abilities) / sizeof(*_abilities);
		for (int i = 0; i < length; i++){
			abilities.add(_abilities[i]);
		}
	}

	alive = true;
	stunned = false;
}

Actor::~Actor()
{

}

void Actor::load()
{

}

void Actor::update()
{
	if (stunned == true)
	{

	}
	else
	{

	}
}

void Actor::draw()
{

}

std::string Actor::getActorName()
{
	return name;
}

void Actor::setState()
{
	if (!stunned) stunned = true;
	else stunned = false;
}

bool Actor::takeDamage(int damage) {
	hp -= damage;

	alive = hp > 0;
	return hp <= 0;
}

Attribute Actor::getAttribute(sf::String name){
	for (int i = 0; i < attributes.getLength(); i++){
		if (attributes.get(i).getName() == name)
			return attributes.get(i);
	}
}

void Actor::useAbility(unsigned int input){

}



