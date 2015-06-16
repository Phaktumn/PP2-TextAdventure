#pragma once
#include <SFML/Graphics.hpp>
#include "RichText.hpp"

class State
{
public:
	virtual ~State()
	{
	}

	virtual void load() = 0;
	virtual void update() = 0;

	virtual void draw(sf::RenderWindow* window);
	void drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window);
	void drawText(float x, float y, const std::string& text, sf::Font &font, int size, sf::RenderWindow* window);
};

