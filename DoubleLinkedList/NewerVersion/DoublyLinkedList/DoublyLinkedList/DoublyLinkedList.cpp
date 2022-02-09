// DoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int i = 0; //used for incrementatioin

typedef struct node { //node struct wiht pointer to next and previous, default null
    int key;          //key is the value assigned to said node
    struct node* prev;
    struct node* next;
} node; //when using a typedef, the first instance is the name of struct, followed by name of typedef

// head/tail and first and temp node pointers are defined here
node* head = NULL;
node* first = NULL;
node* temp = NULL; 
node* tail = NULL;

//adds node to doubly linked list
void addnote(int k) {                                   //TODO: you can do this is c#
    //allocates memory for node pointer
    node* ptr = (node*)malloc(sizeof(node));

    //assign value to the ptr key
    ptr->key = k;

    //nulls next and prev node ptrs
    ptr->next = NULL;
    ptr->prev = NULL;

    //checks if list is empty, if it is, the first, tail and head are set to the added node
    if (head == NULL) {
        head = ptr;
        first = head;
        tail = head;
    }
    else { //if not empty, then add to the end of the linked list
        temp = ptr;
        first->next = temp;
        temp->prev = first;
        first = temp;
        tail = temp;
    }

    i++
}


int main()
{
    std::cout << "Hello World!\n";
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
