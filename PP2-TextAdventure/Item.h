#include <SFML\Graphics.hpp>

#pragma once
class Item
{
private:
	sf::String name;
	int bonusArmor;
	int weaponDamage;
	int bonusStrength;
	int bonusIntelect;
	sf::Text text;
	sf::String Quality;
	static std::map<std::string, sf::Color> quality;

public:
	enum Type
	{
		helmet,
		chest,
		hands,
		weapon,
		legs,
		feet,
	};

	Type type;
	Item(sf::String quality, sf::String name, Type type, int bonusStrength, int bonusIntelect);
	~Item();

	static sf::Color getQuality(const std::string &name);
	static void loadProperties();
	void draw(sf::RenderWindow* window, sf::Font* font, int x, int y);

	std::string getName() { return name.toAnsiString(); }
	int getBonusArmor() { return bonusArmor; }
	int getBonusStrenght() { return bonusStrength; }
	int getBonusIntellevt() { return bonusIntelect; }
};


