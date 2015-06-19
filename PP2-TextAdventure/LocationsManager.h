#include "World.h"
#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"

#pragma once
class LocationsManager
{
public:
	LocationsManager(World* World, sf::Font font);
	~LocationsManager();

	void load();

private:
	void AddLocations();
	void AddConnections();

	sf::Font font;

	World* world;
};

