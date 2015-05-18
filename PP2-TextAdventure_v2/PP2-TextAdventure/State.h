#pragma once
#include <SFML/Graphics.hpp>

class State
{
public:
	virtual ~State()
	{
	}

	virtual void load() = 0;
	virtual void update() = 0;

	virtual void draw(sf::RenderWindow *window);
	void drawText(float x, float y, const std::string &string, sf::Font *font, sf::Color color, int size);
	void removeText(const std::string &string);

private:
	std::map<std::string, sf::Text> drawnText;
	typedef std::map<std::string, sf::Text>::iterator it_type;
};

