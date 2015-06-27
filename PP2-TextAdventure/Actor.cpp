#include "Actor.h"
#include <SFML/Graphics.hpp>

Actor::Actor(std::string _name, LinkedList<Attribute*> _attributes, LinkedList<Ability*> _abilities, int hp, int mana,int level, int baseMaxHP, int baseMaxResource, const int _baseHP)
: name(_name), attributes(_attributes), abilities(_abilities), hp(hp), resource(mana), level(level), baseHP(_baseHP)
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
	MaxHp = baseMaxHP;
	MaxResource = baseMaxResource;
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
	if (this->getAttribute(BONUS_ARMOR) == nullptr)
		MaxHp = baseHP + (this->getAttribute(STRENGTH)->getValue() * 7.50f);
	else MaxHp = baseHP + ((this->getAttribute(STRENGTH)->getValue() + this->getAttribute(BONUS_STRENGTH)->getValue()) * 7.50f);
	if (hp < 0) alive = false;


	//resource regen XD
	if (resource < MaxResource){
		if (this->getAttribute(BONUS_INTELLECT) == nullptr)
			resource += ceil(0.7f * this->getAttribute(INTELLECT)->getValue());
		else resource += ceil(0.7f * this->getAttribute(INTELLECT)->getValue() + this->getAttribute(BONUS_INTELLECT)->getValue());
		if (resource > MaxResource){
			resource = MaxResource;
		}
	}
	//health regen XD
	if (hp < MaxHp){
		if (this->getAttribute(BONUS_INTELLECT) == nullptr)
			hp += ceil(0.8f * this->getAttribute(INTELLECT)->getValue());
		else hp += ceil(0.8f * this->getAttribute(INTELLECT)->getValue() + this->getAttribute(BONUS_INTELLECT)->getValue());
		if (hp > MaxHp){
			hp = MaxHp;
		}
	}
}

void Actor::goFullUpdate()
{
	hp = MaxHp;
	resource = MaxResource;
	alive = true;
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
	return nullptr;
}



