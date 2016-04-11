#include "Location.h"
#include "Actor.h"
#include <SFML/Graphics.hpp>


Location::Location(std::string Name, std::string Description, LinkedList<Actor> Enemys)
{

}


Location::~Location()
{
}

void Location::drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window)
{
	text.setPosition(x, y);
	text.setCharacterSize(size);

	window->draw(text);
}

void Location::drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window) {
	sf::Text _text;
	_text.setPosition(x, y);
	_text.setString(text);
	_text.setFont(font);
	_text.setCharacterSize(size);

	window->draw(_text);
}
