//
// Created by Work on 10/6/2026.
//

#include "LinkedList.h"

#include <iostream>


Node::Node() = default; //what does this do? (it sets pointers to nullptr 0x000...000 (16 zeros if in 64 bit app)
Node::Node(int dataOfInterest, Node *pNext)
    :
data(dataOfInterest),
pNext(pNext)
{

}

//initializes integers to 0 (and bools to false, etc.)


SmartPointerNode::SmartPointerNode() = default;
SmartPointerNode::SmartPointerNode(int data)
    :
data(data)
{
}

SinglyLinkedList::SinglyLinkedList() = default; //default sets pHead to nullptr

SinglyLinkedList::SinglyLinkedList(int dataInHeadNode)
{
    pHead = std::make_unique<SmartPointerNode>(dataInHeadNode); //what does make_unique do?
}

void SinglyLinkedList::pushFront(int newData)
{
    std::unique_ptr<SmartPointerNode> pNew = std::make_unique<SmartPointerNode>(newData);

    pNew->pNext = std::move(pHead); //std::move is a "price" you pay in exchange for no memory leaks

    pHead = std::move(pNew);
}

void SinglyLinkedList::traverse() const
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
