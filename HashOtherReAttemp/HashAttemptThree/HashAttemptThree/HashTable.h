#pragma once
#include<functional>
#include<string>
#include<iostream>

class HashTable
{
private:
	std::string* values;
	int size;
	int count;
	
public:

	HashTable(int size);

	unsigned int myHash(std::string value);

	unsigned int hashToKey(int hash);

	unsigned int ht_insert(std::string value);

	void ht_delete(int hash);

	void print_search(int hash);

	void print_table();


};

