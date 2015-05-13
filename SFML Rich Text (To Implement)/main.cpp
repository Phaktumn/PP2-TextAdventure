#include <fstream>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "RichText.hpp"

int main()
{
    sf::Font arial;
    arial.loadFromFile("arial.ttf");

	std::string source;
    std::ifstream in("source.txt");

    while (in)
    {
    	std::string line;
    	std::getline(in, line);
    	source += line + '\n';
    }

	sfe::RichText rich(source, arial);

    sf::RenderWindow window;
    window.create(sf::VideoMode(700, 250), "SFML Rich text");

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rich);
        window.display();
    }
}
