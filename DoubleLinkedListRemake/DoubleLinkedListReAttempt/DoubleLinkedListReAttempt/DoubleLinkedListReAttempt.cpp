// DoubleLinkedListReAttempt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class DoubleLinkedList
{


public:


	//Nested Class
	class Node {
	public:

		int value;
		Node* prev;
		Node* next;

		Node(int nodeValue) : value(nodeValue), prev(nullptr), next(nullptr) {};
	};

	//Variables
	int i;
	Node* head;
	Node* tail;

	//Constructor
	DoubleLinkedList() : i(0), head(nullptr), tail(nullptr) {};

	//Functions

	void AddNode(int value) {
		Node* node = new Node(value);

		if (tail == NULL) {
			head = node;
			tail = node;
		}
		else {
			node->prev = tail;
			tail->next = node;
			tail = node;
		}

		std::cout << tail->value << " addnode complete" << std::endl;
		i++;
	};

	void InsertAtBegin(int value) {
		Node* node = new Node(value);
		head->prev = node;
		node->next = head;
		head = node;
		std::cout << head->value << " insert at begin complete" << std::endl;
		i++;

	};

	void InsertAtEnd(int value) {
		Node* node = new Node(value);
		tail->next = node;
		node->prev = tail;
		tail = node;
		std::cout << tail->value << " insert at end complete" << std::endl;
		i++;
	};

	void InsertAtPos(int value, int pos) {
		Node* node = new Node(value);

		if (pos == 0) {
			InsertAtBegin(value);
			return;
		}

		Node* nextPos = head;

		for (int i = pos; i > 0; i--) {

			if (nextPos->next == NULL) {
				break;
			}

			nextPos = nextPos->next;


		}

		node->prev = nextPos->prev;
		node->next = nextPos;

		if (nextPos->prev != NULL) {
			nextPos->prev->next = node;
		}
		else {
			head = node;
		}
		if (nextPos != NULL) {
			nextPos->prev = node;
		}

		std::cout << " insert at specific pos done" << std::endl;
		i++;
	};

	void DelAtBegin() {
		head = head->next;
		head->prev = NULL;
		std::cout << " delete at begin complete" << std::endl;
		i--;
	};

	void DelAtEnd() {
		tail = tail->prev;
		tail->next = NULL;
		std::cout << " delete at end complete" << std::endl;
		i--;
	};

	void DelAtPos(int pos) {
		if (pos == 0) {
			DelAtBegin();
			return;
		}

		Node* currentNode = head;

		for (int i = pos - 1; i > 0; i--) {

			if (currentNode->next == NULL) {
				DelAtEnd();
				currentNode = NULL;
				return;
			}

			currentNode = currentNode->next;

		}

		currentNode->next->prev = currentNode->prev;
		currentNode->prev->next = currentNode->next;

		std::cout << " delete at specific pos done" << std::endl;
		i--;
	};

	int GetListCount() {
		Node* currentNode = head;
		int amount = 0;
		while (currentNode != NULL) {
			currentNode = currentNode->next;
			amount++;
		}

		return amount;
	}

	void SortList(Node* current)
	{
		if (current->next)
		{
			if (current->value > current->next->value)
			{
				std::swap(current->value, current->next->value);
				SortList(head);
			}
			else
			{
				SortList(current->next);
			}
		}
	}

	void PrintList() {
		Node* currentNode = head;
		int amount = 0;
		while (currentNode != NULL) {
			std::cout << "Node(" << amount << ") value: " << currentNode->value << std::endl;
			currentNode = currentNode->next;
			amount++;
		}

		std::cout << "head: " << head->value << " || tail: " << tail->value << std::endl;
	}
};

int main()
{
	DoubleLinkedList* list = new DoubleLinkedList();

	list->AddNode(4);
	list->AddNode(53345);
	list->AddNode(111);

	list->InsertAtBegin(25);
	list->InsertAtPos(42, 0);
	list->InsertAtPos(52, 0);
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

	list->SortList(list->head);
	list->PrintList();

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
