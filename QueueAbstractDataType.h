//
// Created by Work on 10/20/2026.
//

#ifndef INC_2436_FALL2026_QUEUEABSTRACTDATATYPE_H
#define INC_2436_FALL2026_QUEUEABSTRACTDATATYPE_H
#include <string>

#include "LinkedList.h"


///@brief this is an ABSTRACT class (it has at least one "pure virtual function")
class QueueAbstractDataType
{
public:
    //virtual means "can be overridden" by children classes
    virtual void pushBack(int newValue) = 0; //const -> immutable (cannot change)

    virtual void popFront() = 0;

};

///@brief this class is CONCRETE (can be "instantiated") <br>
///and it provides specific implementation details for pushBack and popFront
class QueueImplementedWithLinkedList : public QueueAbstractDataType
{
private:
    //composition! returns! ftw (for the win)
    LinkedList linkedList;

public:
    QueueImplementedWithLinkedList();
    QueueImplementedWithLinkedList(int newValue);

    void pushBack(int newValue) override;
    void popFront() override;

    void traverse();

};


///@brief tricky -> uses a "circular" buffer/array
class QueueImplementedWithACStyleArray : public QueueAbstractDataType
{

};


#endif //INC_2436_FALL2026_QUEUEABSTRACTDATATYPE_H
