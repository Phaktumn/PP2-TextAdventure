//atributos
//abilities
//hp mana
//state
//linked list atributos
//linked list abilities
#include <SFML/Graphics.hpp>
#include "Attribute.h"
#include "LinkedList.h"
#include "Ability.h"
#include "UtilityAbility.h"

#pragma once
class Actor
{
private:
	std::string name;
	bool alive;
	int hp;
	int mana;
	LinkedList<Attribute*> attributes;
	LinkedList<Ability*> abilities;
	LinkedList<UtilityAbility*> buffs;
	bool stunned;

public:
	Actor(std::string name, LinkedList<Attribute*> _attributes, LinkedList<Ability*> _abilities, int hp, int mana);
	~Actor();

	void load();
	void update();
	void draw();

	std::string getActorName(){ return name; }
	int getHp(){ return hp; }

	void useAbility(unsigned int input);

	LinkedList<Ability*> getAbilities(){ return abilities; }

	Ability* getAbility(sf::String name);
	Attribute* getAttribute(sf::String name);

	void setState();
	bool takeDamage(int damage);
};

