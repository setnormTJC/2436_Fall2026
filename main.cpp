#include <iostream>

#include "MyStack.h"


int main()
{
    try
    {
        //pop -> might throw
        MyStack myStack;
        // myStack.pop();

        myStack.push("Alice"); //increased topIndex from -1 (init empty) to 0
        myStack.push("Bob"); //increased topIndex to 1
        myStack.push("Carol"); //topIndex became 2
        myStack.push("Darth"); //topIndex became 3
        myStack.push("Eve");

        // myStack.push("Frank");

        myStack.pop();

        std::cout << myStack.top() << "\n";

        //check for "balanced expression" (apply the stack data structure)
    }

    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

    return 0;
}
