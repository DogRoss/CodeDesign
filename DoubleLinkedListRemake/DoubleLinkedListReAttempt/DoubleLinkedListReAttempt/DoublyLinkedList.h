#pragma once

#include <iostream>
#include <string>
#include <functional>

class DoublyLinkedList
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
	Node* head;
	Node* tail;

	//Constructor
	DoublyLinkedList();

	//Functions

	void AddNode(int value);

	void InsertAtBegin(int value);

	void InsertAtEnd(int value);

	void InsertAtPos(int value, int pos);

	void DelAtBegin();

	void DelAtEnd();

	void DelAtPos(int pos);

	int GetListCount();

	void CompareAndSwitch(Node* current, Node* next, bool returnOnThisCall);

	void SortList();

	void PrintList(std::string message = "Default Print");

	Node* Traverse(Node* current, int amount);
};

