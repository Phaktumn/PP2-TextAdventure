#include "Actor.h"

#pragma once
class Player : public Actor
{
private:
	//inventory here! tho
public:
	Player(std::string name, Attribute attributes[], Ability abilities[], int hp, int mana, int baseArmor);
	~Player();
};

