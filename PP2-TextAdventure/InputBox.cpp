#include "InputBox.h"

InputBox::InputBox(float x, float y, sf::Font* font, int fontSize, sf::Color color) : x(x), y(y) {
	text.setFont(*font);
	text.setCharacterSize(fontSize);
	text.setColor(color);
	text.setPosition(x, y);
	string += "> ";
}

InputBox::~InputBox() {

}

void InputBox::update(sf::Event* windowEvent) {	
	if (windowEvent->type == sf::Event::TextEntered) {
		if (windowEvent->text.unicode == '\b' && string.getSize() >= 3) {
			string.erase(string.getSize() - 1, 1);
		} else if (windowEvent->text.unicode < 128) {
			string += static_cast<char>(windowEvent->text.unicode);
		}
	}

	text.setString(string);
}

void InputBox::display(sf::RenderWindow* window) {
	window->draw(text);
}