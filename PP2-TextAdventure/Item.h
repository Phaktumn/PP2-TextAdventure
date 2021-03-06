#include <SFML\Graphics.hpp>

#pragma once
class Item
{
private:
	sf::String name;
	int bonusStrength;
	int bonusIntelect;
	sf::Text text;
	sf::String description;
	sf::String Quality;
	static std::map<std::string, sf::Color> quality;

public:
	enum Type
	{
		helmet,
		feet,
		hands,
		weapon,
		chest,
		legs,
	};

	Type type;
	Item(sf::String quality, sf::String name, sf::String description, Type type, int bonusStrength, int bonusIntelect);
	~Item();

	sf::String Description(){ return description; }
	static sf::Color getQuality(const std::string &name);
	static void loadProperties();
	void draw(sf::RenderWindow* window, sf::Font* font, int x, int y);

	std::string getName() { return name.toAnsiString(); }
	int getBonusStrenght() { return bonusStrength; }
	int getBonusIntellevt() { return bonusIntelect; }
};


