#include "BattleState.h"


BattleState::BattleState(sf::Font& font, InputBox& inputBox) : font(font), inputBox(inputBox)
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
	/*
		THE INPUT AS TO BE CHANGED
	*/
	if (inputBox.lastCommand() == "> 1"){
		unsigned int input = atoi(inputBox.lastCommand().c_str());
		player->useAbility(input);
	}
	if (inputBox.lastCommand() == "> 2"){
		unsigned int input = atoi(inputBox.lastCommand().c_str());
		player->useAbility(input);
	}
	if (inputBox.lastCommand() == "> 3"){
		unsigned int input = atoi(inputBox.lastCommand().c_str());
		player->useAbility(input);
	}
	if (inputBox.lastCommand() == "> 4"){
		unsigned int input = atoi(inputBox.lastCommand().c_str());
		player->useAbility(input);
	}
}

void BattleState::draw(sf::RenderWindow* window)
{
	State::draw(window);
	drawText(0, 0, SEPARATOR, font, CHARACTER_SIZE, window);
	drawText(0, 300, SEPARATOR, font, CHARACTER_SIZE, window);
	drawText(0, WINDOW_HEIGHT - 50, SEPARATOR, font, CHARACTER_SIZE, window);
	for (size_t i = 0; i < player->getAbilities().getLength(); i++){
		drawText(15, 300 + i * 25, sfe::RichText(font) << std::to_string(i) << ") " << player->getAbilities().get(i).getName(), CHARACTER_SIZE, window);
	}
	drawText(15, 15, "HI GUYS BATTLE STATE",font, 24, window);
}
