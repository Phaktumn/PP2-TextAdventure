#include "BattleStateMenu.h"


BattleStateMenu::BattleStateMenu(Actor* _player, Actor* _enemy) : player(_player), enemy(_enemy)
{
	inv = false;
	playerPtr = (Player*)player;
}


BattleStateMenu::~BattleStateMenu()
{
}

void BattleStateMenu::update(InputBox* input){
	_player.HP = player->getHp();
	_player.ARMOR = player->getAttribute(ARMOR)->getValue() + player->getAttribute(BONUS_ARMOR)->getValue();
	_player.STRENGTH = player->getAttribute(STRENGTH)->getValue() + player->getAttribute(BONUS_STRENGTH)->getValue();

	_enemy.HP = enemy->getHp();
	_enemy.ARMOR = enemy->getAttribute(ARMOR)->getValue() + enemy->getAttribute(BONUS_ARMOR)->getValue();
	_enemy.STRENGTH = enemy->getAttribute(STRENGTH)->getValue() + enemy->getAttribute(BONUS_STRENGTH)->getValue();

	if (input->lastCommand() == "1"){
		unsigned int _input = atoi(input->lastCommand().c_str());
		player->useAbility(_input);
	}
	if (input->lastCommand() == "2"){
		unsigned int _input = atoi(input->lastCommand().c_str());
		player->useAbility(_input);
	}
	if (input->lastCommand() == "3"){
		unsigned int _input = atoi(input->lastCommand().c_str());
		player->useAbility(_input);
	}
	if (input->lastCommand() == "4"){
		unsigned int _input = atoi(input->lastCommand().c_str());
		player->useAbility(_input);
	}
	if (input->lastCommand() == "5"){
		inv = true;
	}
}

void BattleStateMenu::draw(sf::RenderWindow* window, sf::Font &font){

	if (!inv)
	{
		drawText(BATTLE_PLAYER_NAME_POSITION_X, BATTLE_PLAYER_NAME_POSITION_Y, sfe::RichText(font) << player->getActorName(), CHARACTER_SIZE, window);
		drawText(BATTLE_ENEMY_NAME_POSITION_X, BATTLE_ENEMY_NAME_POSITION_Y, sfe::RichText(font) << enemy->getActorName(), CHARACTER_SIZE, window);

		for (size_t i = 0; i < player->getAbilities().getLength(); i++){
			drawText(15, 315 + i * 25, sfe::RichText(font) << std::to_string(i) << ") " << player->getAbilities().get(i)->getName(), CHARACTER_SIZE, window);
		}
	}
	else
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