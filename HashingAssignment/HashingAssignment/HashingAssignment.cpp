#pragma once
#include <functional>
#include <string>
#include <string.h>

//TODO: ask rob how this works and why id use it
#define CAPACITY 50000 //size of hash table

typedef std::function< unsigned int(const char*, unsigned int)> HashFunction;

unsigned int myHash(const char* data)
{

	unsigned int result = 0;
	for (int i = 0; data[i]; i++) {
		result += data[i];
	}
	return result % CAPACITY;
}


typedef struct Ht_item Ht_item;

//item struct for storing the value of item and its key (for table searching)
struct Ht_item {
	char* key;
	char* value;
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

typedef struct LinkedList LinkedList;

// Definition
struct LinkedList {//TODO: proper comments
	Ht_item* item;
	LinkedList* next;
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
	free(temp->item->key);
	free(temp->item->value);
	free(temp->item);
	free(temp);
	return it;
}

void free_linkedlist(LinkedList* list) { //TODO: proper comments
	LinkedList* temp = list;
	while (list) {
		temp = list;
		list= list->next;
		free(temp->item->key);
			free(temp->item->value);
		free(temp->item);
		free(temp);
	}

}


Ht_item* create_item(const char* key, const char* value) {
	// Creates pointer to a new hash table item
	Ht_item* item = (Ht_item*)malloc(sizeof(Ht_item));  //allocates memory based off the size of the Ht_item struct (I think)
	item->key = (char*)malloc(strlen(key) + 1); //allocates memory based of the length of the KEY data
	item->value = (char*)malloc(strlen(value) + 1); //allocates memory based of the length of the VALUE data


	size_t size = strlen(key) + 1; //counts size of characters within key
	strcpy_s(item->key, size, key); //copies values to item->key pointer value
	size = strlen(value) + 1;
	strcpy_s(item->value, size, value); //copies values to item->value pointer value

	return item;
}

void free_item(Ht_item* item) {
	// Frees an item
	free(item->key);
	free(item->value);
	free(item);
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

void free_table(HashTable* table) {
	// frees the table
	for (int i = 0; i < table->size; i++) {			//for each item space in table, set a pointer to the item space,
		Ht_item* item = table->items[i];			//check if the item is NULL, if it isnt, free it
		if (item != NULL) {
			free_item(item);
		}
	}

	free_overflow_buckets(table); //free overflow bucket linked list and its items
	free(table->items);
	free(table);
}

void handle_collision(HashTable* table, Ht_item* item) {//TODO: (IMPORTANT) handle collision
}
void ht_insert(HashTable* table, const char* key, const char* value) {
	Ht_item* item = create_item(key, value); //sets pointer to created item
	int index = myHash(key); //compute index
	Ht_item* current_item = table->items[index]; //sets a pointer to the current item space in the table
	if (current_item == NULL) {	//if the item in the table is not taken
		if (table->count == table->size) { //if the amount of items currently within the table match the size of the table
			//throw error
			printf("Insert Error: Hash Table is full\n");
			free_item(item); //frees item pointer, as it cannot be inserted
			return;
			
		}

		//Insert directly
		table->items[index] = item;
		table->count++;
	}
	else { //If the key of created item is found in table already
		//the items are the same, just needs to update the value
		if (strcmp(current_item->key, key) == 0) { //if keys are same
			size_t size = strlen(value) + 1;
			strcpy_s(current_item->value, size, value); //copies created item key/value to item in table
			return;
		}
		else { //collision happened
			handle_collision(table, item);
			return;
		}

	}

}

char* ht_search(HashTable* table, const char* key) { //searched key in hashtable //returns null if nonexistent
	int index = myHash(key); // sets index to hashed 
	Ht_item* item = table->items[index];

	// Ensure that we move to a non NULL item
	if (item != NULL) {
		if (strcmp(item->key, key) == 0) { //if no differences are found in key
			return item->value; //then return the value associated with it
		}
	}
	return NULL;
}

void print_search(HashTable* table, const char* key) { //TODO: proper comments
	char* val;
	if ((val = ht_search(table, key)) == NULL) {
		printf("Key:%s does not exist\n", key);
		return;
	}
	else {
		printf("Key:%s, Value:%s\n", key, val);
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
	ht_insert(ht, "1", "First address");
	ht_insert(ht, "2", "Second address");
	print_search(ht, "1");
	print_search(ht, "2");
	print_search(ht, "3");
	free_table(ht);
	return 0;
}



