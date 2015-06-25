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
#include "Globals.h"

class Actor
{
private:
	std::string name;
	bool alive;
	int hp;
	int resource;
	int Damage;
	int MaxHp;
	const int baseHP;
	int MaxResource;
	LinkedList<Attribute*> attributes;
	LinkedList<Ability*> abilities;
	LinkedList<UtilityAbility*> buffs;
	bool stunned;

public:
	Actor(std::string name, LinkedList<Attribute*> _attributes, LinkedList<Ability*> _abilities, int hp, int mana, int level, int baseMaxHP, int baseMaxResource, const int baseHP);
	~Actor();

	void load();
	void virtual update();
	void draw();

	void goFullUpdate();

	std::string getActorName(){ return name; }
	int getHp(){ return hp; }
	int getMaxHP(){ return MaxHp; }

	int getResource(){ return resource; }
	void changeResource(int value){ resource += value; }
	int getMaxResource(){ return MaxResource; }
	void changeMaxResource(int value){ MaxResource += value; }

	LinkedList<Ability*> getAbilities(){ return abilities; }

	Ability* getAbility(sf::String name);
	Attribute* getAttribute(sf::String name);
	int getDamage() { return Damage; }
	int setDamage(int value){ return Damage += value; }
	int getLevel(){ return level;}

	bool isAlive(){ return alive; }

	void setState();
	bool takeDamage(int damage);

protected:
	int level;
};

