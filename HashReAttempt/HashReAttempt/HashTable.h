#pragma once

#ifndef HASHTABLE_H
#define HASHTABLE_H



#include <functional>
#include <string>
#include <iostream>
#include <vector>

#include "HashItem.h"
#include "LinkedList.h"

class HashTable
{
private:

	std::vector<HashItem*> items;
	LinkedList* overflow_buckets;
	int size;
	int count;


public:
	HashTable(int size);

	HashItem* GetItems() { return items; };
	LinkedList* GetOverflowBuckets() { return overflow_buckets; };

	int GetSize() { return size; };
	int GetCount() { return count; };

	//Hashing and Hash Items
	unsigned int myHash(std::string data);

	unsigned int deHash(int key);

	
	//Table creation and memory management
	static HashTable* create_table(int size);


	//table interaction functions
	unsigned int ht_insert(std::string value); //inserts and

	HashItem* ht_search(int hash); //returns pointer to item in table at hash point

	void ht_delete(int hash); //use hash to find item then delete item

	void print_search(int hash); //provide hash value to find item

	void print_table(); //prints table items and index

	static LinkedList* create_overflow_buckets(HashTable* table);

	void free_overflow_buckets();
};

#endif // !1
