#include "DoublyLinkedList.h"


	//Constructor
	DoublyLinkedList::DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
	};

	//Functions



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

	void DoublyLinkedList::InsertAtBegin(int value) {
		Node* node = new Node(value);
		head->prev = node;
		node->next = head;
		head = node;
		std::cout << head->value << " insert at begin complete" << std::endl;
	};

	void DoublyLinkedList::InsertAtEnd(int value) {
		Node* node = new Node(value);
		tail->next = node;
		node->prev = tail;
		tail = node;
		std::cout << tail->value << " insert at end complete" << std::endl;
	};

	void DoublyLinkedList::InsertAtPos(int value, int pos) {
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
	};

	void DoublyLinkedList::DelAtBegin() {
		head = head->next;
		head->prev = NULL;
		std::cout << " delete at begin complete" << std::endl;
	};

	void DoublyLinkedList::DelAtEnd() {
		tail = tail->prev;
		tail->next = NULL;
		std::cout << " delete at end complete" << std::endl;
	};

	void DoublyLinkedList::DelAtPos(int pos) {
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

	/*
	void DoublyLinkedList::CompareAndSwitch(Node* current, Node* next, bool returnOnThisCall) {
		PrintList("CompareDebug");
		if (returnOnThisCall) {
			return;
		}

		if (next) {
			if (current->value > next->value) {

				if (next != tail) {
					current->next = next->next;
					next->next = current;
					if (next->next != NULL) {
						next->next->prev = current;
					}
				}
				else {
					next->next = current;
					tail = current;
					tail->next = NULL;
				}
				
				//PrintList("Checkup One");
				

				if (current->prev) {
					next->prev = current->prev;
					current->prev = next;
				}
				else {
					next->prev = NULL;
					current->prev = next;
				}
				
				//PrintList("Checkup Two");


				if (current == head) {
					head = next;
					head->prev = NULL;
				}

				CompareAndSwitch(head, head->next, false);
			}
			else {
				if (current->next == NULL) {
					CompareAndSwitch(current->next, next->next, true);
				}
				else {
					CompareAndSwitch(current->next, next->next, false);

				}

			}
		}
	}
	*/

	void DoublyLinkedList::CompareAndSwitch(Node* current, Node* next, bool returnOnThisCall) {
		if (returnOnThisCall) {
			return;
		}

		if (next) {
			if (current->value > next->value) {
				if (current == head) {
					current->next = next->next;
					current->prev = next;
					next->next->prev = current;
					next->next = current;
					
					next->prev = NULL;

					head = next;
				}
				else if (next == tail) {
					current->next = NULL;

					current->prev->next = next;
					
					next->next = current;
					next->prev = current->prev;

					current->prev = next;

					tail = current;
				}
				else {
					next->next->prev = current;
					current->prev->next = next;
					
					next->prev = current->prev;
					
					current->next = next->next;
					current->prev = next;

					next->next = current;
				}
				//PrintList("Checkup Two");
				CompareAndSwitch(head, head->next, false);
			}
			else {
				if (current->next == NULL) {
					CompareAndSwitch(current->next, next->next, true);
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
