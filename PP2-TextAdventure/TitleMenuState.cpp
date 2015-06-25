#include "TitleMenuState.h"
#include "Globals.h"

//for (it_type iterator = drawnText.begin(); iterator != drawnText.end(); iterator++) {
//	window->draw(iterator->second);
//}

TitleMenuState::Option::Option(const std::string text, float x, float y, sf::Color color, unsigned charSize, sf::Font& font)
{
	properties.setFont(font);
	properties.setString(text);
	properties.setPosition(x, y);
	properties.setColor(color);
	properties.setCharacterSize(charSize);
}

TitleMenuState::Option::~Option()
{
}

TitleMenuState::TitleMenuState(sf::Font& font, StateManager& stateManager) : stateManager(stateManager)
{
	std::string strings[] = {
		"Play",
		"Load",
		"Options",
		"Credits"
	};

	menuOptions.resize(MENU_OPTIONS_COUNT);
	for (unsigned int i = 0; i < MENU_OPTIONS_COUNT; i++) {
		menuOptions[i] = std::make_shared<Option>(strings[i], x, y + i * menuPadding + gameTitlePadding, unselectedColor, menuFontSize, font);
	}

	gameTitle.setFont(font);
	gameTitle.setCharacterSize(gameTitleFontSize);
	gameTitle.setColor(sf::Color::White);
	gameTitle.setPosition(x, y);
	gameTitle.setString("Text Adventure");
}

TitleMenuState::~TitleMenuState()
{
}

void TitleMenuState::load()
{

}

void TitleMenuState::update()
{
	if (auxMusic)
	{
		if (!music.openFromFile("songs/inMenu.wav")){ std::cout << "ERROR" << std::endl; } // error
		auxMusic = false;
		music.play();
	}
	previousDown = down;
	previousUp = up;
	previousDown2 = down2;
	previousUp2 = up2;
	down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);
	down2 = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
	up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
	up2 = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);

	if ((down || down2) && !previousDown && !previousDown2 ) {
		selectedOption++;
	}

	if ((up || up2) && !previousUp && !previousUp2)
	{
		selectedOption--;
	}

	if (selectedOption < 0) selectedOption = MENU_OPTIONS_COUNT - 1;
	if (selectedOption >= MENU_OPTIONS_COUNT) selectedOption = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		switch (selectedOption)
		{
		case 0:  
			activeInput = true;
			music.stop();
			auxMusic = true;
            stateManager.changeState("GameState"); 
				break;
		case 3:
			activeInput = true;
			stateManager.changeState("Credits");
				break;
			default:
				break;
		}
	}
}

void TitleMenuState::draw(sf::RenderWindow* window)
{
	for (it_type iterator = menuOptions.begin(); iterator != menuOptions.end(); ++iterator) {
		if (selectedOption == (iterator - menuOptions.begin())) {
			iterator->get()->properties.setColor(selectedColor);
		}  else {
			iterator->get()->properties.setColor(unselectedColor);
		}

		window->draw(iterator->get()->properties);
	}

	window->draw(gameTitle);
}

