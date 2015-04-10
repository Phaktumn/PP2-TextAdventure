#include "linked_list.h"
#include "game.h"
<<<<<<< HEAD
#include "DialogueTree.h"
=======
#include <SFML\Graphics.hpp>
>>>>>>> origin/master

/*
	Ideia:
		Tudo começa na classe Game, que representa o jogo em si; 
		Game contêm um gestor de "Screens", para podermos saltar de menus para in-game e afins;
		A classe Screen base pode ser derivada, pelo podemos criar GameScreen, MenuScreen, etc;

<<<<<<< HEAD
*/

=======
>>>>>>> origin/master
int main()
{
	Game game;
	game.run(RUNNING);


	// Temos duas opções, OOP approach:
	DialogueTree dialogueTree;
	dialogueTree.addNode("Floresta Encantada do caralho mais velho.");
	dialogueTree.addNode("Cóvinha da bicha demoniaca.");
	dialogueTree.addNode("Bomba do gasoile barato.");
	dialogueTree.addOption("Anda pá frente que ainda levas nas trombas.", dialogueTree.getNode(0), dialogueTree.getNode(1));
	dialogueTree.addOption("Enxer o deposito com low cost ca vida não é barata.", dialogueTree.getNode(0), dialogueTree.getNode(2));

	// C-like, forma imperativa:
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
	
	getchar();

	return 0;
}