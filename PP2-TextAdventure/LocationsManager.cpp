#include "LocationsManager.h" 
#include "RichText.hpp"

LocationsManager::LocationsManager(World* _world, sf::Font& _font)
:world(_world), font(_font)
{}

void LocationsManager::AddLocations(){

	sfe::RichText titleFont(font);
	titleFont.setCharacterSize(BIG_CHARACTER_SIZE);

	sfe::RichText descriptionFont(font);
	descriptionFont.setCharacterSize(NORMAL_CHARACTER_SIZE);

	/*world->addLocation(GameManager::getLocationName(0), "Descrição Local 1", 
		titleFont << sf::Color::Cyan << GameManager::getLocationName(0), 
		descriptionFont << "This Is a Mindfull place... \nGet ready to fullfill your " << sf::Color::Blue << "Dreams"
		<< sf::Color::White << " as you get to sleep!!!");*/    

	for (size_t i = 0; i < GameManager::locationDatabase.size(); i++){
		world->addLocation(GameManager::getLocationName(i), GameManager::getLocationDescription(i), 
			titleFont << GameManager::getLocationName(i), descriptionFont << GameManager::getLocationDescription(i), GameManager::getLocationLevel(i));

		titleFont.clear();
		descriptionFont.clear();
	}
}


void LocationsManager::AddConnections(){
	world->connect(GameManager::getLocationName(0), GameManager::getLocationName(1), 10, false);
	world->connect(GameManager::getLocationName(0), GameManager::getLocationName(2), 43, false);
	world->connect(GameManager::getLocationName(0), GameManager::getLocationName(3), 14, true);

	world->connect(GameManager::getLocationName(1), GameManager::getLocationName(5), 10, false);
	world->connect(GameManager::getLocationName(1), GameManager::getLocationName(6), 43, false);
	
	world->connect(GameManager::getLocationName(2), GameManager::getLocationName(6), 10, false);
	
	world->connect(GameManager::getLocationName(3), GameManager::getLocationName(4), 10, true);

	world->connect(GameManager::getLocationName(4), GameManager::getLocationName(8), 10, true);
	world->connect(GameManager::getLocationName(4), GameManager::getLocationName(9), 43, false);

	world->connect(GameManager::getLocationName(5), GameManager::getLocationName(4), 10, false);

	world->connect(GameManager::getLocationName(6), GameManager::getLocationName(7), 10, false);
	
	world->connect(GameManager::getLocationName(7), GameManager::getLocationName(5), 10, false);
	

}

void LocationsManager::load(){
	AddLocations();
	AddConnections();
}



