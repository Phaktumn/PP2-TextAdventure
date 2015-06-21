#include "GameState.h"

GameState::GameState(sf::Font& font, InputBox& inputBox, StateManager& stateManager) : font(font), inputBox(inputBox), stateManager(stateManager)
{
	menu = new GameStateMenu(font, inputBox);
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
	LocationsManager locationsManager(&world, font);
	locationsManager.load();
}

void GameState::update() {
	menu->update(inputBox, &world);
	/*  world.getConnections functions
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

	/*if (inputBox.lastCommand() == "> 1")
		world.moveTo(world.getConnections()[0]->getName());
	if (inputBox.lastCommand() == "> 2")
		world.moveTo(world.getConnections()[1]->getName());*/
	
	std::string lastCommand = inputBox.lastCommand();
	std::vector<std::string> connections = world.getCurrentConnections();
	for (size_t i = 0; i < connections.size(); i++) {
		if (lastCommand == connections[i]) {
			world.moveTo(connections[i]);
			break;
		}
	}
}

void GameState::draw(sf::RenderWindow* window)
{
	State::draw(window);
	world.draw(window);

	drawText(0, 0, SEPARATOR, font, 24, window);
	drawText(0, 300, SEPARATOR, font, 24, window);

	menu->draw(window, &world);
	//for (int i = 0; i < world.getConnections().size(); i++){	
	//	drawText(15, 325 + i * 25, sfe::RichText(font) << std::to_string(i+1) << ") " << world.getConnections()[i]->getName(), 24, window);
	//}

	drawText(0, WINDOW_HEIGHT - 50, SEPARATOR, font, 24, window);

	/*drawText(LOCATION_DESCRIPTION_POSITION_X, LOCATION_DESCRIPTION_POSITION_Y, sfe::RichText(font) 
		<< "This is white, this is " << sf::Color::Red << "red " << sf::Color::White << "and this is " 
		<< sf::Color::Green << "green" << sf::Color::White << ".", 24, window);*/
}