// DoubleLinkedListReAttempt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "DoublyLinkedList.h"

int main()
{
	DoublyLinkedList* list = new DoublyLinkedList();

	list->AddNode(4);
	list->AddNode(53345);
	list->AddNode(111);
	list->PrintList();
	
	list->InsertAtBegin(25);
	//list->InsertAtPos(42, 0);
	//list->InsertAtPos(52, 0);
	//list->InsertAtPos(333, 20);
	list->PrintList();
	list->InsertAtPos(22, 1);
	list->PrintList();
	list->InsertAtPos(55, 4);
	list->PrintList();
	list->InsertAtBegin(101);
	list->PrintList();
	list->InsertAtPos(222, 1);

	list->PrintList();

	list->DelAtBegin();
	list->DelAtEnd();

	list->PrintList();

	list->DelAtPos(4);

	list->PrintList();

	list->SortList();
	list->PrintList("final print");

	std::cout << "end of program..................\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
