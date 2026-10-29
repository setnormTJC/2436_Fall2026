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
    //vector.pop

    //"left shift" array elements
    for (int i = 0; i < vector.size() - 1; ++i) //Note the -1 -> be careful of out of bounds error
    {
        //"left"      //"right"
        vector[i] = vector[i + 1];
    }

    vector.resize(vector.size() - 1); //"kick out" the duplicate at the end

    //this is relatively expensive -> O(N)
}

void QueueImplementedWithAVector::traverse()
{
    for (int i = 0; i < vector.size(); ++i)
    {
        std::cout << vector[i] << std::endl;
    }
}




QueueImplementedWithCircularArray::QueueImplementedWithCircularArray() = default;

QueueImplementedWithCircularArray::QueueImplementedWithCircularArray(const QueueImplementedWithCircularArray &other)
{
    // std::string copy[MAX_SIZE];
    //
    // for (int i = 0; i < MAX_SIZE - 1; ++i)
    // {
    //     copy[i] = other.cStyleArray[i]; //NOTE the other.
    // }
}

void QueueImplementedWithCircularArray::pushBack(const std::string &newValue)
{

    if (isFull()) //edge case
    {
        std::cout << "queue is full - cannot add more" << std::endl;
        //cStyleArray[last] = new... NO!
        return; //void return type
    }

    else if (isEmpty()) //edge case
    {
        //set both first and last to 0 (the first index in an array)
        first = 0;
        last = 0;
        //(equivalently: first++; last++)
    }

    else //the queue is neither empty nor full
    {
        //last++;  //this is ONE way to do it

        last = (last + 1) % MAX_SIZE; //ANOTHER way (getting "circular")
        //ex: if last == -1 (initially empty), this becomes last = (-1 + 1) % 3 = 0
        //and if last == 0 (before calling this function), this becomes (0 + 1) % 3 = 1
        //...
        //and if last == 4, this becomes (4 + 1) % 3 = 0

        //Now this last example MIGHT seem like it overwrites the FIRST value in the queue
        //BUT look into the definition of `isFull` for that:
        //(returns true if (last + 1) % MAX_QUEUE_CAPACITY == first; -> (4 + 1) % 3 = 0 == 0

    }

    //now put the thing in:
    cStyleArray[last] = newValue;
}

void QueueImplementedWithCircularArray::popFront()
{
    if (isEmpty()) std::cout << "Queue is empty" << std::endl;

    //std::cout << "Dequeueing " << theQueueData[first] << "\n";

    if (first == last) //this means queue will be emptied as a result of this dequeue! "Flip reset"
    {
        first = -1;
        last = -1;
    }

    //first++; //not the best approach...
    else
    {
        first = (first + 1) % MAX_SIZE;
        //last = (last + 1) % MAX_QUEUE_CAPACITY; //DO we need to this? (oh snap!)
    }

}

void QueueImplementedWithCircularArray::traverse()
{
    //make a copy (potentially EXPENSIVE with respect to space (and time))




    //loop through the copy, visiting each front element, then pop until empty:
    //while ()
}

bool QueueImplementedWithCircularArray::isEmpty() const
{
    return first == -1; //pretty sure this is good
}

bool QueueImplementedWithCircularArray::isFull() const
{
    int remainder = (last + 1) % MAX_SIZE; //making this a variable for ease of viewing in debugger...

    return remainder == first;
    //return last == MAX_SIZE - 1;
}

std::string QueueImplementedWithCircularArray::front() const
{
    return cStyleArray[first];
}


//it calls the default constructor of the LinkedList class (so a default constructor MUST exist there)
