#include "Inventory.h"

LinkedList<Item*> Inventory::bag;
LinkedList<Item*> Inventory::getBag(){ return bag; }

Inventory::Inventory(Player* player) : player(player)
{

}

Inventory::~Inventory()
{

}

void Inventory::equipWeapon(Weapon* _weapon)
{
	if (weapon != nullptr){
		player->removeBonusIntellect(weapon->getBonusIntellevt());
		player->removeBonusDamage(weapon->getBonusStrenght());
		player->removeDamage(weapon->getWeaponDamage());
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
						 {
							 player->removeBonusArmor(head->getBonusArmor());
							 player->removeBonusDamage(head->getBonusStrenght());
							 player->removeBonusIntellect(head->getBonusIntellevt());
						 }

						 //replaces de head item for a new one
						 head = armor;

						 //add's the new stats to the player
						 player->addBonusArmor(head->getBonusArmor());
						 player->addBonusDamage(head->getBonusStrenght());
						 player->addBonusIntellect(head->getBonusIntellevt());
	}
		break;
	case Item::chest:{
						 if (chest != nullptr)
						 {
							 player->removeBonusArmor(chest->getBonusArmor());
							 player->removeBonusDamage(chest->getBonusStrenght());
							 player->removeBonusIntellect(chest->getBonusIntellevt());
						 }
						 chest = armor;
						 player->addBonusArmor(chest->getBonusArmor());
						 player->addBonusDamage(chest->getBonusStrenght());
						 player->addBonusIntellect(chest->getBonusIntellevt());
	}
		break;
	case Item::hands:{
						 if (hands != nullptr){
							 player->removeBonusArmor(hands->getBonusArmor());
							 player->removeBonusDamage(hands->getBonusStrenght());
							 player->removeBonusIntellect(hands->getBonusIntellevt());
						 }
						 hands = armor;
						 player->addBonusArmor(hands->getBonusArmor());
						 player->addBonusDamage(hands->getBonusStrenght());
						 player->addBonusIntellect(hands->getBonusIntellevt());
	}
		break;
	case Item::legs:{
						if (legs != nullptr)
						{
							player->removeBonusArmor(legs->getBonusArmor());
							player->removeBonusArmor(legs->getBonusIntellevt());
							player->removeBonusIntellect(legs->getBonusIntellevt());
						}
						legs = armor;
						player->addBonusArmor(legs->getBonusArmor());
						player->addBonusDamage(legs->getBonusStrenght());
						player->addBonusIntellect(legs->getBonusIntellevt());
	}
		break;
	case Item::feet:{
						if (feet != nullptr){
							player->removeBonusArmor(feet->getBonusArmor());
							player->removeBonusDamage(feet->getBonusStrenght());
							player->removeBonusIntellect(feet->getBonusIntellevt());
						}
						feet = armor;
						player->addBonusArmor(feet->getBonusArmor());
						player->addBonusDamage(feet->getBonusStrenght());
						player->addBonusIntellect(feet->getBonusIntellevt());
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
		head->draw(window, &font, 100, y);
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


void Inventory::drawBag(sf::RenderWindow* window, sf::Font &font){

	int positionY = 20;
	int positionX = 20;
	int count_AUX = 0;

	for (size_t i = 0; i <= _BAG_MAX_SLOTS; i++)
	{
		sf::String item_num = std::to_string(i);
		if (bag.get(i) == nullptr) {
			count_AUX++;
			positionY = (count_AUX * 40);
			drawText(positionX, positionY, sfe::RichText(font) << item_num << ") No Item", CHARACTER_SIZE, window);
			if (positionY >= 250){
				positionX = 450;
				positionY = 20;
				count_AUX = 0;
			}
		}
		else
		{
			//
			sf::String item_type = std::to_string(bag.get(i)->type);
			count_AUX++;
			positionY = (count_AUX * 40);
			drawText(positionX, positionY, sfe::RichText(font) << item_num << ") " , CHARACTER_SIZE, window);
			bag.get(i)->draw(window, &font, positionX + 25, positionY);
			if (positionY >= 325){
				positionX = 450;
				positionY = 20;
				count_AUX = 0;
			}
		}
	}
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

bool Inventory::addToBags(Item* _item){
	if (_item == nullptr) return false;

	if (bag.getLength() + 1 > _BAG_MAX_SLOTS){
		return false;
	}

	bag.add(_item);
	return true;
}
void Inventory::removeFromBags(Item* item)
{
	if (item == nullptr)
	{
		return;
	}

	bag.remove(item);
}