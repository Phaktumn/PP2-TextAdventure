#pragma once
#include "State.h"
#include "StateManager.h"
#include <memory>

class TitleMenuState : public State
{
public:
	explicit TitleMenuState(sf::Font* font, StateManager* stateManager);
	~TitleMenuState();

	void load() override;
	void update() override;
	void draw(sf::RenderWindow *window) override;

private:
	const unsigned int MENU_OPTIONS_COUNT = 4;
	
	StateManager* stateManager;

	class Option
	{
	public:
		sf::Text properties;
		Option(const std::string text, float x, float y, sf::Color color, unsigned int charSize, sf::Font *font);
		~Option();
	};

	std::vector<std::shared_ptr<Option>> menuOptions;
	typedef std::vector<std::shared_ptr<Option>>::iterator it_type;

	int selectedOption = 0;
	bool up = false;
	bool down = false;
	bool previousDown = false;
	bool previousUp = false;

	sf::Text gameTitle;

	// ==================== TWEAKING ====================
	sf::Color unselectedColor = sf::Color::Color(55, 55, 55, 255);
	sf::Color selectedColor = sf::Color::White;
	float x = 80;
	float y = 50;
	float menuPadding = 32;
	float gameTitlePadding = 120;
	unsigned int menuFontSize = 30;
	unsigned int gameTitleFontSize = 55;
};

