#include <iostream>

#include "LinkedList.h"
#include "MyStack.h"
#include"cmake-build-debug/_deps/raylib-build/raylib/include/raylib.h"
#include<deque> //double-ended queue
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
    QueueImplementedWithAVector queue;

    //QueueImplementedWithAVector queue("Bob");

    queue.pushBack("Alice");

    queue.pushBack("Carol");

    queue.popFront();

    queue.traverse();

    return 0;
}
