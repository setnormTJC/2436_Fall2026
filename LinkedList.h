//
// Created by Work on 10/6/2026.
//

#ifndef INC_2436_FALL2026_LINKEDLIST_H
#define INC_2436_FALL2026_LINKEDLIST_H

#include<memory> //for std::unique_ptr (a "smart" pointer that does not allow memory leaks)


///example of "typical" classes we've built
class Car
{
    std::string make = "Ford";
    int mileCount = 123'456;
    //Car someCar; //no good
};

///@brief This is a "self-referential" class
class Node
{
    //private:
public:
    int data = 0; //
    Node* pNext = nullptr; //a node is defined in terms of itself

    friend class LinkedList; //recall from last semester -> friends can modify and read PRIVATE member variables

public:
    Node();
    Node(int dataOfInterest, Node* pNext);
};

///@brief Nota bene: for simplicity, this uses raw pointers, new operator, and has memory leaks
class LinkedList
{
    //let's fill this up with member variable (single)
    //and functions (ex: traverse, insert, etc.)
private:
    Node* pHead = nullptr;
    //why not also store pTail?
    Node *pTail = nullptr;
    //adding this requires "extra" (auxillary) space for a singly-linked list, but reduces time complexity of pushBack

public:
    LinkedList();
    LinkedList(int dataInTheHeadNode);

    ///@brief inserts newData into the HEAD node of the list
    void pushFront(int newData);
    ///@brief insert newData into the REAR/TAIL node of the list
    void pushBack(int newData);

    ///@brief (single-ended) queue needs popFront (FIFO)
    void popFront(); //remove first element from queue

    void traverse() const; //mark as constant because pHead will NOT be changed by this algo.

};
































///@brief This is a SINGLY-linked node (not a doubly-linked node)
class SmartPointerNode
{
    int data = 0; //let's be brief with the variable name here (this is dataOfInterest)

    //the "dumb", leaky way:
    // Node* pNext; //the address of the next node in the list

    //impossible to leak memory (skyrocket RAM usage)
    std::unique_ptr<SmartPointerNode> pNext;

public:
    SmartPointerNode();
    SmartPointerNode(int data);

    friend class SmartLinkedList;  //note this!
};

///@brief "doubly" and "circularly"-linked lists also exist
class SmartLinkedList
{
    std::unique_ptr<SmartPointerNode> pHead; //the only member variable we need for a singly-linked list
public:
    SmartLinkedList();
    SmartLinkedList(int dataInHeadNode);

    ///@brief inserts a new node at the front of the list<br>
    ///modifies pHead (the sole member variable of this class)
    void pushFront(int newData);

    void popFront();

    void pushBack(int newData);

    ///@brief AKA: print data in all nodes
    void traverse () const;
};



void demoSmartPointerPreventingLeak();

///@brief also called a "naked" or "raw" pointer
void demoStupidPointerLeak();

///@brief note that this uses a raw pointer (because smart pointer's notation looks a bit goofy in this case)
void demoUsefulnessOfPointer();


#endif //INC_2436_FALL2026_LINKEDLIST_H
