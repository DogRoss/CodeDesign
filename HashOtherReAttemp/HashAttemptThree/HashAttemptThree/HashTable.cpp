

#include "HashTable.h"

HashTable::HashTable(int tableSize)
{
	values = new std::string[tableSize];
	size = tableSize;
	count = 0;
}

unsigned int HashTable::myHash(std::string value)
{
	unsigned int result = 0;
	for (int i = 0; value[i]; i++) {
		result += value[i];
	}
	return result * 'a';
}

unsigned int HashTable::hashToKey(int hash)
{
	return hash % size;
}

unsigned int HashTable::ht_insert(std::string value)
{
	int hash = myHash(value);
	int index = hashToKey(hash);

	std::cout << "hash:" << hash << "||index:" << index << std::endl;

	if (!values[index].empty()) {
		std::cout << "//key found in table, updating..." << std::endl;
		values[index] = value;
		return hash;
	}
	else {
		if (count == size) {
			std::cout << "Insert Error: Hash Table is full" << std::endl;
			return NULL;
		}

		std::cout << "Inserting..." << std::endl;
		values[index] = value;
		return hash;
	}
}

std::string HashTable::ht_search(int hash)
{
	int index = hashToKey(hash);


	if (!values[index].empty()) {
		std::cout << "//Item isnt null" << std::endl;
		return values[index];
	}
	std::cout << "Item is null + Returning null..." << std::endl;
	return NULL;

}

void HashTable::ht_delete(int hash)
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

void HashTable::print_search(int hash)
{
	int index = hashToKey(hash);
	if (values[index].empty()) {
		std::cout << "Key: " << index << " does not exist" << std::endl;
	}
	else {
		std::cout << "Key: " << index << " || Value: " << values[index] << std::endl;
	}
}

void HashTable::print_table()
{
	std::cout << "------------------Hash Table-----------------" << std::endl;
	for (int i = 0; i < size; i++) {
		if (!values[i].empty()) {
			std::cout << "Index: " << i << ", Value: " << values[i] << std::endl;
		}
	}
	std::cout << "----------------------------------------------" << std::endl;
}
