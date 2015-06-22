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
		player->removeDamage(_weapon->getWeaponDamage());
	}

	weapon = _weapon;

	player->addBonusDamage(_weapon->getBonusStrenght());
	player->addBonusIntellect(_weapon->getBonusIntellevt());
	player->setDamage(_weapon->getWeaponDamage());
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

void Inventory::drawPos(sf::RenderWindow* window, sf::Font &font, int x, int y){
	if (head != nullptr){
		drawText(x, y, "Head: ", font, 24, window);
		head->draw(window, &font, 100, 20);
	}
	else drawText(x, y, "Head: No Item", font, 24, window);

	if (chest != nullptr){
		drawText(x, y + 20, "Chest: ", font, 24, window);
		chest->draw(window, &font, 100, y + 20);
	}
	else drawText(x, y + 20, "Chest: No Item", font, 24, window);

	if (hands != nullptr){
		drawText(x, y + 40, "Hands: ", font, 24, window);
		hands->draw(window, &font, 100, y + 40);
	}
	else drawText(x, y + 40, "Hands: No Item", font, 24, window);

	if (weapon != nullptr){
		drawText(x, y + 60, "Weapon: ", font, 24, window);
		weapon->draw(window, &font, 110, y + 63);
	}
	else drawText(x, y + 60, "Weapon: No Item", font, 24, window);

	if (legs != nullptr){
		drawText(x, y + 80, "Legs: ", font, 24, window);
		legs->draw(window, &font, 100, y + 80);
	}
	else drawText(x, y + 80, "Legs: No Item", font, 24, window);

	if (feet != nullptr){
		drawText(x, y + 100, "Feet: ", font, 24, window);
		feet->draw(window, &font, 100, y + 100);
	}
	else drawText(x, y + 100, "Feet: No Item", font, 24, window);
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

Weapon* Inventory::getEquipedWeapon()
{
	if (weapon!=nullptr)
		return weapon;
	else{
		return nullptr;
	}
}
