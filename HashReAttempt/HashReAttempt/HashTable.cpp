#include "HashTable.h"



HashTable::HashTable(int size)
{
	size = size;
	count = 0;


}

unsigned int HashTable::myHash(std::string data)
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

unsigned int HashTable::deHash(int key)
{
	return key / 'a';
}

HashTable* HashTable::create_table(int size)
{
	HashTable* table = (HashTable*)malloc(sizeof(HashTable)); //allocates memory based of intended table size
	HashTable* table = new HashTable(); //allocates memory based of intended table size
	table->size = size;
	table->count = 0;
	table->items = (HashItem**)calloc(table->size, sizeof(HashItem*));
	for (int i = 0; i < table->size; i++) {
		table->items[i] = NULL;
	}
	table->overflow_buckets = create_overflow_buckets(table);

	return table;
}

unsigned int HashTable::ht_insert(std::string value)
{
	int hash = myHash(value);
	int index = deHash(hash);
	HashItem* item = HashItem::create_item(value);
	HashItem* current_item = item;
	if (current_item == NULL) {

		if (count == size) {
			std::cout << "Insert Error: Hash Table is full" << std::endl;
			return NULL;
		}

		//Insert directly
		std::cout << "inserting..." << std::endl;
		items[index] = item;
		count++;
	}
	else {
		std::cout << "key found in table" << std::endl;
		//items are same, just need to update values
		current_item->SetValue(value);
		return hash;
	}
}

HashItem* HashTable::ht_search(int hash)
{
	int index = deHash(hash);


	HashItem* item = items[index];

	//ensure that we move to a non NULL item
	if (item != NULL) {
		std::cout << "//item isnt null" << std::endl;
		if (deHash(myHash(item->GetValue())) == index) //no differences found
		{
			std::cout << "returning item value..." << std::endl;
			return item;
		}
	}
	std::cout << "//item is null + returning null..." << std::endl;
	return NULL;
}

void HashTable::ht_delete(int hash)
{
	LinkedList* nullLink = NULL;

	int index = deHash(hash);
	HashItem* item = items[index];
	LinkedList* head = &overflow_buckets[index];

	if (item == NULL) {
		return;
	}
	else {
		if (head == NULL && deHash(myHash(item->GetValue())) == index) {
			items[index] = NULL;
			count--;
			return;
		}
		else if (head != NULL) {
			if (deHash(myHash(item->GetValue())) == index) {
				LinkedList* node = head;
				head = head->next;
				node->next = NULL;
				items[index] = HashItem::create_item(node->item->GetValue());
				node->free_linkedlist();
				overflow_buckets[index] = *head;
				return;
			}

			LinkedList* curr = head;
			LinkedList* prev = NULL;

			while (curr) {
				if (deHash(myHash(curr->item->GetValue())) == index) {
					if (prev == NULL) { //first element in chain
						head->free_linkedlist();
						overflow_buckets[index] = *nullLink;
						return;
					}
					else {
						//somehwere in chain
						prev->next = curr->next;
						curr->next = NULL;
						curr->free_linkedlist();
						overflow_buckets[index] = *head;
						return;
					}
				}

				curr = curr->next;
				prev = curr;

			}

		}
	}

}

void HashTable::print_search(int hash)
{
	int index = deHash(hash);
	HashItem* item = ht_search(hash);
	if (item == NULL) {
		std::cout << "Key: " << index << " does not exist" << std::endl;
		return;
	}
	else {
		std::cout << "Key: " << index << " || Value: " << item->GetValue() << std::endl;
		return;
	}

}

void HashTable::print_table()//TODO: finish, test
{
	std::cout << "------------------Hash Table-----------------" << std::endl;
	for (int i = 0; i < size; i++) {
		if (items[i]) {
			std::cout << "Index: " << deHash(myHash(items[i]->GetValue())) << ", Value: " << items[i]->GetValue() << std::endl;
		}
	}
	std::cout << "----------------------------------------------" << std::endl;
}

LinkedList* HashTable::create_overflow_buckets(HashTable* table)
{

	LinkedList** buckets = (LinkedList**)calloc(table->GetSize(), sizeof(LinkedList*));
	for (int i = 0; i < table->GetSize(); i++) {
		buckets[i] = NULL;
	}
	return buckets;

}

void HashTable::free_overflow_buckets()
{

	LinkedList* buckets = overflow_buckets;
	for (int i = 0; i < size; i++) {
		buckets[i].free_linkedlist();
	}
	free(buckets);
}

