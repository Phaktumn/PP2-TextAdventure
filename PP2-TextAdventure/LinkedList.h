#pragma once

template <class type> 
class LinkedList
{
private:
	typedef struct Node
	{
		type value;
		Node* next;
	};

	Node* head;
	int count;

public:
	LinkedList();
	~LinkedList();
	
	void add(type value);
	type get(int index);
	void removeAt(int index);
	void remove(type object);
	int getLength();
	bool checkIfEmpty();
};

template <class type>
LinkedList<type>::LinkedList() : head(nullptr), count(0)
{

}

template <class type>
LinkedList<type>::~LinkedList()
{
}

template <class type>
int LinkedList<type>::getLength(){
	return count;
}

template <class type>
bool LinkedList<type>::checkIfEmpty()
{
	Node* ptr = head;
	if (ptr != nullptr) return false;
	else return true;
}

template <class type>
void LinkedList<type>::add(type value)
{
	if (head == nullptr) {
		head = (Node*)malloc(sizeof(Node));
		head->value = value;
		head->next = nullptr;
	}
	else 
	{
		Node* previousPtr = head;
		Node* ptr = head;

		while (ptr != nullptr) {
			previousPtr = ptr;
			ptr = ptr->next;
		}

		ptr = (Node*)malloc(sizeof(Node));
		previousPtr->next = ptr;
		ptr->value = value;
		ptr->next = nullptr;
		count++;
	}
}

template <class type>
type LinkedList<type>::get(int index)
{
	int i = 0;
	Node* ptr = head;

	if (ptr != nullptr){
		while (i < index) {
			ptr = ptr->next;
			i++;
		}
		return ptr->value;
	}
	return nullptr;
}

template <class type>
void LinkedList<type>::removeAt(int index)
{
	int i = 0;
	Node* ptr = head;

	while (i < index - 1)
	{
		ptr = ptr->next;
		i++;
	}
	ptr->next = ptr->next->next;
	Node* removed = ptr->next;
	count--;
	delete(removed)
}

template <class type>
void LinkedList<type>::remove(type object)
{
	Node* ptr = head;
	while (ptr->next != nullptr)
	{
		if (object == ptr->next->value)
		{
			Node* toRemove = ptr->next;
			ptr->next = ptr->next->next;
			delete(toRemove);
			count--;
			delete(toRemove);
		}
	}
}