#include "World.h"
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"

#pragma once
class LocationsManager
{
public:

	LocationsManager(World* world, sf::Font& font);


	void load();

private:
	void AddLocations();
	void AddConnections();

	sf::Font& font;

	World* world;
};

