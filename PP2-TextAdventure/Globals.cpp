#include "Globals.h"
#include "LinkedList.h"
#include "Item.h"

sf::String SEPARATOR("+ ----------------------------------------------------------------------------------------------------- +");
bool activeInput = false;
int MAX_ARMOR = 100;

sf::String STRENGTH("Strength");
sf::String BONUS_STRENGTH("Bonus Strength");

sf::String INTELLECT("Intellect");
sf::String BONUS_INTELLECT("Bonus Intellect");

sf::String ARMOR("Armor");
sf::String BONUS_ARMOR("Bonus Armor");

//just a fcking test
std::map<int, sf::String> options;
void addOptions(int i, sf::String asset)
{
	options.emplace(i, asset);
}
sf::String getOption(int i)
{
	return options[i];
}
//just a fcking test
