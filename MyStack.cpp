//
// Created by Work on 9/22/2026.
//

#include "MyStack.h"

#include<stack>
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
bool StackApplications::isBalanced(const std::string &expression)

{
    std::stack<char> stackOfOpenParentheses;

    for (int i = 0; i < expression.size(); ++i)
    {
        if (expression[i] == '(')
            stackOfOpenParentheses.push(expression[i]);

        else if (expression[i] == ')') //mutually exclusive
        {
            if (stackOfOpenParentheses.empty() == false)
            {
                stackOfOpenParentheses.pop();
            }
        }
    }

    return (stackOfOpenParentheses.empty());

}
