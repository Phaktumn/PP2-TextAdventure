#include "Item.h"

std::map<std::string, sf::Color> Item::quality;

Item::Item(sf::String _quality, sf::String _name, Type _type, int _bonusStrength, int _bonusIntelect)
{
	Quality = _quality;
	name = _name;

	bonusStrength = _bonusStrength;
	bonusIntelect = _bonusIntelect;
	type = _type;
}

Item::~Item()
{

}

sf::Color Item::getQuality(const std::string &name)
{
	return quality[name];
}

void Item::loadProperties(){
	quality.emplace("Legendary", sf::Color::Color(185, 33, 33, 255));
	quality.emplace("Epic", sf::Color::Color(237, 14, 181, 255));
	quality.emplace("Rare", sf::Color::Color(205, 00, 255, 255));
	quality.emplace("Uncommon", sf::Color::Color(71, 63, 232, 255));
	quality.emplace("Common", sf::Color::Color(162, 220, 220, 255));
}

void Item::draw(sf::RenderWindow* window, sf::Font* font, int x, int y)
{
	text.setString(name);
	text.setFont(*font);
	text.setCharacterSize(22);
	text.setColor(getQuality(Quality));
	text.setPosition(x, y);
	window->draw(text);
}
