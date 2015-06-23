#include "BattleStateMenu.h"

BattleStateMenu::BattleStateMenu(Player* _player, Actor* _enemy, StateManager& _state) 
: playerPtr(_player), enemy(_enemy), state(_state)
{
	inv = false;
	abilitiesScreen = false;
	BattleMenu = true;
}


BattleStateMenu::~BattleStateMenu()
{
}

void BattleStateMenu::update(InputBox* input){
	_player.HP = playerPtr->getHp();
	_player.ARMOR = playerPtr->getAttribute(ARMOR)->getValue() + playerPtr->getAttribute(BONUS_ARMOR)->getValue();
	_player.STRENGTH = playerPtr->getAttribute(STRENGTH)->getValue() + playerPtr->getAttribute(BONUS_STRENGTH)->getValue();

	_enemy.HP = playerPtr->getHp();
	_enemy.ARMOR = playerPtr->getAttribute(ARMOR)->getValue() + playerPtr->getAttribute(BONUS_ARMOR)->getValue();
	_enemy.STRENGTH = playerPtr->getAttribute(STRENGTH)->getValue() + playerPtr->getAttribute(BONUS_STRENGTH)->getValue();

	//if (input->lastCommand() == "1"){
	//	unsigned int _input = atoi(input->lastCommand().c_str());
	//	player->useAbility(_input);
	//}
	//if (input->lastCommand() == "2"){
	//	unsigned int _input = atoi(input->lastCommand().c_str());
	//	player->useAbility(_input);
	//}
	//if (input->lastCommand() == "3"){
	//	unsigned int _input = atoi(input->lastCommand().c_str());
	//	player->useAbility(_input);
	//}
	//if (input->lastCommand() == "4"){
	//	unsigned int _input = atoi(input->lastCommand().c_str());
	//	player->useAbility(_input);
	//}
	if (input->lastCommand() == "attack"){
		abilitiesScreen = true;
		BattleMenu = false;
		inv = false;
	}
	if (input->lastCommand() == "run away"){
		state.changeState("GameState");
	}
	if (input->lastCommand() == "back"){
		abilitiesScreen = false;
		BattleMenu = true;
		inv = false;
	}
	if (input->lastCommand() == "inventory"){
		inv = true;
		abilitiesScreen = false;
		BattleMenu = false;
	}
	if (abilitiesScreen)
	{
		for (size_t i = 0; i <= playerPtr->getAbilities().getLength(); i++)
		{
			sf::String ability = playerPtr->getAbilities().get(i)->getName();
			std::transform(ability.begin(), ability.end(), ability.begin(), ::tolower);
			if (input->lastCommand() == ability){
				BattleManager::applyDamage(playerPtr, (DamageAbility*)playerPtr->getAbility(ability),enemy);
			}
		}
	}
}

void BattleStateMenu::draw(sf::RenderWindow* window, sf::Font &font){
	if (BattleMenu)
	{
		drawText(15, 325, "> Attack", font, 24, window);
		drawText(15, 350, "> Run Away", font, 24, window);
		drawText(15, 375, "> Inventory", font, 24, window);
	}
	if (abilitiesScreen)
	{
		sf::String auxHP = std::to_string(_player.HP);
		drawText(BATTLE_PLAYER_NAME_POSITION_X, BATTLE_PLAYER_NAME_POSITION_Y, sfe::RichText(font) << sf::Color::Green << "------" << playerPtr->getActorName() << "------", CHARACTER_SIZE, window);
		drawText(BATTLE_PLAYER_NAME_POSITION_X, BATTLE_PLAYER_NAME_POSITION_Y + 50, sfe::RichText(font) << "Hit Points: " << sf::Color::Red << auxHP, CHARACTER_SIZE, window);
		
		drawText(BATTLE_PLAYER_NAME_POSITION_X, BATTLE_PLAYER_NAME_POSITION_Y + 175, sfe::RichText(font) << sf::Color::Blue << "-------------------------------LOG-------------------------------", CHARACTER_SIZE, window);

		log->draw(window);

		drawText(BATTLE_ENEMY_NAME_POSITION_X, BATTLE_ENEMY_NAME_POSITION_Y, sfe::RichText(font) << enemy->getActorName(), CHARACTER_SIZE, window);

		for (size_t i = 0; i <= playerPtr->getAbilities().getLength(); i++){
			drawText(15, 320 + i * 25, sfe::RichText(font) << std::to_string(i) << ") " << playerPtr->getAbilities().get(i)->getName(), CHARACTER_SIZE, window);
		}
		drawText(15, WINDOW_HEIGHT - 75, "> Back", font, 24, window);
	}
	if (inv)
	{
		drawText(BATTLE_PLAYER_NAME_POSITION_X + 300, BATTLE_PLAYER_NAME_POSITION_Y + 25, "ATRIBUTES", font, CHARACTER_SIZE, window);
		drawText(BATTLE_PLAYER_NAME_POSITION_X + 300, BATTLE_PLAYER_NAME_POSITION_Y + 50,
			sfe::RichText(font) << "Unleash the " << STRENGTH << ": " << sf::Color::Red << std::to_string(_player.STRENGTH), CHARACTER_SIZE, window);
		drawText(BATTLE_PLAYER_NAME_POSITION_X + 300, BATTLE_PLAYER_NAME_POSITION_Y + 75,
			sfe::RichText(font) << "Unleash the " << ARMOR << ": " << sf::Color::Red << std::to_string(_player.ARMOR), CHARACTER_SIZE, window);
		drawText(BATTLE_PLAYER_NAME_POSITION_X + 300, BATTLE_PLAYER_NAME_POSITION_Y + 100,
			sfe::RichText(font) << "Unleash the HitPoints" << ": " << sf::Color::Red << std::to_string(_player.HP), CHARACTER_SIZE, window);

		playerPtr->getInventory()->draw(window, font);
	}
}

void BattleStateMenu::drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window){
	sf::Text _text;
	_text.setPosition(x, y);
	_text.setString(text);
	_text.setFont(font);
	_text.setCharacterSize(size);

	window->draw(_text);
}
void BattleStateMenu::drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window){
	text.setPosition(x, y);
	text.setCharacterSize(size);

	window->draw(text);
}


void BattleStateMenu::LOG::update(){

}

void BattleStateMenu::LOG::draw(sf::RenderWindow* window){

}