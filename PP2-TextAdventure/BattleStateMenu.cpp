#include "BattleStateMenu.h"



BattleStateMenu::BattleStateMenu(Player* _player, Actor* _enemy, StateManager& _state) 
: playerPtr(_player), enemy(_enemy), state(_state)
{
	inv = false;
	inBattle = false;
	BattleMenu = true;
	isAtacking = false;
	log = new LOG();

	Resource[9] = "[: : : : : : : : : :]";
	Resource[8] = "[: : : : : : : : :  ]";
	Resource[7] = "[: : : : : : : :    ]";
	Resource[6] = "[: : : : : : :     ]";
	Resource[5] = "[: : : : : :      ]";
	Resource[4] = "[: : : : :       ]";
	Resource[3] = "[: : : :        ]";
	Resource[2] = "[: : :         ]";
	Resource[1] = "[: :          ]";
	Resource[0] = "[:           ]";

	Hp[9] = "[: : : : : : : : : :]";
	Hp[8] = "[: : : : : : : : :  ]";
	Hp[7] = "[: : : : : : : :    ]";
	Hp[6] = "[: : : : : : :     ]";
	Hp[5] = "[: : : : : :      ]";
	Hp[4] = "[: : : : :       ]";
	Hp[3] = "[: : : :        ]";
	Hp[2] = "[: : :         ]";
	Hp[1] = "[: :          ]";
	Hp[0] = "[:		      ]";
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


	

	if (input->lastCommand() == "attack"){
		inBattle = true;
		BattleMenu = false;
		inv = false;
		input->log.push_back("-1");
		playerPtr->update();
	}
	if (input->lastCommand() == "run away"){
		state.changeState("GameState");
		playerPtr->update();
		input->log.push_back("-1");
		playerPtr->update();
	}
	if (input->lastCommand() == "back"){
		inBattle = false;
		BattleMenu = true;
		inv = false;
		input->log.push_back("-1");
		playerPtr->update();
	}
	if (input->lastCommand() == "inventory"){
		inv = true;
		inBattle = false;
		BattleMenu = false;
		input->log.push_back("-1");
		playerPtr->update();
	}
	if (inBattle)
	{
		log->lastSeenHP = enemy->getHp();
		for (size_t i = 0; i <= playerPtr->getAbilities().getLength(); i++)
		{
			sf::String _ability = playerPtr->getAbilities().get(i)->getName();
			sf::String ability_transform = playerPtr->getAbilities().get(i)->getName();
			std::transform(ability_transform.begin(), ability_transform.end(), ability_transform.begin(), ::tolower);
			if (input->lastCommand() == ability_transform){
				BattleManager::applyDamage(playerPtr,(DamageAbility*)playerPtr->getAbility(_ability),enemy);
				inBattle = true;
				BattleMenu = false;
				log->update((DamageAbility*)playerPtr->getAbility(_ability), font, enemy);
				input->log.push_back("-1");
				playerPtr->update();
			}
		}
	}
}

double BattleStateMenu::auxCalc(Actor* actor){
	int maxHP = actor->getMaxHP();
	return ((actor->getHp() * 9) / maxHP);
}

void BattleStateMenu::draw(sf::RenderWindow* window, sf::Font &font){
	if (BattleMenu)
	{
		sf::String targetAxuHP = std::to_string(_enemy.HP);
		drawText(BATTLE_ENEMY_NAME_POSITION_X-150, BATTLE_ENEMY_NAME_POSITION_Y, sfe::RichText(font) << sf::Color::Red << "------:: " << enemy->getActorName() << " ::------", CHARACTER_SIZE, window);
		drawText(BATTLE_ENEMY_NAME_POSITION_X-150, BATTLE_ENEMY_NAME_POSITION_Y + 50, sfe::RichText(font) << "Hit Points: " << sf::Color::Red << targetAxuHP, CHARACTER_SIZE, window);

		drawText(BATTLE_ENEMY_NAME_POSITION_X - 150, BATTLE_ENEMY_NAME_POSITION_Y + 75, "ATRIBUTES", font, CHARACTER_SIZE, window);
		drawText(BATTLE_ENEMY_NAME_POSITION_X - 150, BATTLE_ENEMY_NAME_POSITION_Y + 100,
			sfe::RichText(font) << "Unleash the " << STRENGTH << ": " << sf::Color::Red << std::to_string(_enemy.STRENGTH), CHARACTER_SIZE, window);
		drawText(BATTLE_ENEMY_NAME_POSITION_X - 150, BATTLE_ENEMY_NAME_POSITION_Y + 125,
			sfe::RichText(font) << "Unleash the " << ARMOR << ": " << sf::Color::Red << std::to_string(_enemy.ARMOR), CHARACTER_SIZE, window);
		drawText(BATTLE_ENEMY_NAME_POSITION_X - 150, BATTLE_ENEMY_NAME_POSITION_Y + 150,
			sfe::RichText(font) << "Unleash the HitPoints" << ": " << sf::Color::Red << std::to_string(_enemy.HP), CHARACTER_SIZE, window);


		drawText(15, 325, "> Attack", font, 24, window);
		drawText(15, 350, "> Run Away", font, 24, window);
		drawText(15, 375, "> Inventory", font, 24, window);
	}
	if (inBattle)
	{
		sf::String auxHP = std::to_string(_player.HP);
		drawText(BATTLE_PLAYER_NAME_POSITION_X, BATTLE_PLAYER_NAME_POSITION_Y, sfe::RichText(font) << sf::Color::Green << "------" << playerPtr->getActorName() << "------", CHARACTER_SIZE, window);
		drawText(BATTLE_PLAYER_NAME_POSITION_X, BATTLE_PLAYER_NAME_POSITION_Y + 50, sfe::RichText(font) << "Hit Points: " << sf::Color::Red << auxHP, CHARACTER_SIZE, window);
		drawText(BATTLE_PLAYER_NAME_POSITION_X, BATTLE_PLAYER_NAME_POSITION_Y + 75, sfe::RichText(font) << sf::Color::Green << Hp[(int)round(abs(auxCalc(playerPtr)))], CHARACTER_SIZE, window);
		
		log->draw(window, font);

		sf::String targetAxuHP = std::to_string(_enemy.HP);
		drawText(BATTLE_ENEMY_NAME_POSITION_X, BATTLE_ENEMY_NAME_POSITION_Y, sfe::RichText(font) << sf::Color::Red << "------:: " << enemy->getActorName() << " ::------", CHARACTER_SIZE, window);
		drawText(BATTLE_ENEMY_NAME_POSITION_X, BATTLE_ENEMY_NAME_POSITION_Y + 50, sfe::RichText(font) << "Hit Points: " << sf::Color::Red << targetAxuHP, CHARACTER_SIZE, window);
		drawText(BATTLE_ENEMY_NAME_POSITION_X, BATTLE_ENEMY_NAME_POSITION_Y + 75, sfe::RichText(font) << sf::Color::Green << Hp[(int)round(abs(auxCalc(enemy)))] , CHARACTER_SIZE, window);

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

void BattleStateMenu::LOG::update(Ability* ability, sf::Font &font, Actor* enemy){

	sfe::RichText text(font);
	text << "Used Ability-> " << sf::Color::Red << ability->getName() << "  ::Damage Dealt: " << sf::Color::Blue << std::to_string(lastSeenHP - enemy->getHp());
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
