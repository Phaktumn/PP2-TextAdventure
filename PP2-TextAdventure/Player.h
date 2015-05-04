#include "Actor.h"

#pragma once
class Player : public Actor
{
private:
	//inventory here! tho
public:
	Player(Attribute attributes[], Ability abilities[], int hp, int mana);
	~Player();
};

