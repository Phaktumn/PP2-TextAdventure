#include "World.h"
#include "Globals.h"

void World::draw(sf::RenderWindow* window)
{
	currentLocation->draw(window);
}

void World::moveTo(const std::string& name)
{
	Location* loc = getLocation(name);
	
	if (loc == nullptr) return;
	if (!currentLocation->hasPath(loc)) {
		std::cout << "Current location is not connected to " << name << "." << std::endl;
		return;
	}

	currentLocation = loc;
	std::cout << "Moved to " << loc->getName() << "." << std::endl;
	//TODO: Find all possible paths and show them.
}

void World::addLocation(const std::string& name, const std::string& description)
{
	locations.push_back(std::shared_ptr<Location>(new Location(name, description)));
	if (locations.size() == 1) {
		currentLocation = locations[0].get();
	}
}

void World::addLocation(const std::string& name, const std::string& description, sfe::RichText displayName, sfe::RichText displayDescription)
{
	displayName.setPosition(LOCATION_NAME_POSITION_X, LOCATION_NAME_POSITION_Y);
	displayDescription.setPosition(LOCATION_DESCRIPTION_POSITION_X, LOCATION_DESCRIPTION_POSITION_Y);
	Location* loc = new Location(name, description, displayName, displayDescription);
	
	locations.push_back(std::shared_ptr<Location>(loc));
}

void World::connect(const std::string& start, const std::string& dest, int distance, bool twoWay)
{
	Location* startLoc = getLocation(start);
	Location* destLoc = getLocation(dest);

	if (startLoc == nullptr) {
		printf("Specified start location does not exit.");
		return;
	}

	if (destLoc == nullptr) {
		printf("Specified destination location does not exit.");
		return;
	}

	Path path = Path{ distance, destLoc };
	startLoc->addConnection(path);

	if (!twoWay) return;

	path = Path{ distance, startLoc };
	destLoc->addConnection(path);
}

World::Location* World::getLocation(const std::string& name)
{
	for (size_t i = 0; i < locations.size(); i++) {
		if (locations[i].get()->getName() == name) {
			return locations[i].get();
		}
	}

	return nullptr;
}

void World::debugPrintConnections(const std::string& name)
{
	Location* loc = getLocation(name);
	if (loc == nullptr) return;
	loc->debugPrintConnections();
}

void World::Location::draw(sf::RenderWindow* window)
{
	if (!hasDisplay) return;
	window->draw(_displayName);
	window->draw(_displayDescription);
}