#include "Attribute.h"
#include <SFML/Graphics.hpp>


Attribute::Attribute(sf::String _name, int _value)
{
	name = _name;
	value = _value;
}


Attribute::~Attribute()
{

}