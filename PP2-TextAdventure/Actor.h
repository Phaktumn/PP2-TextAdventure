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

#pragma once
class Actor
{
private:
	std::string name;
	bool alive;
	int hp;
	int mana;
	LinkedList<Attribute> attributes;
	LinkedList<Ability> abilities;

public:
	Actor(std::string, Attribute _attributes[], Ability _abilities[], int hp, int mana);
	~Actor();

	void load();
	void update();
	void draw();
	std::string getActorName();

	bool takeDamage(int damage);
};

