//
// Created by Work on 10/20/2026.
//

#include "QueueAbstractDataType.h"

QueueImplementedWithLinkedList::QueueImplementedWithLinkedList() = default; //what does default do here?
QueueImplementedWithLinkedList::QueueImplementedWithLinkedList(int newValue)
    :
linkedList(newValue) //calls the parameterized constructor of LinkedList class
{
}

void QueueImplementedWithLinkedList::pushBack(int newValue)
{
    linkedList.pushBack(newValue); //again, the complexity of this operation is constant! (O(1))
}

void QueueImplementedWithLinkedList::popFront()
{
    linkedList.popFront();
}

void QueueImplementedWithLinkedList::traverse()
{
    linkedList.traverse();

    // while (queue is not empty)
    // {
    //     //get the front element and print
    //     //pop the queue
    // }
}


//it calls the default constructor of the LinkedList class (so a default constructor MUST exist there)
