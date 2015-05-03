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
			modified = true;
		} else if (windowEvent->text.unicode < 128 && windowEvent->text.unicode != 13) {
			string += static_cast<char>(windowEvent->text.unicode);
			modified = true;
		} else if (windowEvent->text.unicode == 13) {
			sent = true;
			string.clear();
			string += "> ";
		}
	}

	if (sent) {
		log.add(&sf::String(string));
		sent = false;
	}

	text.setString(string);
	modified = false;
}

void InputBox::display(sf::RenderWindow* window) {
	window->draw(text);
}

sf::String InputBox::lastCommand() {
	return *log.get(log.getLength() - 1);
}