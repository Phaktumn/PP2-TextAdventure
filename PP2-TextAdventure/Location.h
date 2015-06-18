#pragma once
#include <SFML/Graphics.hpp>
#include "LinkedList.h"
#include "Actor.h"
#include "RichText.hpp"


class Location
{
	std::string Description, Name;
	LinkedList<Actor> Enemys;

public:
	Location(std::string Name, std::string Description, LinkedList<Actor> Enemys);
	~Location();

	void drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window);
	void drawText(float x, float y, const std::string& text, sf::Font &font, int size, sf::RenderWindow* window);


};
