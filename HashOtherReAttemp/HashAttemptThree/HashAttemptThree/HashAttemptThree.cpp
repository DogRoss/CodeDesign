// HashAttemptThree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "HashTable.h"



int main()
{
    HashTable ht = HashTable(1000);
    std::cout << "//HashTable created" << std::endl;
    bool shouldClose = false;
    std::cout << "------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "What would you like to do: (i)nsert, (d)elete, (s)earch, (p)rint table, (q)uit application" << std::endl;
    while (!shouldClose) { //interactive UI, takes inputed result and executes statement dependant on input
        
        std::string result;
        std::cin >> result;

        if (result == "i") {
            std::string insertString;
            std::cout << "What text/value would you like to insert?" << std::endl;
            std::cin.ignore(1000, '\n'); //getline breaks w/o this
            std::getline(std::cin, insertString);
            ht.ht_insert(insertString);
        }
        else if (result == "d") {
            std::cout << "provide the hash of the text/value you want to delete." << std::endl;
            unsigned int deleteHash;
            std::cin >> deleteHash;
            ht.ht_delete(deleteHash);
        }
        else if (result == "s") {
            std::cout << "provide the hash of the text/value you want to find." << std::endl;
            unsigned int searchHash;
            std::cin >> searchHash;
            ht.print_search(searchHash);
        }
        else if (result == "p") {
            ht.print_table();
        }
        else if(result == "q") {
            shouldClose = true;
            break;
        }
        std::cout << "------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "What would you like to do: (i)nsert, (d)elete, (s)earch, (p)rint table, (q)uit application" << std::endl;
    }

}

