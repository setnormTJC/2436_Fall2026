//
// Created by Work on 10/6/2026.
//

#ifndef INC_2436_FALL2026_LINKEDLIST_H
#define INC_2436_FALL2026_LINKEDLIST_H

#include <iostream>
#include<memory> //for std::unique_ptr (a "smart" pointer that does not allow memory leaks)

template <typename T>
class LinkedList; //this is a "forward declaration"

///@brief This is a "self-referential" class
template<typename T>
class Node
{
    private:
    T data{}; //braces default initialize whatever data type T is (including complex data types - ex: class Car)
    Node* pNext = nullptr; //a node is defined in terms of itself

    friend class LinkedList<T>; //need for template?
    //friend class LinkedList;
public:
    Node() = default;
    Node(T dataOfInterest, Node* pNext)
    :
    data(dataOfInterest),
    pNext(pNext)
    {

    }
};

///@brief Nota bene: for simplicity, this uses raw pointers, new operator, and has memory leaks
template<typename T>
class LinkedList //redefinition error due to friend class declaration above
{
    //let's fill this up with member variable (single)
    //and functions (ex: traverse, insert, etc.)
private:
    Node<T>* pHead = nullptr;
    //why not also store pTail?
    Node<T> *pTail = nullptr;
    //adding this requires "extra" (auxillary) space for a singly-linked list, but reduces time complexity of pushBack

public:
    LinkedList() = default;
    LinkedList(T dataInTheHeadNode)
    {
        pHead = new Node<T>(dataInTheHeadNode, nullptr);

        //the new node is the ONLY node (it is both head AND tail)
        pTail = pHead;
    }

    ///@brief inserts newData into the HEAD node of the list <br>
    ///complexity is O(1)
    void pushFront(T newData)
    {
        Node<T>* pNew = new Node<T>(newData, nullptr);

        //handle edge case first: list is EMPTY when calling this function
        if (pHead == nullptr)
        {
            pHead = pNew;
            pTail = pNew;
            return; //go no further
        }

        //"non-edge case"
        pNew->pNext = pHead;
        pHead = pNew;
    }

    ///@brief insert newData into the REAR/TAIL node of the list<br>
    ///complexity is O(1) -> constant, terrific!
    void pushBack(T newData)
    {
        Node<T>* pNew = new Node<T>(newData, nullptr);

        Node<T>* pCurrent = pHead;

        if (pHead == nullptr)
        {
            pHead = pNew;
            pTail = pNew;
            return;
        }

        pTail->pNext = pNew;

        pTail = pNew;

    }

    ///@brief (single-ended) queue needs popFront (FIFO)<br>
    ///complexity is O(1)
    void popFront()
    {
        //NOTA BENE: since we are using raw pointers and the NEW operator, delete should be used here
        //(but isn't for the sake of "simplicity")
        if (pHead == nullptr)
        {
            std::cout << "Cannot pop empty list!" << std::endl;
            return;
        }

        //Should pTail be updated? What if pHead is the ONLY node in the list when this function is called?
        if (pHead->pNext == nullptr)
        {
            pTail = nullptr;
        }

        pHead = pHead->pNext;

    }

    ///complexity is O(N)
    void traverse() const //mark as constant because pHead and pTail will NOT be changed by this algo.
    {
        //for an array:
        //for (int index = 0; index < arrayName.size(); ++index)
        //print arrayName[index]

        Node<T>* pCurrent = pHead;

        while (pCurrent != nullptr)
        {
            std::cout << pCurrent->data << std::endl;
            //advance to next node
            pCurrent = pCurrent->pNext; //step forward (analogous to index = index + 1 in array traversal algo)
        }
    }
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
