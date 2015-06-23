#include "BattleStateMenu.h"



BattleStateMenu::BattleStateMenu(Player* _player, Actor* _enemy, StateManager& _state) 
: playerPtr(_player), enemy(_enemy), state(_state)
{
	inv = false;
	abilitiesScreen = false;
	BattleMenu = true;
	isAtacking = false;
	log = new LOG();
}


BattleStateMenu::~BattleStateMenu()
{
}

BattleStateMenu::LOG::LOG(){
	vector_count = 0;
}

BattleStateMenu::LOG::~LOG(){}

void BattleStateMenu::update(InputBox* input, sf::Font &font){
	_player.HP = playerPtr->getHp();
	_player.ARMOR = playerPtr->getAttribute(ARMOR)->getValue() + playerPtr->getAttribute(BONUS_ARMOR)->getValue();
	_player.STRENGTH = playerPtr->getAttribute(STRENGTH)->getValue() + playerPtr->getAttribute(BONUS_STRENGTH)->getValue();

	_enemy.HP = enemy->getHp();
	_enemy.ARMOR = enemy->getAttribute(ARMOR)->getValue();
	_enemy.STRENGTH = enemy->getAttribute(STRENGTH)->getValue();

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
		isAtacking = true;
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
	if (abilitiesScreen && isAtacking)
	{
		for (size_t i = 0; i <= playerPtr->getAbilities().getLength(); i++)
		{
			sf::String _ability = playerPtr->getAbilities().get(i)->getName();
			sf::String ability_transform = playerPtr->getAbilities().get(i)->getName();
			std::transform(ability_transform.begin(), ability_transform.end(), ability_transform.begin(), ::tolower);
			if (input->lastCommand() == ability_transform){
				BattleManager::applyDamage(playerPtr,(DamageAbility*)playerPtr->getAbility(_ability),enemy);
				isAtacking = false;
				abilitiesScreen = false;
				BattleMenu = true;
				log->update((DamageAbility*)playerPtr->getAbility(_ability), font);
			}
		}
	}
}

void BattleStateMenu::draw(sf::RenderWindow* window, sf::Font &font){
	if (BattleMenu)
	{
		sf::String targetAxuHP = std::to_string(_enemy.HP);
		drawText(BATTLE_ENEMY_NAME_POSITION_X-100, BATTLE_ENEMY_NAME_POSITION_Y, sfe::RichText(font) << sf::Color::Red << "------:: " << enemy->getActorName() << " ::------", CHARACTER_SIZE, window);
		drawText(BATTLE_ENEMY_NAME_POSITION_X-100, BATTLE_ENEMY_NAME_POSITION_Y + 50, sfe::RichText(font) << "Hit Points: " << sf::Color::Red << targetAxuHP, CHARACTER_SIZE, window);

		drawText(BATTLE_ENEMY_NAME_POSITION_X - 100, BATTLE_ENEMY_NAME_POSITION_Y + 75, "ATRIBUTES", font, CHARACTER_SIZE, window);
		drawText(BATTLE_ENEMY_NAME_POSITION_X - 100, BATTLE_ENEMY_NAME_POSITION_Y + 100,
			sfe::RichText(font) << "Unleash the " << STRENGTH << ": " << sf::Color::Red << std::to_string(_enemy.STRENGTH), CHARACTER_SIZE, window);
		drawText(BATTLE_ENEMY_NAME_POSITION_X - 100, BATTLE_ENEMY_NAME_POSITION_Y + 125,
			sfe::RichText(font) << "Unleash the " << ARMOR << ": " << sf::Color::Red << std::to_string(_enemy.ARMOR), CHARACTER_SIZE, window);
		drawText(BATTLE_ENEMY_NAME_POSITION_X - 100, BATTLE_ENEMY_NAME_POSITION_Y + 150,
			sfe::RichText(font) << "Unleash the HitPoints" << ": " << sf::Color::Red << std::to_string(_enemy.HP), CHARACTER_SIZE, window);


		drawText(15, 325, "> Attack", font, 24, window);
		drawText(15, 350, "> Run Away", font, 24, window);
		drawText(15, 375, "> Inventory", font, 24, window);
	}
	if (abilitiesScreen)
	{
		sf::String auxHP = std::to_string(_player.HP);
		drawText(BATTLE_PLAYER_NAME_POSITION_X, BATTLE_PLAYER_NAME_POSITION_Y, sfe::RichText(font) << sf::Color::Green << "------" << playerPtr->getActorName() << "------", CHARACTER_SIZE, window);
		drawText(BATTLE_PLAYER_NAME_POSITION_X, BATTLE_PLAYER_NAME_POSITION_Y + 50, sfe::RichText(font) << "Hit Points: " << sf::Color::Red << auxHP, CHARACTER_SIZE, window);
		
		log->draw(window, font);

		sf::String targetAxuHP = std::to_string(_enemy.HP);
		drawText(BATTLE_ENEMY_NAME_POSITION_X, BATTLE_ENEMY_NAME_POSITION_Y, sfe::RichText(font) << sf::Color::Red << "------:: " << enemy->getActorName() << " ::------", CHARACTER_SIZE, window);
		drawText(BATTLE_ENEMY_NAME_POSITION_X, BATTLE_ENEMY_NAME_POSITION_Y + 50, sfe::RichText(font) << "Hit Points: " << sf::Color::Red << targetAxuHP, CHARACTER_SIZE, window);

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




void BattleStateMenu::LOG::drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window){
	sf::Text _text;
	_text.setPosition(x, y);
	_text.setString(text);
	_text.setFont(font);
	_text.setCharacterSize(size);

	window->draw(_text);
}
void BattleStateMenu::LOG::drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window){
	text.setPosition(x, y);
	text.setCharacterSize(size);

	window->draw(text);
}

void BattleStateMenu::LOG::load(){

}

void BattleStateMenu::LOG::update(Ability* ability, sf::Font &font){
	sfe::RichText text(font);
	text << "Used Ability-> " << sf::Color::Red << ability->getName() << "  ::Damage Dealt: " << sf::Color::Blue << "DUNNO DEV SHIT";
	vector_count++;
	iteLog = log.begin();
	iteLog = log.insert(iteLog, text);
	if (vector_count > 3){
		log.pop_back();
	}
}

void BattleStateMenu::LOG::draw(sf::RenderWindow* window, sf::Font &font){
	drawText(BATTLE_PLAYER_NAME_POSITION_X, BATTLE_PLAYER_NAME_POSITION_Y + 150, sfe::RichText(font) << sf::Color::Blue << "----------------------------------------LOG----------------------------------------", CHARACTER_SIZE, window);
	sfe::RichText text(font);
	for (size_t i = 0; i < log.size(); i++){
		text = log[i];
		drawText(BATTLE_PLAYER_NAME_POSITION_X, BATTLE_PLAYER_NAME_POSITION_Y + 175 + (i * 25), text, CHARACTER_SIZE, window);
	}
}
