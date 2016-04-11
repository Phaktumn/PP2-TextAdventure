#include "Credits.h"


Credits::Credits(sf::Font& font, InputBox& inputBox, StateManager& state) : font(font), state(state), inputBox(inputBox)
{
	auxpos = 500;
}


Credits::~Credits()
{
}


void Credits::load(){}

void Credits::update()
{
	sf::Time elapsed1 = clock.getElapsedTime();

	if (elapsed1.asSeconds() > 0.01f && auxpos > 170){
		auxpos -= 1;
		clock.restart();
	}
	if (inputBox.lastCommand() == "back")
	{
		auxpos = 500;
		activeInput = false;
		state.changeState("TitleMenuState");
	}
}

void Credits::draw(sf::RenderWindow *window) {

	drawText(350, auxpos - 100, "@xxxx[{::::::::::::::::::::::::::::::::::>", font, CHARACTER_SIZE, window);

	drawText(400, auxpos - 50, "IPCA_EDJD_PPII", font, CHARACTER_SIZE, window);

	drawText(390, auxpos     , "Rui Caridade 9949" , font, CHARACTER_SIZE, window);
	drawText(390, auxpos + 50, "Jorge Paiva 10673"  , font, CHARACTER_SIZE, window);
	drawText(390, auxpos + 100, "Pedro Barros 10669" , font, CHARACTER_SIZE, window);
	drawText(390, auxpos + 150, "Gil Fernandes 10844", font, CHARACTER_SIZE, window);

	drawText(350, auxpos +200, "<::::::::::::::::::::::::::::::::::}]xxxx@", font, CHARACTER_SIZE, window);
	                                                          

	drawText(15, 475, "> Back", font, 24, window);
}
