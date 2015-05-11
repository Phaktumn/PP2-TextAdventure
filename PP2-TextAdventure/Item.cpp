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

void Item::draw(sf::RenderWindow* window, sf::Font* font)
{
	text.setString(name);
	text.setFont(*font);
	text.setCharacterSize(22);
	text.setColor(Quality);
	text.setPosition(100, 100);
	window->draw(text);
}
