//atributos
//abilities
//hp mana
//state
//linked list atributos
//linked list abilities
#include <SFML/Graphics.hpp>
#include "Attribute.h"
#include "LinkedList.h"

#pragma once
class Actors
{
private:
	bool alive;
	float hp;
	float mana;
	LinkedList<Attribute> attributes;

public:
	Actors();
	~Actors();

	void load();
	void update();
	void draw();
};

