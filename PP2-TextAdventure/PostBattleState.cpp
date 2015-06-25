#include "PostBattleState.h"


PostBattleState::PostBattleState(sf::Font& font, InputBox& inputBox, StateManager& state) : font(font), state(state), inputBox(inputBox)
{
	auxloot = false;
}


PostBattleState::~PostBattleState()
{
}

void PostBattleState::load(){}

void PostBattleState::update(){
	_player.LEVEL = GameManager::playerPtr->getLevel();
	_player.XP = GameManager::playerPtr->getXp();
	_player.TXP = GameManager::playerPtr->getTXp();

	if (firstTime)
	{
		srand(time(NULL));
		auxloot = getloot();
		firstTime = false;
	}
	if (inputBox.lastCommand() == "continue")
	{
		state.changeState("GameState");
		auxloot = false;
		firstTime = true;
	}
}

void PostBattleState::draw(sf::RenderWindow *window){

	drawText(310, 20, sfe::RichText(font) << sf::Color::Red << "VICTORIOUS!", CHARACTER_SIZE * 3, window);
	drawText(10, 250, sfe::RichText(font) << "You've earned " << sf::Color::Red << std::to_string(LAST_ENEMY_LEVEL * 100) << " xp.", CHARACTER_SIZE, window);
	drawText(25, 275 , sfe::RichText(font) << "Level: " << sf::Color::Red << std::to_string(_player.LEVEL), CHARACTER_SIZE, window);
	drawText(25, 300 , sfe::RichText(font) << "XP:  " << sf::Color::Red << std::to_string(_player.XP) << " (" << std::to_string(_player.TXP)<< ")", CHARACTER_SIZE, window);

	if (auxloot)
		drawText(10, 350,  "AND you've got some loot too!!!",font, CHARACTER_SIZE, window);
	else 
		drawText(10, 350, "And nothing more...", font,CHARACTER_SIZE, window);


	drawText(15, 475, "> Continue", font, 24, window);
}

bool PostBattleState::getloot(){
	int aux;
	aux = rand() % 100;
	if (aux > 70) return true;
	else return false;
}