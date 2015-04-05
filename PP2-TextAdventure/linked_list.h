#include <string>
#define LL_DEFINE(type) initList_##type(nullptr);
#define LL_ADD_DATA(linkedlist, type, content) addData_##type(linkedlist, content);
#define LL_PRINT_DATA(linkedlist, type, index) printData_##type(linkedlist, index);

typedef struct LINKED_LIST_STRING
{
	LINKED_LIST_STRING* previous;
	LINKED_LIST_STRING* next;
	std::string* content;
} LINKED_LIST_STRING;

LINKED_LIST_STRING* initList_string(LINKED_LIST_STRING* previousLinkedList);
void addData_string(LINKED_LIST_STRING* linkedlist, const std::string &str);
void printData_string(LINKED_LIST_STRING* linkedlist, int index);