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

	static sf::Color getQuality(const std::string &name) {
		return quality[name];
	}

	static void loadProperties() {
		quality.emplace("Legendary", sf::Color::Color(185, 33, 33, 255));
		quality.emplace("Epic", sf::Color::Color(237, 14, 181, 255));
		quality.emplace("Rare", sf::Color::Color(205, 00, 255, 255));
		quality.emplace("Uncommon", sf::Color::Color(71, 63, 232, 255));
		quality.emplace("Common", sf::Color::Color(162, 220, 220, 255));
	}

	Type type;
	Item(sf::Color quality, sf::String name, Type type, int bonusStrength, int bonusIntelect);
	~Item();
	void draw(sf::RenderWindow* window, sf::Font* font);

	std::string getName() { return name.toAnsiString(); }
};


