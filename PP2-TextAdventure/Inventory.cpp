#include "Inventory.h"

<<<<<<< HEAD

=======
>>>>>>> origin/master
Inventory::Inventory(Player* player) : player(player)
{

}


Inventory::~Inventory()
{

}

void Inventory::equipWeapon(Weapon* _weapon)
{
	if (weapon != nullptr){
		player->removeBonusIntellect(_weapon->getBonusIntellevt());
		player->removeBonusDamage(_weapon->getBonusStrenght());
	}

	weapon = _weapon;

	player->addBonusDamage(_weapon->getBonusStrenght());
	player->addBonusIntellect(_weapon->getBonusIntellevt());
}

void Inventory::equipArmor(Armor* armor, Item::Type type)
{
	switch (type)
	{
	case Item::helmet:
	{
						 //removes the armor of the last equiped head
						 if (head != nullptr)
							 player->removeBonusArmor(head->getBonusArmor());

						 //replaces de head item for a new one
						 head = armor;

						 //add's the new stats to the player
						 player->addBonusArmor(head->getBonusArmor());
	}
		break;
	case Item::chest:{
						 if (chest != nullptr)
							 player->removeBonusArmor(chest->getBonusArmor());
						 chest = armor;
						 player->addBonusArmor(chest->getBonusArmor());
	}
		break;
	case Item::hands:{
						 if (hands != nullptr)
							 player->removeBonusArmor(chest->getBonusArmor());
						 hands = armor;
						 player->addBonusArmor(hands->getBonusArmor());
	}
		break;
	case Item::legs:{
						if (legs != nullptr)
							player->removeBonusArmor(legs->getBonusArmor());
						legs = armor;
						player->addBonusArmor(legs->getBonusArmor());
	}
		break;
	case Item::feet:{
						if (feet != nullptr)
							player->removeBonusArmor(feet->getBonusArmor());
						feet = armor;
						player->addBonusArmor(feet->getBonusArmor());
	}
		break;
	}
}
