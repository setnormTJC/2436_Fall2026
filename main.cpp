#include <iostream>

#include "LinkedList.h"
#include "MyStack.h"
#include"cmake-build-debug/_deps/raylib-build/raylib/include/raylib.h"
#include<string>
#include<chrono>
#include<thread>

#include "QueueAbstractDataType.h"

#include<queue>

void printQueue(std::queue<std::string> queue)//pass by value!
{
    while (queue.empty() == false)
    {
        std::cout << queue.front() << std::endl; //
        queue.pop(); //removes first element (ex: Alice in example in main)
    }
}

int main()
{
    // std::queue<std::string> customersInLine;
    // customersInLine.push("Alice");
    // customersInLine.push("Bob");
    // customersInLine.push("Carol");
    //
    // printQueue(customersInLine);

    QueueImplementedWithLinkedList queue('A');

    queue.pushBack('B');

    queue.pushBack('C');

    queue.traverse();

    // queue.popFront(); //remove Alice
    // queue.popFront(); //remove Bob
    // queue.popFront(); //remove Carol

    return 0;
}
