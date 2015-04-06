#include "linked_list.h"
#include "game.h"
#include <SFML\Graphics.hpp>

using namespace std;

int main()
{
	LINKED_LIST_STRING* list_s;
	list_s = LL_DEFINE(string);

	LL_ADD_DATA(list_s, string, "Hello World.");
	LL_ADD_DATA(list_s, string, "Eu sou uma lista ligada.");
	LL_ADD_DATA(list_s, string, "Sou miseravel e a minha cadela odeia-me.");
	LL_ADD_DATA(list_s, string, "Adeus, ate sempre.");
	LL_PRINT_DATA(list_s, string, 0);
	LL_PRINT_DATA(list_s, string, 1);
	LL_PRINT_DATA(list_s, string, 2);
	LL_PRINT_DATA(list_s, string, 3);

	GAME_RUN(RUNNING);
	
	getchar();

	GAME_STOP;
	return 0;
}