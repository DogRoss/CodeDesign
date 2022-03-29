// HashAttemptThree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "HashTable.h"

std::string insertInput() {
    std::cout << "What text/value would you like to insert?" << std::endl;
    std::string result;
    std::getline(std::cin, result);
    return result;
}

unsigned int deleteInput() {
    std::cout << "provide the hash of the text/value you want to delete." << std::endl;
    unsigned int result;
    std::cin >> result;
    return result;

}

unsigned int searchInput() {
    std::cout << "provide the hash of the text/value you want to find." << std::endl;
    unsigned int result;
    std::cin >> result;
    return result;

}

int main()
{
    HashTable ht = HashTable(1000);
    std::cout << "//HashTable created" << std::endl;
    bool shouldClose = false;
    while (!shouldClose) {
        std::cout << "----------------------------------------------------------------------" << std::endl;
        std::cout << "What would you like to do: (i)nsert, (d)elete, (s)earch, (p)rint table" << std::endl;
        char result;
        std::cin >> result;
        switch (result) {
        case 'i':
            ht.ht_insert(insertInput());
            break;
        case'd':
            ht.ht_delete(deleteInput());
            break;
        case's':
            ht.print_search(searchInput());
            break;
        case'p':
            ht.print_table();
            break;
        }
    }



    unsigned int hash = ht.ht_insert("Indominable");
    ht.print_search(hash);

    unsigned int hash2 = ht.ht_insert("decision");
    ht.print_search(hash2);

    unsigned int hash3 = ht.ht_insert("Indominable");
    ht.print_search(hash3);

    unsigned int hash4 = ht.ht_insert("bruh");
    ht.print_search(hash4);

    unsigned int hash5 = ht.ht_insert("male");
    ht.print_search(hash5);

    ht.print_table();

}

