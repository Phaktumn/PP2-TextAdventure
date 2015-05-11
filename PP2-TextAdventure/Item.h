#include <SFML\Graphics.hpp>

#pragma once
class Item
{
private:
	sf::Color Quality;
	sf::String name;
	int bonusArmor;
	int weaponDamage;
	int bonusStrength;
	int bonusIntelect;
	sf::Text text;

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
	Item(sf::Color quality, sf::String name, Type type, int bonusStrength, int bonusIntelect);
	~Item();
	static sf::Color getQuality(const std::string &name);
	static void loadProperties();
	void draw(sf::RenderWindow* window, sf::Font* font);

	std::string getName() { return name.toAnsiString(); }
};


