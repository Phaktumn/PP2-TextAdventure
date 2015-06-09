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
	int armor;
	LinkedList<Attribute> attributes;
	LinkedList<Ability> abilities;
	LinkedList<UtilityAbility> buffs;
	bool stunned;

public:
	Actor(std::string, Attribute _attributes[], Ability _abilities[], int hp, int mana, int baseArmor);
	~Actor();

	void load();
	void update();
	void draw();
	std::string getActorName();

	int getArmor();

	void setState();
	bool takeDamage(int damage);
};

