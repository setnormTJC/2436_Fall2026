//
// Created by Work on 10/6/2026.
//

#include "LinkedList.h"

#include <iostream>

Node::Node(int data)
    :
data(data)
{
}

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
