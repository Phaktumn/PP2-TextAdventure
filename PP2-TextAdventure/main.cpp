#include "game.h"
#include <SFML\Graphics.hpp>
#include "LinkedList.h"

int main()
{
	LinkedList<int> cabron;
	LinkedList<char*> elMatador;
	LinkedList<LinkedList<int>> listaDuplamenteLigada;

	cabron.add(1);
	cabron.add(3);
	elMatador.add("Hell");

	printf("%i\n", cabron.get(0));
	printf("%i\n", cabron.get(1));
	printf("%s\n", elMatador.get(0));

	Game game;
	game.run();

	getchar();

	return 0;
}