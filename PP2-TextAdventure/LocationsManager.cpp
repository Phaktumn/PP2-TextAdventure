#include "LocationsManager.h" 

LocationsManager::LocationsManager(World* _world, sf::Font _font) 
	: world(_world), font(_font)
{ }

LocationsManager::~LocationsManager(){}

void LocationsManager::AddLocations(){

	sfe::RichText titleFont(font);
	titleFont.setCharacterSize(BIG_CHARACTER_SIZE);

	sfe::RichText descriptionFont(font);
	descriptionFont.setCharacterSize(NORMAL_CHARACTER_SIZE);

	world->addLocation(GameManager::getLocationName(0), "Descrição Local 1", 
		titleFont << sf::Color::Cyan << GameManager::getLocationName(0), 
		descriptionFont << "This Is a Mindfull place... \nGet ready to fullfill your " << sf::Color::Blue << "Dreams"
		<< sf::Color::White << "as you get to sleep!!!");    

	world->addLocation(GameManager::getLocationName(1), "Descrição Local 2",
		titleFont << sf::Color::Cyan << GameManager::getLocationName(1),
		descriptionFont << "1 This jungle is made out of monkeys and seriously, like, everyone here is"
		<< sf::Color::Red << " BATSHIT " << sf::Color::White << "insane. \nMan, fuck me."
		);

	world->addLocation(GameManager::getLocationName(2), "Descrição Local 3");
	world->addLocation(GameManager::getLocationName(3), "Descrição Local 4");
	world->addLocation(GameManager::getLocationName(4), "Descrição Local 5");
	world->addLocation(GameManager::getLocationName(5), "dasldasd");


}


void LocationsManager::AddConnections(){
	world->connect(GameManager::getLocationName(0), GameManager::getLocationName(1), 10, false);
	world->connect(GameManager::getLocationName(0), GameManager::getLocationName(2), 43, false);
	world->connect(GameManager::getLocationName(0), GameManager::getLocationName(3), 14, false);
	world->connect(GameManager::getLocationName(0), GameManager::getLocationName(4), 123, true);

	world->connect(GameManager::getLocationName(1), GameManager::getLocationName(2), 43, true);
	world->connect(GameManager::getLocationName(1), GameManager::getLocationName(5), 11, true);
}



void LocationsManager::load(){

	AddLocations();
	AddConnections();

}



