#pragma once
#include "Ability.h"
class AutoAtack : public Ability
{
public:
	AutoAtack(const sf::String _name, Resource _resource, int cost);
	~AutoAtack();
};

