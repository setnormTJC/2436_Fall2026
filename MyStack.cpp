//
// Created by Work on 9/22/2026.
//

#include "MyStack.h"

#include <stdexcept>

void MyStack::push(const std::string &newItem)
{
    if (topIndex >= STACK_SIZE - 1)
    {
        throw std::runtime_error("Stack overflow - there is not enough space in the stack!\n");
    }

    topIndex++;

    stackData[topIndex] = newItem;
}

void MyStack::pop()
{
    if (topIndex == -1)
    {
        throw std::runtime_error("Stack UNDERFLOW - cannot pop an empty stack!\n");
    }
    topIndex--;
}

std::string MyStack::top()
{
    if (topIndex == -1)
    {
        throw std::runtime_error("Stack is empty - cannot retrieve element from empty stack\n");
    }

    return stackData[topIndex];
}

MyStack::MyStack() = default;
