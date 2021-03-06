#include "PostBattleState.h"


PostBattleState::PostBattleState(sf::Font& font, InputBox& inputBox, StateManager& state) : font(font), state(state), inputBox(inputBox)
{
	auxloot = false;
	droped = false;
	firstTime = true;
}


PostBattleState::~PostBattleState()
{
}

void PostBattleState::load(){}

void PostBattleState::update(){
	if (auxMusic)
	{
		if (!music.openFromFile("songs/WinCheer.ogg")){ std::cout << "ERROR" << std::endl; } // error
		auxMusic = false;
		music.play();
	}
	_player.LEVEL = GameManager::playerPtr->getLevel();
	_player.XP = GameManager::playerPtr->getXp();
	_player.TXP = GameManager::playerPtr->getTXp();

	if (firstTime)
	{
		srand(time(NULL));
		auxloot = CALCgetloot();
		firstTime = false;
	}
	if (inputBox.lastCommand() == "continue")
	{
		music.stop();
		auxMusic = true;
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
	{
		drawText(10, 350, sfe::RichText(font) << "AND you've got some loot too!!!", CHARACTER_SIZE, window);
		dropedItem->draw(window, &font, 10, 380);
	}
	else drawText(10, 350, "And nothing more...", font,CHARACTER_SIZE, window);

	drawText(15, 475, "> Continue", font, 24, window);
}

void PostBattleState::getDrop()
{
	int auxRand = genRand();
	dropedItem = GameManager::getItem(auxRand);
	if (GameManager::playerPtr->getInventory()->addToBags(dropedItem)){
		return;
	}
	else{
		auxloot = false;
	}
}

bool PostBattleState::CALCgetloot(){
	int aux;
	aux = rand() % 100;
	if (aux > 0) {
		getDrop();
		return true;
	}
	else return false;
}

int PostBattleState::genRand(){
	int _rand;
	srand(time(NULL));
	_rand = rand() % GameManager::itemDatabase.size();
	return _rand;
}

