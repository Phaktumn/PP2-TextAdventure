#include "Globals.h"
#include "LinkedList.h"
#include "Item.h"

int WINDOW_WIDTH = 960;
int WINDOW_HEIGHT = 540;
sf::String SEPARATOR("+ ----------------------------------------------------------------------------------------------------- +");
bool activeInput = false;
int MAX_ARMOR = 100;

sf::String STRENGTH("Strength");
sf::String INTELLECT("Intellect");
sf::String ARMOR("Armor");

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
