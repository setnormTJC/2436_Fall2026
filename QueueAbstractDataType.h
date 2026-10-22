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
    //variables that are useful for a clever (circular buffer) approach:
    int first, last; //indices of first and last elements in the array (first is not always ZERO???)
public:
    QueueImplementedWithAVector();

    void pushBack(const std::string& newValue) override;
    void popFront() override;
    void traverse();
};


#endif //INC_2436_FALL2026_QUEUEABSTRACTDATATYPE_H
