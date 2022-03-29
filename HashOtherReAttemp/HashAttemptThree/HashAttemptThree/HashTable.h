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

	std::string ht_search(int hash);

	void ht_delete(int hash);

	void print_search(int hash);

	void print_table();


};

/*
properties:--------------=
list of items
size of table
count of items
-------------------------=



*/