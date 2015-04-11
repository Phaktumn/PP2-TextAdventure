#include "game.h"
#include <SFML\Graphics.hpp>
#include "LinkedList.h"

int main()
{
	LinkedList<int> cabron;

	cabron.add(1);
	cabron.add(3);

	printf("%i\n", cabron.get(0));
	printf("%i\n", cabron.get(1));

	Game game;
	game.run();

	getchar();

	return 0;
}