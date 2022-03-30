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

		Node(int nodeValue) { value = nodeValue; prev = NULL; next = NULL; };
	};

	//Variables
	int i = 0;
	Node* head;
	Node* tail;

	//Constructor
	DoubleLinkedList() {
		i = 0;
		head = NULL;
		tail = NULL;
	};

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
		
		std::cout << tail->value  << " addnode complete" << std::endl;
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

		Node* leftofPos = NULL;
		Node* rightOfPos = head;

		for (int i = pos; i > 0; i--) {
			
			if (rightOfPos->next == NULL) {
				leftofPos = rightOfPos;
				rightOfPos = NULL;
				break;
			}

			rightOfPos = rightOfPos->next;
		
			leftofPos = rightOfPos->prev;
			
		}

		node->prev = leftofPos;
		node->next = rightOfPos;

		if (leftofPos != NULL) {
			leftofPos->next = node;
		}
		if (rightOfPos != NULL) {
			rightOfPos->prev = node;
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

	void SortList() {
		Node* currentNode = head;
		int listAmount = GetListCount();
		int inOrderCount = 0;
		bool sorted = false;
		while (!sorted) {
			inOrderCount++;
			if (currentNode == head) {	//if head
				if (currentNode->value > currentNode->next->value) { //if left greater than right
					Node* nextCopy = currentNode->next; //copy of next
					head = nextCopy; //makes head next
					head->prev = NULL; //sets head prev to null
					head->next->prev = currentNode;//sets node originally after head to be current to squeeze it in
					head->next = currentNode;//sets head current next to node
					inOrderCount = 0;
				}
			}
			else if (currentNode == tail) {
				sorted = true;
				break;
			}
			else if (currentNode->value > currentNode->next->value) {
				Node* nextCopy = currentNode->next;//create copy of next
				nextCopy->prev = currentNode->prev;
				nextCopy->next = currentNode;
				
				currentNode->prev->next = currentNode->next; //sets the previous of current node to the current-next node
				currentNode->prev = currentNode->next;//set current selected nodes previous to next
				currentNode->next = currentNode->next->next;

				currentNode = nextCopy;
			}

			if (inOrderCount >= listAmount) {
				sorted = true;
				break;
			}
		}

		if (inOrderCount < listAmount) {
			SortList();
		}
	}

	void PrintList() {
		Node* currentNode = head;
		int amount = 0;
		while(currentNode != NULL) {
			std::cout << "Node(" << amount << ") value: " << currentNode->value << std::endl;
			currentNode = currentNode->next;
			amount++;
		}
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
	list->InsertAtPos(55, 4);
	list->InsertAtBegin(101);
	list->InsertAtEnd(202);

	list->PrintList();

	list->DelAtBegin();
	list->DelAtEnd();

	list->PrintList();

	list->DelAtPos(4);

	list->PrintList();

	list->SortList();
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
