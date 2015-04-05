#include "linked_list.h"
#include "utils.h"
#include <stdlib.h>

LINKED_LIST_STRING* initList_string(LINKED_LIST_STRING* previousLinkedList)
{
	LINKED_LIST_STRING* linked_list_string;
	linked_list_string = (LINKED_LIST_STRING*)malloc(sizeof(LINKED_LIST_STRING));
	linked_list_string->next = nullptr;
	linked_list_string->previous = previousLinkedList;
	linked_list_string->content = nullptr;

	return linked_list_string;
}

void addData_string(LINKED_LIST_STRING* linkedlist, const std::string &str)
{
	if (linkedlist->content != nullptr) {
		if (linkedlist->next == nullptr) {
			linkedlist->next = initList_string(linkedlist);
			addData_string(linkedlist->next, str);
			return;
		}

		addData_string(linkedlist->next, str);
		return;
	}

	std::string* ptr = new std::string(str);
	linkedlist->content = ptr;
}

void printData_string(LINKED_LIST_STRING* linkedlist, int index)
{
	if (index < 0) {
		error("Index cannot be lower than zero.");
		return;
	}

	LINKED_LIST_STRING* ptr = linkedlist;
	int count = 0;

	while (index != count) {
		ptr = ptr->next;
		count++;
	}

	printf("[%i]: %s\n", index, ptr->content->c_str());
}