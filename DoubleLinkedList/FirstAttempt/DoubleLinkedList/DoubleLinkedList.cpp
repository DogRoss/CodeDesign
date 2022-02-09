// DoubleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


//template<typename T> class Node
//{
//private:
//    //T data;
//    //T* previous;
//    //T* next;
//
//public:
//
//};
template<typename T>
class Node
{
private:
    //data
    //for now just doing ints
    T data;

    T* previous;
    T* next;
    //previous
    //next

public:

    Node() {};

    Node(T nodeData)
    {
        data = nodeData;
    
    }


};

template<typename T>
class LinkedList
{

    

public:

    //LinkedList() {};

    LinkedList() 
    {
        
    };


    void pushFront(T value) //push a value from the front of the list
    {
        Node<T> storageNodeArray[sizeof(nodeThings)];
        
        for (int i = 0; i < sizeof(nodeThings); i++) //copies data to new array
        {
            storageNodeArray[i] = nodeThings[i];
        }

        nodeThings.memSet;

        //for(int i = 0; i < nodeThing)
        
    }
    //pushBack(value) 
    //insert(Iterator, value) 
    //begin()
    //end() 
    //first()
    //last() 
    //count()
    //erase(iterator)
    //remove(value)
    //popBack() 
    //popFront()
    //empty()
    //clear()


private:
    Node<T> nodeThings[];

    Node<T>* head;
    Node<T>* tail;

};

int main()
{
    Node<int> node(7);
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
