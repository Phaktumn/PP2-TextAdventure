#include "Inventory.h"


Inventory::Inventory()
{

}


Inventory::~Inventory()
{

}

void Inventory::equipWeapon(Weapon* _weapon)
{
	weapon = _weapon;
}

void Inventory::equipArmor(Armor* armor, Item::Type type)
{
	switch (type)
	{
	case Item::helmet:
		head = armor;
		break;
	case Item::chest:
		chest = armor;
		break;
	case Item::hands:
		hands = armor;
		break;
	case Item::legs:
		legs = armor;
		break;
	case Item::feet:
		feet = armor;
		break;
	}
}
