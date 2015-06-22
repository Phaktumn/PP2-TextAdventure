#include "BattleState.h"


BattleState::BattleState(sf::Font& font, InputBox& inputBox) : font(font), inputBox(inputBox)
{
	player = new Player("jorge", GameManager::attribute, GameManager::abilities, 1000, 250);
	shit = new Actor("well", GameManager::attribute, GameManager::abilities, 1000, 250);
	battleMenu = new BattleStateMenu(player, shit);
}


BattleState::~BattleState()
{

}

void BattleState::load()
{
	playerPtr = (Player*)player;
}

void BattleState::update()
{
	playerPtr->getInventory()->equipWeapon((Weapon*)GameManager::getItem("Shiva's Parashu"));
	playerPtr->getInventory()->equipArmor((Armor*)GameManager::getItem("Titan's Outlook"), GameManager::getItem("Titan's Outlook")->type);
	battleMenu->update(&inputBox);
}

void BattleState::draw(sf::RenderWindow* window)
{
	State::draw(window);
	drawText(0, 0, SEPARATOR, font, CHARACTER_SIZE, window);
	drawText(0, 300, SEPARATOR, font, CHARACTER_SIZE, window);
	drawText(0, WINDOW_HEIGHT - 50, SEPARATOR, font, CHARACTER_SIZE, window);

	battleMenu->draw(window, font);
}
