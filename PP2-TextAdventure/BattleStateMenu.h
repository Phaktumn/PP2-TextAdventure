#pragma once

#include "Actor.h"
#include "Player.h"
#include "InputBox.h"
#include <string>
#include <SFML/Graphics.hpp>
#include "RichText.hpp"
#include "GameManager.h"

class BattleStateMenu
{
public:
	BattleStateMenu(Player* player, Actor* enemy);
	~BattleStateMenu();

	void update(InputBox* input);
	void draw(sf::RenderWindow* window, sf::Font &font);
	
	void drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window);
	void drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window);
private:

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

	Player* playerPtr;
	Actor* enemy;
};

