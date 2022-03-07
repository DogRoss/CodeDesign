// DoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class DoubleLinkedList {
public:
    int i = 0; //used for incrementatioin

    class node { //node struct wiht pointer to next and previous, default null
    public:
        int key;          //key is the value assigned to said node
        node* prev;
        node* next;
    }; //when using a typedef, the first instance is the name of struct, followed by name of typedef

    // head/tail and first and temp node pointers are defined here
    node* head = NULL;
    node* first = NULL;
    node* temp = NULL;
    node* tail = NULL;


    //adds node to doubly linked list
    void addnode(int k) {                                   //TODO: you can do this is c#
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

        //Increment for num of nodes in linked list
        i++;
    };

    void traverse() {
        //node points towards head node
        node* ptr = head;

        //while pointer isnt null, traverse and print the mode
        while (ptr != NULL) {

            //Print key of the node
            printf("%d ", ptr->key);
            ptr = ptr->next;
        }

        printf("\n");
    }

    //function to insert a node at the beginning of the linked list
    void insertatbegin(int k) {
        //allocates memory to the node ptr
        node* ptr = (node*)malloc(sizeof(node));

        //assign key to value k
        ptr->key = k;

        // Next and prev pointer to NULL
        ptr->next = NULL;
        ptr->prev = NULL;

        //if head is NULL, then head and tail are the node
        if (head == NULL) {
            first = ptr;
            first = head;
            tail = head;
        }
        else { //if not, insert at the beginning and update head node to be current
            temp = ptr;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        i++;
    }

    //Function to insert node at end
    void insertatend(int k) {
        //allocate memory to node pointer
        node* ptr = (node*)malloc(sizeof(node));

        //assign key to value k
        ptr->key = k;

        //Next and prev pointer to NULL
        ptr->next = NULL;
        ptr->prev = NULL;

        //If head is Null
        if (head == NULL) {
            first = ptr;
            first = head;
            tail = head;
        }
        else { //if not, insert at the end
            temp = ptr;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        i++;
    }

    //insert function to insert at any position in list
    void insertatpos(int k, int pos) { //TODO: clean comments, and names of variables

        //for invalid position
        if (pos < 1 || pos > i + 1) {
            std::cout << "Please enter a valid position" << std::endl;
        }
        else if (pos == 1) { //if at beggining of list, then insert at beginning
            insertatbegin(k);
        }
        else if (pos == i + 1) { // if at end of list, insert at end
            insertatend(k);
        }
        else { //if not at end or beginning, traverse and insert at designated position
            node* src = head;

            //Move head pointer to pos
            while (pos--) {
                src = src->next;
            }

            //Allocate memory to new node
            node** da, ** ba;
            node* ptr = (node*)malloc(sizeof(node));
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->key = k;

            //change prev/next ptr of nodes inserted with prev/next node
            ba = &src;
            da = &(src->prev);
            ptr->next = (*ba);
            ptr->prev = (*da);
            (*da)->next = ptr;
            (*ba)->prev = ptr;
            i++;
        }
    }

    //function to delete node at the beginning of the list
    void delatbegin() {
        //move head to next and decrease length by one
        head = head->next;
        i--;
    }

    //Function to delete node at end of list
    void delatend() {
        //move tail to prev, and decrease lenght by 1
        tail = tail->prev;
        tail->next = NULL;
        i--;
    }

    //function to delete node at specific position
    void delatpos(int pos) {

        //invalid pos
        if (pos < 1 || pos > i + 1) {
            std::cout << "please enter a valid position" << std::endl;
        }

        //if pos is one, del at begin
        else if (pos == 1) {
            delatbegin();
        }

        //if pos is at the end, del at end
        else if (pos == i) {
            delatend();
        }

        //traverse to pos and del
        else {
            //src node to find which node to be deleted
            node* src = head;
            pos--;

            //traverse til node pos
            while (pos--) {
                src = src->next;
            }

            //prev and after node of src node
            node** pre, ** aft;
            pre = &(src->prev);
            aft = &(src->next);

            //change the next and prev ptr of pre and aft node
            (*pre)->next = (*aft);
            (*aft)->prev = (*pre);

            //decrease length of list
            i--;
        }

    }
};



int main() //TODO user interface
{
    DoubleLinkedList linkedList;

    // Adding node to the linked List
    linkedList.addnode(2);
    linkedList.addnode(4);
    linkedList.addnode(9);
    linkedList.addnode(1);
    linkedList.addnode(21);
    linkedList.addnode(22);

    // To print the linked List
    printf("Linked List: ");
    linkedList.traverse();

    printf("\n");

    // To insert node at the beginning
    linkedList.insertatbegin(1);
    printf("Linked List after"
        " inserting 1 "
        "at beginning: ");
    linkedList.traverse();

    // To insert at the end
    linkedList.insertatend(0);
    printf("Linked List after "
        "inserting 0 at end: ");
    linkedList.traverse();

    // To insert Node with
    // value 44 after 3rd Node
    linkedList.insertatpos(44, 3);
    printf("Linked List after "
        "inserting 44 "
        "after 3rd Node: ");
    linkedList.traverse();

    printf("\n");

    // To delete node at the beginning
    linkedList.delatbegin();
    printf("Linked List after "
        "deleting node "
        "at beginning: ");
    linkedList.traverse();

    // To delete at the end
    linkedList.delatend();
    printf("Linked List after "
        "deleting node at end: ");
    linkedList.traverse();

    // To delete Node at position 5
    printf("Linked List after "
        "deleting node "
        "at position 5: ");
    linkedList.delatpos(5);
    linkedList.traverse();


    std::cout << "type 'esc' to exit" << std::endl;
    std::string result;
    std::cin >> result;
    return 0;
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
