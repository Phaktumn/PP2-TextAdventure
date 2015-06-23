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

	void update(InputBox* input);
	void draw(sf::RenderWindow* window, sf::Font &font);

	void drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window);
	void drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window);
	
	Ability* getUsedHability(Ability* ability){
		return ability;
	}

private:
	///////////////////////////////////////////////////
	///////////////////////////////////////////////////               //
	////////////////////LOG////////////////////////////
	///////////////////////////////////////////////////  
	///////////////////////////////////////////////////
	class LOG
	{
	public:
		LOG();
		~LOG();
		
		void update();
		void draw(sf::RenderWindow* window);

	private:
		
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

	bool inv;
	bool abilitiesScreen;
	bool BattleMenu;

	LOG* log;

	StateManager& state;
	Player* playerPtr;
	Actor* enemy;
};

