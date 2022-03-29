#include "LinkedList.h"

LinkedList* LinkedList::allocate_list()
{
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	return list;
}

LinkedList* LinkedList::linkedlist_insert(HashItem* item)
{
	if (!this) {
		LinkedList* head = allocate_list();
		head->item = item;
		head->next = NULL;
		return head;
	}
	else if (next == NULL) {
		LinkedList* node = allocate_list();
		node->item = item;
		node->next = NULL;
		next = node;
		return this;
	}

	LinkedList* temp = this;
	while (temp->next->next) {
		temp = temp->next;
	}

	LinkedList* node = allocate_list();
	node->item = item;
	node->next = NULL;
	temp->next = node;

	return this;
}

HashItem* LinkedList::linkedlist_remove() //removes head from linked list //returns popped item
{
	if (!this) {
		return NULL;
	}
	if (!next) {
		return NULL;
	}
	LinkedList* node = next;
	LinkedList* temp = this;
	temp->next = NULL;

	//might not work
	//this = node;
	next = node->next;
	item = node->item;

	HashItem* it = NULL;
	memcpy(temp->item, it, sizeof(HashItem));
	free(temp->item);
	free(temp);
	return it;
}

void LinkedList::free_linkedlist()
{

	LinkedList* temp = this;
	while (this) {
		temp = this;
		//might not work
		//list = list->next;
		item = next->item;
		next = next->next;

		free(temp->item);
		free(temp);
	}

}


