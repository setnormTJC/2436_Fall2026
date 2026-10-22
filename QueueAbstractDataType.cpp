//
// Created by Work on 10/20/2026.
//

#include "QueueAbstractDataType.h"

QueueImplementedWithLinkedList::QueueImplementedWithLinkedList() = default; //what does default do here?
QueueImplementedWithLinkedList::QueueImplementedWithLinkedList(const std::string& newValue)
    :
linkedList(newValue) //calls the parameterized constructor of LinkedList class
{
}

void QueueImplementedWithLinkedList::pushBack(const std::string& newValue)
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

QueueImplementedWithAVector::QueueImplementedWithAVector() = default; //makes an empty vector initially

void QueueImplementedWithAVector::pushBack(const std::string &newValue)
{
    vector.push_back(newValue); //what is the time complexity of this?
}

void QueueImplementedWithAVector::popFront()
{
    //vector.pop_back();//no! ... there is no pop_front in std::vector? (thoughts re: why?)

    //"left shift" array elements
    for (int i = 0; i < vector.size() - 1; ++i) //Note the -1 -> be careful of out of bounds error
    {
        //"left"      //"right"
        vector[i] = vector[i + 1];
    }
    //this is relatively expensive -> O(N)
}

void QueueImplementedWithAVector::traverse()
{
    for (int i = 0; i < vector.size(); ++i)
    {
        std::cout << vector[i] << std::endl;
    }

}


//it calls the default constructor of the LinkedList class (so a default constructor MUST exist there)
