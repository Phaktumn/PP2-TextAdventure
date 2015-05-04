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
	bool alive;
	float hp;
	float mana;
	LinkedList<Attribute> attributes;
	LinkedList<Ability> abilities;

public:
	Actor(Attribute _attribures[], Ability _abilities[]);
	~Actor();

	void load();
	void update();
	void draw();
};

