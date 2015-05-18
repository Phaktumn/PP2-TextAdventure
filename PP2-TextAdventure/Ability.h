//ACABAR ISTO

#pragma once
#include <SFML\Graphics.hpp>
#include "BattleManager.h"

class Ability
{
public:
	typedef enum Resource {
		NORESOURCE,
		MANA,
		RAGE
	} Resource;

	Ability(const sf::String &name, Resource resource, int cost);
	~Ability();

	sf::String getName() { return name; }
	int getCost() { return cost; }
	virtual void onBattleEvent(BattleManager* battleManager) = 0;

private:
	sf::String name;
	int cost;
protected:
	Resource resource;
};

