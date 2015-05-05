#include "Item.h"


Item::Item(sf::Color _quality, sf::String _name, Type _type, int _bonusStrength, int _bonusIntelect)
{
	Quality = _quality;
	name = _name;
	bonusStrength = _bonusStrength;
	bonusIntelect = _bonusIntelect;
	type = type;
}


Item::~Item()
{
}
