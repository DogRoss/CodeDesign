#pragma once

#ifndef	LINKEDLIST_H
#define LINKEDLIST_H


#include "HashTable.h"

class LinkedList
{
public:

	HashItem* item;
	LinkedList* next;



	LinkedList* allocate_list();

	LinkedList* linkedlist_insert(HashItem* item);

	HashItem* linkedlist_remove();	//removes head from linked list //returns popped item

	void free_linkedlist();
};

#endif
