#include "Item.h"


Item::Item(sf::Color _quality, sf::String _name, int _bonusStrength, int _bonusIntelect)
{
	Quality = _quality;
	name = _name;
	bonusStrength = _bonusStrength;
	bonusIntelect = _bonusIntelect;
}


Item::~Item()
{
}
