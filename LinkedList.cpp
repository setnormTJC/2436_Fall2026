//
// Created by Work on 10/6/2026.
//

#include "LinkedList.h"

#include <iostream>

#include "raylib.h"


Node::Node() = default; //what does this do? (it sets pointers to nullptr 0x000...000 (16 zeros if in 64 bit app)
Node::Node(int dataOfInterest, Node *pNext)
    :
data(dataOfInterest),
pNext(pNext)
{

}

LinkedList::LinkedList() = default; //what does this do? It initializes pHead to nullptr

LinkedList::LinkedList(int dataInTheHeadNode)
{
    pHead = new Node(dataInTheHeadNode, nullptr);

    //the new node is the ONLY node (it is both head AND tail)
    pTail = pHead;
}

void LinkedList::pushFront(int newData)
{
    Node* pNew = new Node(newData, nullptr);

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

void LinkedList::pushBack(int newData)
{
    Node* pNew = new Node(newData, nullptr);

    pTail->pNext = pNew;

    pTail = pNew;

    // if (pHead == nullptr) //what if the list is empty? Without this if, nullptr gets dereferenced below
    // {
    //     pushFront(newData);
    //     return; //go no further (Gandalf you shall not pass)
    // }
    //
    // Node* pCurrent = pHead;
    //
    // //move pCurrent along until we get to the end of the list
    // while (pCurrent->pNext != nullptr) //caution! what happens here if the list is empty?
    // {
    //     pCurrent = pCurrent->pNext; //analogous to ++i for array traversal
    // }
    //
    // //make new node and update pCurrent's pNext to pNew
    // Node* pNew = new Node(newData, nullptr);
    //
    // pCurrent->pNext = pNew;
}

void LinkedList::popFront()
{
    if (pHead == nullptr)
    {
        std::cout << "Cannot pop empty list!" << std::endl;
        return;
    }

    pHead = pHead->pNext;

    //Should pTail be updated? What if pHead is the ONLY node in the list now?
    if (pHead->pNext == nullptr)
    {
        pTail = pHead; //is this necessary?
    }
}

void LinkedList::traverse() const
{
    //for an array:
    //for (int index = 0; index < arrayName.size(); ++index)
    //print arrayName[index]

    // if (pHead == nullptr) //safety check
    // {
    //     std::cout << "The list is EMPTY! Cannot traverse an empty list!" << std::endl;
    //     return; //early return (prevents dereferencing the nullptr)
    // }

    Node* pCurrent = pHead;

    while (pCurrent != nullptr)
    {
        std::cout << pCurrent->data << std::endl;
        //DrawRectangle(0, 100, ...); //use RayLib dependency to draw boxes for nodes?

        //advance
        pCurrent = pCurrent->pNext; //step forward (analogous to index = index + 1 in array traversal algo)

    }

}

class Queue
{
private:
    LinkedList linkedList; //why use a linked list? BECAUSE "fast" (O(1)) insertion at ... we'll talk about
};

//initializes integers to 0 (and bools to false, etc.)
























SmartPointerNode::SmartPointerNode() = default;
SmartPointerNode::SmartPointerNode(int data)
    :
data(data)
{
}

SmartLinkedList::SmartLinkedList() = default; //default sets pHead to nullptr

SmartLinkedList::SmartLinkedList(int dataInHeadNode)
{
    pHead = std::make_unique<SmartPointerNode>(dataInHeadNode); //what does make_unique do?
}

void SmartLinkedList::pushFront(int newData)
{
    std::unique_ptr<SmartPointerNode> pNew = std::make_unique<SmartPointerNode>(newData);

    pNew->pNext = std::move(pHead); //std::move is a "price" you pay in exchange for no memory leaks

    pHead = std::move(pNew);
}

void SmartLinkedList::popFront()
{
    //safety check (avoid dereferencing nullptr (pHead->pNext) below):
    if (pHead == nullptr)
    {
        //optional print statement - or throw exception (sort of a silent failure if not included)
        return;
    }

    pHead = std::move(pHead->pNext);
}

///@brief O(N) complexity - implemented for the sake of queue (insert in rear)
void SmartLinkedList::pushBack(int newData)
{
    if (pHead == nullptr) //what if the list is empty? Without this if, nullptr gets dereferenced below
    {
        pushFront(newData);
        return; //go no further
    }

    SmartPointerNode* pCurrent = pHead.get();

    //move pCurrent along until we get to the end of the list
    while (pCurrent->pNext != nullptr) //caution! what happens here if the list is empty?
    {
        pCurrent = pCurrent->pNext.get();
    }

    //make new node and update pCurrent's pNext to pNew
    std::unique_ptr<SmartPointerNode> pNew = std::make_unique<SmartPointerNode>(newData);

    pCurrent->pNext = std::move(pNew);
}

void SmartLinkedList::traverse() const
{
    //std::unique_ptr<Node> pCurrent = std::move(pHead); //illegal -> attempting to use deleted copy const. of unique_ptr
    //recall: pHead is the sole member variable of SinglyLinkedList and is of type std::unique_ptr<Node>

    //use a raw pointer here:
    SmartPointerNode* pCurrent = pHead.get();

    while (pCurrent != nullptr)
    {
        std::cout << pCurrent->data << std::endl;
        pCurrent = pCurrent->pNext.get();
    }
}



#pragma region Demos //enables "code folding"
void demoSmartPointerPreventingLeak()
{
    while (true)
    {
        std::unique_ptr<int> ptr = std::make_unique<int>();


        // std::cout << "PTR.get() is" << ptr.get() << std::endl;

    }

}

void demoStupidPointerLeak()
{

    while (true)
    {
        int * i = new int;
        delete i;
    }

}

void demoUsefulnessOfPointer()
{
    // g++ main.cpp
    //vector
    //int bigBoy[1'000'000'000];

    //this is (very roughly) how std::vector works under the hood:
    std::cout << "How many numbers do you want in your list? \n";

    int numberOfThings;
    std::cin>> numberOfThings;

    //use the "new" operator to ask the operating system for a "dynamically allocated" chunk of memory:
    int* pointerToFirstElementInList = new int[numberOfThings];

    std::cout << "The value of pointerToFirstElementInList is: " << pointerToFirstElementInList << std::endl;
    std::cout << "The number of BYTES allocated for an integer is" << sizeof(int) << std::endl;
    int counter = 0;
    while (counter < numberOfThings)
    {
        std::cout << "Enter number at index " << counter << ": " << std::endl;
        int newValue;
        std::cin >> newValue;

        pointerToFirstElementInList[counter] = newValue;

        counter++;
    }

    std::cout << "The dereferenced first memory location is: " << *pointerToFirstElementInList << std::endl;


    int a = 1231;

    delete [] pointerToFirstElementInList; //this prevents a memory leak when raw pointer is used

}

#pragma endregion
