#include "World.h"
#include "Globals.h"

void World::draw(sf::RenderWindow* window, sf::Font& font)
{
	currentLocation->draw(window, font);
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

	connections.clear();
	for (size_t i = 0; i < currentLocation->connections.size(); i++) {
		connections.push_back(currentLocation->connections[i].location->getName());
	}
}

void World::addLocation(const std::string& name, const std::string& description, int locationLevel)
{
	locations.push_back(std::shared_ptr<Location>(new Location(name, description, locationLevel)));
	if (locations.size() == 1) {
		currentLocation = locations[0].get();
	}
}

void World::addLocation(const std::string& name, const std::string& description, sfe::RichText displayName, sfe::RichText displayDescription, int locationLevel)
{
	displayName.setPosition(LOCATION_NAME_POSITION_X, LOCATION_NAME_POSITION_Y);
	displayDescription.setPosition(LOCATION_DESCRIPTION_POSITION_X, LOCATION_DESCRIPTION_POSITION_Y);
	Location* loc = new Location(name, description, displayName, displayDescription, locationLevel);
	
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

void World::Location::draw(sf::RenderWindow* window, sf::Font& font)
{
 	if (!hasDisplay) return;
	drawText(LOCATION_NAME_POSITION_X + 300, LOCATION_NAME_POSITION_Y, sfe::RichText(font) << "Location NPC LvL: " << sf::Color::Red << std::to_string(zoneLevel), CHARACTER_SIZE, window);
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


void World::Location::drawText(float x, float y, const std::string& text, sf::Font& font, int size, sf::RenderWindow* window){
	sf::Text _text;
	_text.setPosition(x, y);
	_text.setString(text);
	_text.setFont(font);
	_text.setCharacterSize(size);

	window->draw(_text);
}
void World::Location::drawText(float x, float y, sfe::RichText text, int size, sf::RenderWindow* window){
	text.setPosition(x, y);
	text.setCharacterSize(size);

	window->draw(text);
}