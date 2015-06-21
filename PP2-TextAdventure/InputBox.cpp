#include "InputBox.h"
#include <iostream>
#include <functional>

#define NULL_STRING ""

InputBox::InputBox(float x, float y, sf::Font* font, int fontSize, sf::Color color) : x(x), y(y) {
	text.setFont(*font);
	text.setCharacterSize(fontSize);
	text.setColor(color);
	text.setPosition(x, y);
	string += "> ";
}

InputBox::~InputBox() {

}

void InputBox::addListener(const std::function<void(std::string)> function)
{
	listeners.push_back(function);
} 

void InputBox::handleInput()
{
	if (sent) {
		log.push_back(string);
		std::cout << log.back() << std::endl;
		sent = false;
		
		for (size_t i = 0; i < listeners.size(); i++) {
			listeners[i](string);
		}

		string.clear();
		string += "> ";
	}
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
		}
	}

	handleInput();

	text.setString(string);
	modified = false;
}

void InputBox::display(sf::RenderWindow* window) {
	window->draw(text);
}

std::string InputBox::lastCommand() {
	if (!log.empty()) {
		log.push_back("-1");
		return log.back();
	}
	else
		return "-1";
}