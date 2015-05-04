#include "Actors.h"

#pragma once
class Player : public Actor
{
private:
	//inventory here! tho
public:
	Player(Attribute attributes[], Ability abilities[], int HP, int Mana);
	~Player();


};

