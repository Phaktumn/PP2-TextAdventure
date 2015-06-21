#include "World.h"
#include "Globals.h"

void World::draw(sf::RenderWindow* window)
{
	std::cout << currentLocation->getName();
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

	if (locations.size() == 1){
		currentLocation = locations[0].get();
	}
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

std::map<int, World::Location*> World::getConnections()
{
	Location* loc = currentLocation;
	path__locations.clear();
	int i = 0, std_map__counter = 0;
	while (true)
	{
		if (GameManager::getLocationName(i) == "") break;
		if (loc->hasPath(getLocation(GameManager::getLocationName(i))))
		{
			path__locations.emplace(std_map__counter, getLocation(GameManager::getLocationName(i)));
			std_map__counter++;
		}
		i++;
	}
	return path__locations;
}

bool World::circuitExists(Location* location)
{
	bool circuitExists = false;

	for (size_t i = 0; i < location->connections.size(); i++) {
		circuitExists = pathExists(location->connections[i].location, location);
		if (circuitExists) { return circuitExists; }
	}

	return circuitExists;
}

bool World::pathExists(Location* start, Location* end)
{
	bool exists = false;

	for (size_t i = 0; i < start->connections.size(); i++) {
		if (start->connections[i].location == end) {
			return true;
		}

		exists = true * pathExists(start->connections[i].location, end);
	}

	return exists;
}