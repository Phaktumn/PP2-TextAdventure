#include "Inventory.h"

Inventory::Inventory(Player* player) : player(player)
{

}


Inventory::~Inventory()
{

}

void Inventory::equipWeapon(Weapon* _weapon)
{
	if (weapon != nullptr){
		player->removeBonusIntellect(_weapon->getBonusIntellevt());
		player->removeBonusDamage(_weapon->getBonusStrenght());
	}

	weapon = _weapon;

	player->addBonusDamage(_weapon->getBonusStrenght());
	player->addBonusIntellect(_weapon->getBonusIntellevt());
}

void Inventory::equipArmor(Armor* armor, Armor::Type type)
{
	switch (type)
	{
	case Item::helmet:
	{
						 //removes the armor of the last equiped head
						 if (head != nullptr)
							 player->removeBonusArmor(head->getBonusArmor());

						 //replaces de head item for a new one
						 head = armor;

						 //add's the new stats to the player
						 player->addBonusArmor(head->getBonusArmor());
	}
		break;
	case Item::chest:{
						 if (chest != nullptr)
							 player->removeBonusArmor(chest->getBonusArmor());
						 chest = armor;
						 player->addBonusArmor(chest->getBonusArmor());
	}
		break;
	case Item::hands:{
						 if (hands != nullptr)
							 player->removeBonusArmor(chest->getBonusArmor());
						 hands = armor;
						 player->addBonusArmor(hands->getBonusArmor());
	}
		break;
	case Item::legs:{
						if (legs != nullptr)
							player->removeBonusArmor(legs->getBonusArmor());
						legs = armor;
						player->addBonusArmor(legs->getBonusArmor());
	}
		break;
	case Item::feet:{
						if (feet != nullptr)
							player->removeBonusArmor(feet->getBonusArmor());
						feet = armor;
						player->addBonusArmor(feet->getBonusArmor());
	}
		break;
	}
}

void Inventory::draw(sf::RenderWindow* window, sf::Font &font){
	if (head != nullptr){
		drawText(20, 20, "Head: ", font, 24, window);
		head->draw(window, &font, 100, 20);
	}
	else drawText(20, 20, "Head: No Item", font, 24, window);

	if (chest != nullptr){
		drawText(20, 40, "Chest: ", font, 24, window);
		chest->draw(window, &font, 100, 40);
	}
	else drawText(20, 40, "Chest: No Item", font, 24, window);

	if (hands != nullptr){
		drawText(20, 60, "Hands: ", font, 24, window);
		hands->draw(window, &font, 100, 60);
	}
	else drawText(20, 60, "Hands: No Item", font, 24, window);

	if (weapon != nullptr){
		drawText(20, 80, "Weapon: ", font, 24, window);
		weapon->draw(window, &font, 110, 83);
	}
	else drawText(20, 80, "Weapon: No Item", font, 24, window);

	if (legs != nullptr){
		drawText(20, 100, "Legs: ", font, 24, window);
		legs->draw(window, &font, 100, 100);
	}
	else drawText(20, 100, "Legs: No Item", font, 24, window);

	if (feet != nullptr){
		drawText(20, 120, "Feet: ", font, 24, window);
		feet->draw(window, &font, 100, 120);
	}
	else drawText(20, 120, "Feet: No Item", font, 24, window);
}


void Inventory::drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window){
	sf::Text _text;
	_text.setPosition(x, y);
	_text.setString(text);
	_text.setFont(font);
	_text.setCharacterSize(size);

	window->draw(_text);
}
void Inventory::drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window){
	text.setPosition(x, y);
	text.setCharacterSize(size);

	window->draw(text);
}
