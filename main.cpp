#include <iostream>

#include "LinkedList.h"
#include "MyStack.h"

#include<string>

void answerLinkedListQuizQuestions()
{
    //
    Node* pHead = new Node(119, nullptr); //new "goes to the OS and begs for some extra memory"

    Node* pSecond = new Node('t', nullptr);

    Node* pThird = new Node('f', nullptr);
    //in this case third node is also "tail" (last)

    //now that we have the nodes, let's connect them:
    pHead->pNext = pSecond; //connects first (head) to second

    pSecond->pNext = pThird;

    // Node* pCurrent = pSecond;
    //
    // // std::cout << "What is it?" << pThird->pNext->data << std::endl;

    // std::cout << (char)pCurrent->data << std::endl;

    // std::cout << "pHead->data is: " << (char)pHead->data << std::endl; //some memory address (which we CANNOT predict)
    // std::cout << "pHead->pNext is: " << pHead->pNext << std::endl;
    // std::cout << "pSecond->pNext->pData is: " << static_cast<char>(pSecond->pNext->data)<< std::endl;

    // pHead->pNext = something;


    //pHead MIGHT have the value 0xF (as on the quiz)

}

int main()
{
    // LinkedList emptyList;

    // answerLinkedListQuizQuestions();

    LinkedList linkedList('a'); //a is initially at head of list (only contains one node)

    linkedList.pushFront('b');  //put b in front of a

    linkedList.pushFront('c'); //put c in front of b

    linkedList.traverse();//ex: print data in all nodes in list

    //what functionality SHOULD exist for a singly-linked list?


     /******************************Smart pointer-based linked list demos*************************/
    // SmartLinkedList smartLinkedList(97); //97
    //
    // smartLinkedList.pushFront(98);//98,97
    //
    // smartLinkedList.popFront();//97
    //
    // smartLinkedList.pushBack(99); //97,99
    //
    // smartLinkedList.traverse();

    return 0;
}
