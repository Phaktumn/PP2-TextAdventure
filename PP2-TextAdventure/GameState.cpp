#include "GameState.h"

GameState::GameState(sf::Font& font, InputBox& inputBox, StateManager& stateManager) : font(font), inputBox(inputBox), stateManager(stateManager)
{
	
}

GameState::~GameState() {
	
}

void GameState::processCommands(const std::string& command)
{
	if (command == "> 1")
		world.moveTo(GameManager::getLocationName(1));
}

void GameState::load() {
	//inputBox.addListener(&GameState::processCommands);

	sfe::RichText titleFont(font);
	titleFont.setCharacterSize(BIG_CHARACTER_SIZE);

	sfe::RichText descriptionFont(font);
	descriptionFont.setCharacterSize(NORMAL_CHARACTER_SIZE);

	world.addLocation(GameManager::getLocationName(0), "Descrição Local 1");	
	world.addLocation(GameManager::getLocationName(1) , "Descrição Local 2", 
		titleFont << sf::Color::Cyan << GameManager::getLocationName(1),
		descriptionFont << "1 This jungle is made out of monkeys and seriously, like, everyone here is"
			<< sf::Color::Red << " BATSHIT " << sf::Color::White << "insane. \nMan, fuck me."	
	);		
	world.addLocation(GameManager::getLocationName(2), "Descrição Local 3");
	world.addLocation(GameManager::getLocationName(3), "Descrição Local 4");
	world.addLocation(GameManager::getLocationName(4), "Descrição Local 5");
	world.addLocation(GameManager::getLocationName(5), "dasldasd");

	world.debugPrintConnections(GameManager::getLocationName(0));
	
	world.connect(GameManager::getLocationName(0), GameManager::getLocationName(1), 10, false);
	world.connect(GameManager::getLocationName(0), GameManager::getLocationName(2), 43, false);
	world.connect(GameManager::getLocationName(0), GameManager::getLocationName(3), 14, false);
	world.connect(GameManager::getLocationName(0), GameManager::getLocationName(4), 123, true);
	world.connect(GameManager::getLocationName(1), GameManager::getLocationName(2), 43, true);
	world.connect(GameManager::getLocationName(1), GameManager::getLocationName(5), 11, true);

}

void GameState::update() {

	/*
		world.getConnections functions
			->gives all possible pathes from the position the player is

		world.getConnections()[0]
			->the first location connected
		world.getConnections()[1]
			->the second location connected
			...

		world.getConnections()[1]->getName()
			->gives the name of the first location connected

		world.moveTo(world.getConnections()[1]->getName());
			->moves the player to the first locations connected!
	*/
	if (inputBox.lastCommand() == "> 1")
		world.moveTo(world.getConnections()[0]->getName());
	if (inputBox.lastCommand() == "> 2")
		world.moveTo(world.getConnections()[1]->getName());
}

void GameState::draw(sf::RenderWindow* window)
{
	State::draw(window);
	world.draw(window);

	drawText(0, 0, SEPARATOR, font, 24, window);
	drawText(0, 300, SEPARATOR, font, 24, window);
	for (int i = 0; i < world.getConnections().size(); i++)
	{	
		drawText(15, 325 + i * 25, sfe::RichText(font) << std::to_string(i+1) << ") " << world.getConnections()[i]->getName(), 24, window);
	}


	drawText(0, WINDOW_HEIGHT - 50, SEPARATOR, font, 24, window);

	/*drawText(LOCATION_DESCRIPTION_POSITION_X, LOCATION_DESCRIPTION_POSITION_Y, sfe::RichText(font) 
		<< "This is white, this is " << sf::Color::Red << "red " << sf::Color::White << "and this is " 
		<< sf::Color::Green << "green" << sf::Color::White << ".", 24, window);*/
}