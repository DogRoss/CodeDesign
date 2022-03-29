#pragma once
#include <functional>
#include <string>
#include <string.h>
#include <iostream>

#include "HashTable.h"

//TODO: ask rob how this works and why id use it
#define CAPACITY 50000 //size of hash table

typedef std::function< unsigned int(const char*, unsigned int)> HashFunction;

unsigned int myHash(std::string data)
{

	unsigned int result = 0;
	for (int i = 0; data[i]; i++) {
		result += data[i];
	}
	int temp = result * 'a';
	std::cout << temp << std::endl;
	std::cout << temp / 'a' << std::endl;
	std::cout << result << std::endl;
	return result * 'a';
}

unsigned int deHash(int key) {
	return key / 'a';
}


//typedef struct Ht_item Ht_item;

//item struct for storing the value of item and its key (for table searching)
class Ht_item {
public:

	Ht_item(int inputKey, std::string inputValue) {
		key = inputKey;
		value = inputValue;
	}


	int key;
	std::string value;

	void SetKey(int inputKey) {
		key = inputKey;
	}

	void SetValue(std::string inputValue) {
		value = inputValue;
	}
};

typedef struct LinkedList LinkedList;

// Definition
class LinkedList {//TODO: proper comments

public:
	Ht_item* item;
	LinkedList* next;


};

typedef struct HashTable HashTable;

//	Definitions
struct HashTable {
	//Contains array of pointers to items
	Ht_item** items;
	LinkedList** overflow_buckets; //TODO: desc
	int size;
	int count;
};



LinkedList* allocate_list() { //TODO: proper comments
	// Allocates memory for a Linkedlist pointer
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	return list;
}

LinkedList* linkedlist_insert(LinkedList* list, Ht_item* item) {//TODO: proper comments
	//Inserts item onto Linked List
	if (!list) {				//TODO: desc
		LinkedList* head = allocate_list();
		head->item = item;
		head->next = NULL;
		list = head;
		return list;
	}
	else if (list->next == NULL) {		//TODO: desc
		LinkedList* node = allocate_list();
		node->item = item;
		node->next = NULL;
		list->next = node;
		return list;
	}

	LinkedList* temp = list;
	while (temp->next->next) {	//TODO: desc
		temp = temp->next;
	}

	LinkedList* node = allocate_list();
	node->item = item;
	node->next = NULL;
	temp->next = node;

	return list;
}

Ht_item* linkedlist_remove(LinkedList* list) {	//TODO: proper comments
	// Removes the head from the linked list
	// and returns the item of the popped element
	if (!list) {
		return NULL;
	}
	if (!list->next) {
		return NULL;
	}
	LinkedList* node = list->next;
	LinkedList* temp = list;
	temp->next = NULL;
	list = node;
	Ht_item* it = NULL;
	memcpy(temp->item, it, sizeof(Ht_item));
	free(temp->item);
	free(temp);
	return it;
}

void free_linkedlist(LinkedList* list) { //TODO: proper comments
	LinkedList* temp = list;
	while (list) {
		temp = list;
		list= list->next;
		free(temp->item);
		free(temp);
	}

}


Ht_item* create_item(int key, std::string value) {
	// Creates pointer to a new hash table item
	//Ht_item* item = (Ht_item*)malloc(sizeof(Ht_item));  //allocates memory based off the size of the Ht_item struct (I think)
	Ht_item* item = new Ht_item(key, value);  //allocates memory based off the size of the Ht_item struct (I think)
	item->SetKey(key); //allocates memory based of the length of the KEY data
	//item->value = (std::string)malloc(sizeof(value)); //allocates memory based of the length of the VALUE data
	item->SetValue(value); //allocates memory based of the length of the VALUE data


	//size_t size = key+ 1; //counts size of characters within key
	//item->key = key; //copies values to item->key pointer value
	//item->value = value; //copies values to item->value pointer value

	return item;
}

LinkedList** create_overflow_buckets(HashTable* table) { //TODO: proper comments
	//Create the overflow buckets; an array of linkedlists
	LinkedList** buckets = (LinkedList**)calloc(table->size, sizeof(LinkedList*));
	for (int i = 0; i < table->size; i++) {
		buckets[i] = NULL;
	}
	return buckets;
}

void free_overflow_buckets(HashTable* table) { //TODO: proper comments
	// Free all the overflow bucket lists
	LinkedList** buckets = table->overflow_buckets;
	for (int i = 0; i < table->size; i++) {
		free_linkedlist(buckets[i]);
	}
	free(buckets);
}

