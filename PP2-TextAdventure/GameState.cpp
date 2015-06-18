#include "GameState.h"

GameState::GameState(sf::Font& font, InputBox& inputBox, StateManager& stateManager) : font(font), inputBox(inputBox), stateManager(stateManager)
{
	
}

GameState::~GameState() {

}

void GameState::load() {
	world.addLocation("Kingdom of Balls", "Descrição Local 1");
	
	sfe::RichText titleFont(font);
	titleFont.setCharacterSize(BIG_CHARACTER_SIZE);

	sfe::RichText descriptionFont(font);
	descriptionFont.setCharacterSize(NORMAL_CHARACTER_SIZE);

	world.addLocation("Monkey Jungle", "Descrição Local 2", 

		titleFont << sf::Color::Cyan << "Monkey Jungle",
		descriptionFont << "This jungle is made out of monkeys and seriously, like, everyone here is"
			<< sf::Color::Red << " BATSHIT " << sf::Color::White << "insane. \nMan, fuck me."
	
	);
	
	
	world.addLocation("Shit", "Descrição Local 3");
	world.addLocation("Banana", "Descrição Local 4");
	world.addLocation("Lol", "Descrição Local 5");
	world.addLocation("Mehehehe", "dasldasd");

	world.connect("Kingdom of Balls", "Monkey Jungle", 10);
	world.connect("Kingdom of Balls", "Shit", 20);
	world.connect("Kingdom of Balls", "Banana", 50);
	world.connect("Kingdom of Balls", "Lol", 102);

	world.debugPrintConnections("Kingdom of Balls");
	
	world.moveTo("Mehehehe");
	world.moveTo("Monkey Jungle");
}

void GameState::update() {
	if (inputBox.lastCommand() == "1")
		stateManager.changeState("BattleState");
}

void GameState::draw(sf::RenderWindow* window)
{
	State::draw(window);
	world.draw(window);

	drawText(0, 0, SEPARATOR, font, 24, window);
	drawText(0, 300, SEPARATOR, font, 24, window);
	drawText(0, WINDOW_HEIGHT - 50, SEPARATOR, font, 24, window);

	/*drawText(LOCATION_DESCRIPTION_POSITION_X, LOCATION_DESCRIPTION_POSITION_Y, sfe::RichText(font) 
		<< "This is white, this is " << sf::Color::Red << "red " << sf::Color::White << "and this is " 
		<< sf::Color::Green << "green" << sf::Color::White << ".", 24, window);*/
}