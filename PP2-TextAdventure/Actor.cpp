#include "Actor.h"
#include <SFML/Graphics.hpp>

Actor::Actor(std::string _name, LinkedList<Attribute*> _attributes, LinkedList<Ability*> _abilities, int hp, int mana,int level)
	: name(_name), attributes(_attributes), abilities(_abilities), hp(hp), mana(mana), level(level)
{
	//int length = sizeof(_attributes)/sizeof(*_attributes);
	//for (int i = 0; i < length; i++){
	//	attributes.add(_attributes[i]);
	//}
	//
	//if (_abilities != nullptr) {
	//	length = sizeof(_abilities) / sizeof(*_abilities);
	//	for (int i = 0; i < length; i++){
	//		abilities.add(_abilities[i]);
	//	}
	//}
	MaxHp = hp;
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
	if (this->getAttribute(BONUS_ARMOR)->getValue() > 10000 || this->getAttribute(BONUS_ARMOR)->getValue() < 0)
		MaxHp = WARRIOR_BASE_HP + (this->getAttribute(STRENGTH)->getValue() * 0.20f);
	else MaxHp = WARRIOR_BASE_HP + ((this->getAttribute(STRENGTH)->getValue() + this->getAttribute(BONUS_STRENGTH)->getValue()) * 0.20f);

	if (hp < MaxHp){
		hp = MaxHp;
		/*if (hp > MaxHp){
			hp = MaxHp;
		}*/
	}
}

void Actor::draw()
{

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

Ability* Actor::getAbility(sf::String name)
{
	for (int i = 0; i <= abilities.getLength(); i++){
		if (abilities.get(i)->getName() == name)
			return abilities.get(i);
	}
}

Attribute* Actor::getAttribute(sf::String name){
	for (int i = 0; i <= attributes.getLength(); i++){
		if (attributes.get(i)->getName() == name)
			return attributes.get(i);
	}
}



