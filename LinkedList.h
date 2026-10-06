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
};


///@brief This is a SINGLY-linked node (not a doubly-linked node)
class Node
{
    int data; //let's be brief with the variable name here (this is dataOfInterest)

    //the "dumb", leaky way:
    // Node* pNext; //the address of the next node in the list

    //impossible to leak memory (skyrocket RAM usage)
    std::unique_ptr<Node> pNext;

public:
    Node(int data);

};

class LinkedList
{

};

void demoSmartPointerPreventingLeak();

///@brief also called a "naked" or "raw" pointer
void demoStupidPointerLeak();


///@brief note that this uses a raw pointer (because smart pointer's notation looks a bit goofy in this case)
void demoUsefulnessOfPointer();


#endif //INC_2436_FALL2026_LINKEDLIST_H
