#include "State.h"

void State::drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window)
{
	text.setPosition(x, y);
	text.setCharacterSize(size);
		
	window->draw(text);
}

void State::drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window) {
	sf::Text _text;
	_text.setPosition(x, y);
	_text.setString(text);
	_text.setFont(font);
	_text.setCharacterSize(size);

	window->draw(_text);
}

void State::draw(sf::RenderWindow* window)
{
	
}