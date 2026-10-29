//
// Created by Work on 10/20/2026.
//

#ifndef INC_2436_FALL2026_QUEUEABSTRACTDATATYPE_H
#define INC_2436_FALL2026_QUEUEABSTRACTDATATYPE_H
#include <string>
#include<vector>

#include "LinkedList.h"


///@brief this is an ABSTRACT class (it has at least one "pure virtual function")
class QueueAbstractDataType
{
public:
    //virtual means "can be overridden" by children classes
    virtual void pushBack(const std::string& newValue) = 0; //const -> immutable (cannot change)

    virtual void popFront() = 0; //FIFO

};

///@brief this class is CONCRETE (can be "instantiated") <br>
///and it provides specific implementation details for pushBack and popFront
class QueueImplementedWithLinkedList : public QueueAbstractDataType
{
private:
    //composition! returns! ftw (for the win)
    LinkedList<std::string> linkedList; //NOTE the template param here
    //forward_list
public:
    QueueImplementedWithLinkedList();
    QueueImplementedWithLinkedList(const std::string& newValue);

    ///@brief O(1) complexity
    void pushBack(const std::string& newValue) override;
    void popFront() override;

    void traverse();

};


///@brief tricky -> uses a "circular" buffer/array
class QueueImplementedWithAVector : public QueueAbstractDataType
{
private:
    std::vector<std::string> vector;//"underlying implementation/data structure"

public:
    QueueImplementedWithAVector();
    ///@brief O(1) time complexity (not space complexity)
    void pushBack(const std::string& newValue) override;
    ///@brief O(N) complexity! Bad - can do better with linked list implementation
    void popFront() override;
    void traverse();
};

class QueueImplementedWithCircularArray : public QueueAbstractDataType
{
    static const int MAX_SIZE = 3; //kept small for minimization of tedium walking through example
    std::string cStyleArray[MAX_SIZE]; //could have used a vector, but this has some benefits

    //variables that are useful for a clever (circular buffer) approach:
    //construct the queue such that it is EMPTY initially -> so first (non-existent) element is at index -1 (not 0)
    int first = -1; // should index of first element not ALWAYS be 0?  ...
    int last = -1; //index of current last value in array (not MAX_SIZE - 1)

public:
    QueueImplementedWithCircularArray();
    QueueImplementedWithCircularArray(const QueueImplementedWithCircularArray& other);

    void pushBack(const std::string& newValue) override;
    void popFront() override;
    void traverse();

    //some "utility methods" that will be useful:
    bool isEmpty() const; //marked const since this will not alter state of queue
    bool isFull() const;
    std::string front() const;

};

#endif //INC_2436_FALL2026_QUEUEABSTRACTDATATYPE_H
