#include "State.h"

void State::drawText(float x, float y, const std::string &string, sf::Font *font, sf::Color color, int size)
{
	sf::Text text;
	text.setPosition(x, y);
	text.setCharacterSize(size);
	text.setFont(*font);
	text.setColor(color);
	text.setString(string);

	drawnText.emplace(string, text);
}

void State::draw(sf::RenderWindow *window)
{
	for (it_type iterator = drawnText.begin(); iterator != drawnText.end(); iterator++) {
		window->draw(iterator->second);
	}
}

void State::removeText(const std::string &string)
{
	drawnText.erase(string);
}