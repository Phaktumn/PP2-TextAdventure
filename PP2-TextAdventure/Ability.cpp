#include "Ability.h"
#include <SFML\Graphics.hpp>


Ability::Ability(sf::String _name, int _value)
{
	name = _name;
	value = _value;
}


Ability::~Ability()
{

}