HashTable* create_table(int size) {
	// Creates a new HashTable
	HashTable* table = (HashTable*)malloc(sizeof(HashTable));	// allocates memory based on size of table the user wants
	table->size = size;	// sets value thats pointed to
	table->count = 0;
	table->items = (Ht_item**)calloc(table->size, sizeof(Ht_item*)); // allocates memory 
	for (int i = 0; i < table->size; i++) {
		table->items[i] = NULL; // 
	}
	table->overflow_buckets = create_overflow_buckets(table);

	return table;
}



void ht_insert(HashTable* table, std::string value) {
	int hash = myHash(value); //compute index
	int index = deHash(hash);
	Ht_item* item = create_item(index, value); //sets pointer to created item
	Ht_item* current_item = item; //sets a pointer to the current item space in the table
	if (current_item == NULL) {	//if the item in the table is not taken
		if (table->count == table->size) { //if the amount of items currently within the table match the size of the table
			//throw error
			printf("Insert Error: Hash Table is full\n");
			return;
			
		}

		//Insert directly
		std::cout << "inserting..." << std::endl;
		table->items[index] = item;
		table->count++;
	}
	else { //If the key of created item is found in table already
		std::cout << "key found in table..." << std::endl;
		//the items are the same, just needs to update the value
		current_item->SetValue(value);//copies created item key/value to item in table
		return;
	}

}

Ht_item* ht_search(HashTable* table, int index) { //searched key in hashtable //returns null if nonexistent
	Ht_item* item = table->items[index];

	// Ensure that we move to a non NULL item
	if (item != NULL) {
		std::cout << "//item isnt null" << std::endl;
		if (item->key == index) { //if no differences are found in key
			std::cout << "returning item value..." << std::endl;
			return item; //then return the value associated with it
		}
	}
	std::cout << "//item is null + returning null..." << std::endl;
	return NULL;
}

void ht_delete(HashTable* table, int hash) {
	//Deletes an item from table
	int index = deHash(hash);
	Ht_item* item = table->items[index];
	LinkedList* head = table->overflow_buckets[index];

	if (item == NULL) {
		//Does not exist. Return
		return;
	}
	else {
		if (head == NULL && item->key == index) {
			//No collision chain, remove the item and set table index to NULL
			table->items[index] = NULL;
			table->count--;
			return;
		}
		else if (head != NULL) {
			//Collision chain exists
			if (item->key == index) {
				//Remove this item and set the head of list as new item
				LinkedList* node = head;
				head = head->next;
				node->next = NULL;
				table->items[index] = create_item(node->item->key, node->item->value);
				free_linkedlist(node);
				table->overflow_buckets[index] = head;
				return;
			}

			LinkedList* curr = head;
			LinkedList* prev = NULL;

			while (curr) {
				if (curr->item->key == index) {
					if (prev == NULL) {
						//first element in chain
						free_linkedlist(head);
						table->overflow_buckets[index] = NULL;
						return; 
					}
					else {
						//this is somewhere in chain
						prev->next = curr->next;
						curr->next = NULL;
						free_linkedlist(curr);
						table->overflow_buckets[index] = head;
						return;
					}
				}

				curr = curr->next;
				prev = curr;

			}

		}
	}

}

void print_search(HashTable* table, int index) { //TODO: proper comments
	Ht_item* item = ht_search(table, index);
	if (item == NULL) {
		std::cout << "Key:" << index << " does not exist" << std::endl;
		return;
	}
	else {
		std::cout << "Key:" << index << "Value:" << item->value << std::endl;
		return;
	}
}

void print_table(HashTable* table) { //TODO: proper comments
	printf("\nHash Table\n-------------------\n");
	for (int i = 0; i < table->size; i++) {
		if (table->items[i]) {
			printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
		}
	}
	printf("---------------------\n\n");
}


int main() { //TODO: proper comments
	HashTable* ht = create_table(CAPACITY);

	std::string item = "First address";
	unsigned int firstHash = myHash(item);
	ht_insert(ht, item);
	//ht_insert(ht, "2", "Second address");
	//ht_insert(ht, "Hel", "Third address");
	//ht_insert(ht, "Cau", "Fourthh address");
	print_search(ht, deHash(firstHash));
	//print_search(ht, "2");
	//print_search(ht, "3");
	//print_search(ht, "Hel");
	//print_search(ht, "Cau"); //Collision happens
	//print_table(ht);
	//ht_delete(ht, "1");
	//ht_delete(ht, "Cau");
	//print_table(ht);
	//free_table(ht);

	std::cout << "type 'esc' to exit" << std::endl;
	std::string result;
	std::cin >> result;
	if (result == "esc") {
		return 0;
	}
	else {
		return 0;
	}
	
}





/*

	

*/








