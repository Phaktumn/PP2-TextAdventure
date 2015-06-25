#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "RichText.hpp"
#include "gameManager.h"
#include <SFML/Graphics.hpp>

class World
{
public:
	class Location;
	
	struct Path;
	static const struct Path EmptyPath;

	void draw(sf::RenderWindow* window, sf::Font& font);
	void moveTo(const std::string& name);

	bool pathExists(Location* start, Location* end);
	bool circuitExists(Location* location);
	void addLocation(const std::string& name, const std::string& description, int locationLevel);
	void addLocation(const std::string& name, const std::string& description, sfe::RichText displayName, sfe::RichText displayDescription, int locationLevel);
	void connect(const std::string& start, const std::string& dest, int distance, bool twoWay = false);
	Location* getLocation(const std::string& name);
	std::vector<std::string> getCurrentConnections() { return connections;  }
	void debugPrintConnections(const std::string& name);
	std::map<int, Location*> getConnections();

	std::map<int, Location*> path__locations;

private:
	// ==================================================
	// =                   LOCATION	                    =
	// ==================================================

	class Location
	{
	public:
		Location(const std::string& name, const std::string& description, int zoneLevel) :
			_name(name), _description(description), zoneLevel(zoneLevel), hasDisplay(false)
		{ }

		Location(const std::string& name, const std::string& description, sfe::RichText displayName, sfe::RichText displayDescription, int zoneLevel) :
			_name(name), _description(description), _displayName(displayName), _displayDescription(displayDescription), zoneLevel(zoneLevel), hasDisplay(true)
		{ }

		~Location() { }

		std::vector<Path> connections;

		bool hasPath(Location* location)
		{
			for (size_t i = 0; i < connections.size(); i++) {
				if (connections[i].location == location) {
					return true;
				}
			}

			return false;
		}

		std::string getName() { return _name; }
		std::string getDescription() { return _description; }
		sfe::RichText getDisplayName() { return _displayName; }
		sfe::RichText getDisplayDescription(){ return _displayDescription; }

		void addConnection(Path path) { connections.push_back(path); }

		void debugPrintConnections()
		{
			for (size_t i = 0; i < connections.size(); i++) {
				std::cout << connections[i].location->getName() << ": "
					<< connections[i].distance << std::endl;
			}
		}
		int getLocationLevel(){ return zoneLevel; }

		void draw(sf::RenderWindow* window, sf::Font& font);

	private:
		void drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window);
		void drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window);

		std::string _name;
		std::string _description;

		sfe::RichText _displayName;
		sfe::RichText _displayDescription;

		int zoneLevel;

		bool hasDisplay;
	};

	// ==================================================


	struct Path
	{
		int distance;
		Location* location;
	};

	Location* currentLocation;
	std::vector<std::shared_ptr<Location>> locations;
	std::vector<std::string> connections;
};

