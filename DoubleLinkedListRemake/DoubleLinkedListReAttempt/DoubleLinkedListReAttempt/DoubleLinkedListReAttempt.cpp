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

		Node(int nodeValue) { value = nodeValue; };

		void SetPrevTo(Node* node) {
			
		};

		void SetNextTo(Node* node) {

		};
		void SwitchWith(Node* otherNode) { //only used on nodes current in list
			Node* currentNode = this;

			//set the corresponding prev/next of this node to the other ones prev/next nodes
			prev = otherNode->prev ? otherNode->prev : NULL; 
			next = otherNode->next ? otherNode->next : NULL;
			//set the neighboring nodes proper prev/next nodes to current
			if (otherNode->prev->next) {
				otherNode->prev->next = currentNode;
			}
			if (otherNode->next->prev) {
				otherNode->next->prev = currentNode;
			}

			//set other nodes prev/next to preSwitched version of this nodes prev/next
			otherNode->prev = currentNode->prev ? currentNode->prev : NULL;
			otherNode->next = currentNode->next ? currentNode->next : NULL;
			//set neighboring nodes of this to proper prev/next nodes to other node
			if (currentNode->prev) {
				currentNode->prev->next = otherNode;
			}
			if (currentNode->next) {
				currentNode->next->prev = otherNode;
			}
		};
		void SqueezeInBetween(DoubleLinkedList* list, Node* leftNode, Node* rightNode) {

			if (leftNode == NULL) {
				list->head = this;
			}
			if (rightNode == NULL) {
				list->tail = this;
			}

			prev = leftNode;
			next = rightNode;

			if (rightNode != NULL && leftNode != NULL) {
				leftNode->next = this;
			}
			
			
			if (leftNode != NULL && rightNode != NULL) {
				rightNode->prev = this;
			}

		};
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
			tail->next = node;
			tail = node;
		}
		
		std::cout << tail->value  << " addnode complete" << std::endl;
		i++;
	};

	/*
	Node* Traverse(int amount) { //traverse through list by specific amount
		if (amount = 0) {
			std::cout << "returning head only" << std::endl;
			return head;
		}

		Node* currentNode = head;
		int amountHolder = amount;
		while (currentNode->next != NULL) {
			std::cout << "loop" << std::endl;
			if (amountHolder > 0) {
				currentNode = currentNode->next;
				amountHolder--;
				std::cout << "minusminus" << std::endl;
			}
			else if(amountHolder <= 0) {
				std::cout << "break" << std::endl;
				break;
			}
			
		}
		return currentNode;
		//return amountHolder > 0 ? currentNode : NULL;
	};*/

	Node* Traverse(Node* startingNode, int amount) { //traverse through list by specific amount
		if (amount > 0) {
			if (startingNode->next != NULL) {
				Traverse(startingNode->next, amount - 1);
			}
			else {
				return startingNode;
			}
		}
		else {
			return startingNode;
		}
	};

	void InsertAtBegin(int value) {
		Node* node = new Node(value);
		node->SqueezeInBetween(this, NULL, head);
		std::cout << head->value << " insert at begin complete" << std::endl;
		i++;

	};

	void InsertAtEnd(int value) {
		Node* node = new Node(value);
		node->SqueezeInBetween(this, tail, NULL);
		std::cout << tail->value << " insert at end complete" << std::endl;
		i++;
	};

	void InsertAtPos(int value, int pos) {
		Node* node = new Node(value);

		Node* positionNode = head;
		Node* nextPositionNode = head->next;
		int posStored = pos;
		bool isFound = false;
		if (pos == 0) {
			isFound = true;
			positionNode = NULL;
			nextPositionNode = head;

		}
		while (!isFound) {
			if (posStored <= 0) {
				std::cout << "breakout" << std::endl;
				isFound = true;
				break;
			}

			if (positionNode->next != NULL) {
				positionNode = positionNode->next;
			}
			else {
				break;
			}
			posStored--;
		}

		
		if (positionNode != NULL && positionNode->next != NULL) {
			nextPositionNode = positionNode->next;
		}
		else{
			nextPositionNode = NULL;
		}
		node->SqueezeInBetween(this, positionNode, nextPositionNode);
		std::cout << " insert at specific pos done" << std::endl;
		i++;
	};

	void DelAtBegin() {

	};

	void DelAtEnd() {

	};

	void DelAtPos(int pos) {

	};

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
	list->InsertAtPos(333, 20);
	list->InsertAtPos(55, 4);


	list->PrintList();

	std::cout << "bruh..................\n";


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
