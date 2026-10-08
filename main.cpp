#include <iostream>

#include "LinkedList.h"
#include "MyStack.h"

#include<string>

int main()
{
    Node* pHead = new Node(97, nullptr);

    Node* pSecond = new Node(98, nullptr); //0x123...

    pHead->pNext = pSecond;

    std::cout << "pHead is: " << pHead << std::endl;
    std::cout << "pHead->data is: " << pHead->data << std::endl;
    //std::cout << pHead->pSecond << std::endl; //(intentional) ERROR

    return 0;
}
