#include "BattleState.h"


BattleState::BattleState(sf::Font* font) : font(font)
{

}


BattleState::~BattleState()
{

}

void BattleState::load()
{

}

void BattleState::update()
{

}

void BattleState::draw(sf::RenderWindow* window)
{
	State::draw(window);

	sf::String separator(SEPARATOR);

	sf::Text text;
	text.setFont(*font);
	text.setColor(sf::Color::White);
	text.setCharacterSize(24);
	text.setPosition(0, 0);

	text.setString(separator);
	window->draw(text);

	drawText(50, 25, "BattleState here! nothin yet!!!", font, sf::Color::Red, 22);

	text.setPosition(0, 300);
	window->draw(text);

	text.setPosition(0, WINDOW_HEIGHT - 50);
	window->draw(text);
}
