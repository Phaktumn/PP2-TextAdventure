//atributos
//abilities
//hp mana
//state
//linked list atributos
//linked list abilities
#pragma once
#include <SFML/Graphics.hpp>
#include "Attribute.h"
#include "LinkedList.h"
#include "Ability.h"
#include "UtilityAbility.h"

class Actor
{
private:
	std::string name;
	bool alive;
	int hp;
	int mana;
	int Damage;
	LinkedList<Attribute*> attributes;
	LinkedList<Ability*> abilities;
	LinkedList<UtilityAbility*> buffs;
	bool stunned;

public:
	Actor(std::string name, LinkedList<Attribute*> _attributes, LinkedList<Ability*> _abilities, int hp, int mana, int level);
	~Actor();

	void load();
	void update();
	void draw();

	std::string getActorName(){ return name; }
	int getHp(){ return hp; }

	LinkedList<Ability*> getAbilities(){ return abilities; }

	Ability* getAbility(sf::String name);
	Attribute* getAttribute(sf::String name);
	int getDamage() { return Damage; }
	int setDamage(int value){ return Damage += value; }
	int getLevel(){ return level;}

	void setState();
	bool takeDamage(int damage);

protected:
	int level;

};

