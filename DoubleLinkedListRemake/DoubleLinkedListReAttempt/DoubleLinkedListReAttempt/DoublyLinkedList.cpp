#include "DoublyLinkedList.h"


	//Constructor
	DoublyLinkedList::DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
	};

	//Functions


	//adds node to end
	void DoublyLinkedList::AddNode(int value) {
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
	};

	//inserts before head
	void DoublyLinkedList::InsertAtBegin(int value) {
		Node* node = new Node(value);
		head->prev = node;
		node->next = head;
		head = node;
		std::cout << head->value << " insert at begin complete" << std::endl;
	};

	//inserts after tail
	void DoublyLinkedList::InsertAtEnd(int value) {
		Node* node = new Node(value);
		tail->next = node;
		node->prev = tail;
		tail = node;
		std::cout << tail->value << " insert at end complete" << std::endl;
	};

	//inserts in list by iterating into list by position amount
	void DoublyLinkedList::InsertAtPos(int value, int pos) {
		if (pos == 0) { //if being inserted at beginning
			InsertAtBegin(value);
			return;
		}

		Node* node = new Node(value);
		Node* nextPos = head;

		for (int i = pos; i > 0; i--) { //iterates to just before position
			if (nextPos->next == NULL) {
				break;
			}

			nextPos = nextPos->next;
		}

		node->prev = nextPos->prev; //inserts node in between selected position nodes
		node->next = nextPos;

		if (nextPos->prev != NULL) { //sets previous node to properly point to this new node
			nextPos->prev->next = node;
		}
		else {
			head = node;
		}
		if (nextPos != NULL) { //sets next node to properly point to this new node
			nextPos->prev = node;
		}

		std::cout << " insert at specific pos done" << std::endl;
	};

	void DoublyLinkedList::DelAtBegin() {
		head = head->next;
		delete head->prev;
		head->prev = NULL;
		std::cout << " delete at begin complete" << std::endl;
	};

	void DoublyLinkedList::DelAtEnd() {
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
		std::cout << " delete at end complete" << std::endl;
	};

	void DoublyLinkedList::DelAtPos(int pos) {
		if (pos == 0) {
			DelAtBegin();
			return;
		}

		Node* currentNode = head;

		for (int i = pos - 1; i > 0; i--) {//iterates through to position

			if (currentNode->next == NULL) {
				DelAtEnd();
				delete currentNode;
				return;
			}

			currentNode = currentNode->next;

		}

		currentNode->next->prev = currentNode->prev; //links currentNodes next and previous together
		currentNode->prev->next = currentNode->next;

		delete currentNode;

		std::cout << " delete at specific pos done" << std::endl;
	};

	int DoublyLinkedList::GetListCount() {
		Node* currentNode = head;
		int amount = 0;
		while (currentNode != NULL) {
			currentNode = currentNode->next;
			amount++;
		}

		return amount;
	}

	
	//recursive function to compare and switch nodes using a bubble sort
	void DoublyLinkedList::CompareAndSwitch(Node* current, Node* next, bool returnOnThisCall) {
		if (returnOnThisCall) { //checks to see if sortings is done
			return;
		}

		if (next) {
			if (current->value > next->value) { //if current is greater than next, switch based on certain conditions
				if (current == head) { //if current is head switch and set next to be head
					current->next = next->next;
					current->prev = next;

					next->next->prev = current;
					next->next = current;
					
					next->prev = NULL;
					head = next;
				}
				else if (next == tail) {//if current is tail switch and set current to be tail
					current->next = NULL;
					current->prev->next = next;
					
					next->next = current;
					next->prev = current->prev;

					current->prev = next;
					tail = current;
				}
				else { //if its a position in the list that isnt head or tail
					next->next->prev = current;
					current->prev->next = next;
					
					next->prev = current->prev;
					
					current->next = next->next;
					current->prev = next;

					next->next = current;
				}
				CompareAndSwitch(head, head->next, false); //recurses
			}
			else {
				if (current->next == NULL) {
					CompareAndSwitch(current->next, next->next, true); //if iterating is completed, then next call will return null
				}
				else {
					CompareAndSwitch(current->next, next->next, false); 

				}

			}
		}
	}

	void DoublyLinkedList::SortList()
	{
		CompareAndSwitch(head, head->next, false);

	}

	void DoublyLinkedList::PrintList(std::string message) {
		std::string nullString = "NULL";

		std::cout << "\n------" << message << "------" << std::endl;
		Node* currentNode = head;
		int amount = 0;
		while (currentNode != NULL) {
			std::cout << "Node(" << amount << ") value: " << currentNode->value << "    |||||||    ";
			if (currentNode->prev) {
				std::cout << " prev: " << currentNode->prev->value;
			}
			if (currentNode->next) {
				std::cout << " next: " << currentNode->next->value << std::endl;
			}
			currentNode = currentNode->next;
			amount++;
		}

		std::cout << "\nhead: " << head->value << " || tail: " << tail->value << std::endl;
	}

	DoublyLinkedList::Node* DoublyLinkedList::Traverse(Node* current, int amount)
	{
		if (current->next && amount > 0) {
			Traverse(current->next, amount - 1);
		}
		else {
			return current;
		}
	};
