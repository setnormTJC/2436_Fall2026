//
// Created by Work on 9/22/2026.
//

#ifndef INC_2436_FALL2026_MYSTACK_H
#define INC_2436_FALL2026_MYSTACK_H
#include <string>
#include <vector>


// template<typename T>
class MyStack
{
    static const int STACK_SIZE = 5;
    //a C-style array:
    std::string stackData[STACK_SIZE];
    int topIndex = -1; //means that the stack is empty, by default (needs push ops to fill it up)

public:

    ///@brief inserts an element at the TOP of the stack
    void push(const std::string& newItem);

    ///@brief removes the element on the top of the stack
    void pop();

    ///@returns the element on the top of the stack <br>
    ///(this method does NOT remove that item)
    std::string top();

    MyStack();
};

namespace StackApplications
{

    ///@param -> expression cannot contain {, [ as grouping symbols -> ONLY parentheses are allowed!
    bool isBalanced(const std::string& expression);

    void solveMaze(std::vector<std::vector<char>>& theMaze);
}

#endif //INC_2436_FALL2026_MYSTACK_H
