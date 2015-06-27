#pragma once

#include <string>
#include "InputBox.h"
#include "World.h"
#include "StateManager.h"
#include "Actor.h"
#include "Player.h"
#include "GameManager.h"
#include "Globals.h"
#include "Inventory.h"
#include <SFML/Audio.hpp>


class GameStateMenu
{
public:
	GameStateMenu(sf::Font& font, InputBox& inputBox, StateManager& stateManager, Player* playerPtr);
	~GameStateMenu();

	sf::Music music;

	bool auxMusic = true;

	void update(InputBox& inputBox, World* world, std::string command);
	void draw(sf::RenderWindow* window, World* world);
	void drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window);
	void drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window);
	bool randomEncounter();

	bool auxPaths;
	bool auxInv;
	bool auxBag;
	bool eqp;

	bool item0;
	bool item1;
	bool item2;
	bool item3;
	bool item4;
	bool item5;

	bool displayItem;

	struct HELPERS
	{
		int HP;
		int STRENGTH;
		int ARMOR;
		int INTELLECT;
		int LEVEL;
		int XP;
		int TXP;
	}_player;


private:
	sf::Font font;

	StateManager& state;

	//Aux variable to display item
	Item* aux;
	Weapon* AuxWep;
	Armor* AuxArmor;
};
