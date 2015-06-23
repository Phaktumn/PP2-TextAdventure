#include "Credits.h"


Credits::Credits() : font(font), state(state), inputBox(inputBox)
{
	auxpos = 500;
}


Credits::~Credits()
{
}


void Credits::load(){}

void Credits::update()
{
	sf::Clock clock;

	sf::Time elapsed1 = clock.getElapsedTime();

	if (elapsed1.asSeconds() > 0.1f){
		auxpos -= 10;
		clock.restart();
	}
	if (inputBox.lastCommand() == "back")
		state.changeState("TitleMenuState");

}

void Credits::draw(sf::RenderWindow *window) {

	drawText(0, auxpos     , "Rui Caridade" , font, CHARACTER_SIZE, window);
	drawText(0, auxpos + 25, "Jorge Paiva"  , font, CHARACTER_SIZE, window);
	drawText(0, auxpos + 50, "Pedro Barros" , font, CHARACTER_SIZE, window);
	drawText(0, auxpos + 75, "Gil Fernandes", font, CHARACTER_SIZE, window);
	drawText(15, 475, "> Back", font, 24, window);
}
