#pragma once

#include "Actor.h"
#include "Player.h"
#include "InputBox.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "RichText.hpp"
#include "GameManager.h"
#include "StateManager.h"
#include "Ability.h"
#include "BattleManager.h"

class BattleStateMenu
{
public:
	class LOG;

	BattleStateMenu(Player* player, Actor* enemy, StateManager& state);
	~BattleStateMenu();

	void update(InputBox* input, sf::Font &font);
	void draw(sf::RenderWindow* window, sf::Font &font);

	void drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window);
	void drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window);
	
	void BattleStateMenu::EnemyAI(Actor* enemy);

	Actor* getPlayerInBattle(){ return playerPtr; }
	Actor* getEnemyInBattle(){ return enemy; }

	Ability* getUsedHability(Ability* ability){
		return ability;
	}

private:
	///////////////////////////////////////////////////
	///////////////////////////////////////////////////               
	////////////////////LOG////////////////////////////
	///////////////////////////////////////////////////  
	///////////////////////////////////////////////////
	class LOG
	{
	public:
		LOG();
		~LOG();
		
		void load();
		void update(Ability* ability, sf::Font &font, Actor* enemy, Actor* player);
		void draw(sf::RenderWindow* window, sf::Font &font);

		int lastSeenHP;
		int lastSeenResource;

	private:
		int vector_count;
		void drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window);
		void drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window);
		
		std::vector<sfe::RichText>::iterator iteLog;
		std::vector<sfe::RichText> log;
	};

	//aux helpers aux helpers aux helpers
	//
	//
	struct HELPERS
	{
		int HP;
		int STRENGTH;
		int ARMOR;
	}_player, _enemy;
	//
	//
	//aux helpers aux helpers aux helpers

	double auxCalc(Actor* actor);
	double auxCalcResource(Actor* actor);

	sf::String Resource[10];
	sf::String Hp[10];

	bool inv;
	bool inBattle;
	bool BattleMenu;
	bool isAtacking;

	LOG* log;

	StateManager& state;
	Player* playerPtr;
	Actor* enemy;
};

