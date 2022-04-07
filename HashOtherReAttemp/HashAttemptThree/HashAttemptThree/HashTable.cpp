

#include "HashTable.h"

HashTable::HashTable(int tableSize)
{
	values = new std::string[tableSize];
	size = tableSize;
	count = 0;
}

unsigned int HashTable::myHash(std::string value) //hashes value inputed by getting values from individual characters, adding them, and multiplying by 'a'
{
	unsigned int result = 0;
	for (int i = 0; value[i]; i++) {
		result += value[i];
	}
	return result * 'a';
}

unsigned int HashTable::hashToKey(int hash) //mod by table size to find location in table
{
	return hash % size;
}

unsigned int HashTable::ht_insert(std::string value) //inserts value into hash table
{
	int hash = myHash(value); //creates hash key, then creates the location in the table with the hash key
	int index = hashToKey(hash);

	std::cout << "hash:" << hash << "||index:" << index << std::endl;

	if (!values[index].empty()) { //key exists, update value at key
		std::cout << "//key found in table, updating..." << std::endl;
		values[index] = value;
		return hash;
	}
	else { //inserts
		std::cout << "Inserting..." << std::endl;
		values[index] = value;
		return hash;
	}
}

void HashTable::ht_delete(int hash) //deletes specified item through hash key
{
	int index = hashToKey(hash);

	if (values[index].empty()) {
		std::cout << "//Item at index is null + Returning..." << std::endl;
		return;
	}
	else {
		std::cout << "Deleting Item..." << std::endl;
		values[index] = "";
	}

}

void HashTable::print_search(int hash) //prints info of specified hash item
{
	int index = hashToKey(hash);
	if (values[index].empty()) {
		std::cout << "Key: " << index << " does not exist" << std::endl;
	}
	else {
		std::cout << "Value: " << values[index] << ", Index: " << index << ", Hash: " << myHash(values[index]) << std::endl;
	}
}

void HashTable::print_table() //prints hash table with associated and necessitated values
{
	std::cout << "------------------Hash Table-----------------" << std::endl;
	for (int i = 0; i < size; i++) {
		if (!values[i].empty()) {
			std::cout << "Value: " << values[i] << ", Index: " << i << ", Hash: " << myHash(values[i]) << std::endl;
		}
	}
	std::cout << "----------------------------------------------" << std::endl;
}
