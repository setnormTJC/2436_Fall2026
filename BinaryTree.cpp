//
// Created by Work on 11/12/2026.
//

#include "BinaryTree.h"

#include<iostream>
#include <queue>

Node::Node() = default; //this sets the char data = we'll see; the pointers get set to NULL pointer (0x0000)
Node::Node(char data)
    :
data(data), pLeft(nullptr), pRight(nullptr)
{

}


BinaryTree::BinaryTree() = default;

BinaryTree::BinaryTree(char dataInTheRoot)
{
    pRoot = std::make_unique<Node>(dataInTheRoot);

}

void BinaryTree::addData(char newData) const
{
    helpAddData(newData, pRoot.get());
}

Node* BinaryTree::getPRoot() const
{
    return pRoot.get();
}

void BinaryTree::helpAddData(char newData, Node* pCurrent) const
{
    std::unique_ptr<Node> pNew = std::make_unique<Node>(newData);
    static bool wasAdded = false; //static modifier here makes the state of the variable ... static (stay the same)
                                    //when function call stack gets popped

    if (pCurrent->pLeft == nullptr) //base case
    {
        pCurrent->pLeft = std::move(pNew);
        wasAdded = true;
    }

    else if (pCurrent->pRight == nullptr) //another base case
    {
        pCurrent->pRight = std::move(pNew);
        wasAdded = true;
    }

    else //recursive case - both the left spot and the right spot are occupied - move down
    {
        helpAddData(newData, pCurrent->pLeft.get());
        if (!wasAdded) //left side was full - look to the right before going down further
        {
            helpAddData(newData, pCurrent->pRight.get());
        }
    }

    // //second level (a SILLY approach):
    // else if (pRoot->pLeft->pLeft == nullptr)
    // {
    //     pRoot->pLeft->pLeft = std::move(pNew);
    // }
    //
    // else if (pRoot->pLeft->pRight == nullptr)
    // {
    //     pRoot->pLeft->pRight = std::move(pNew);
    // }
}

void BinaryTree::depthFirstTraverse(Node* pCurrent) const
{
    if (pCurrent == nullptr) //base case (termination) of recursion
    {
        return;
    }

    std::cout << pCurrent->data << std::endl; //"visit"
    depthFirstTraverse(pCurrent->pLeft.get()); //recurse!
    depthFirstTraverse(pCurrent->pRight.get());
}

void BinaryTree::breadthFirstTraverse() const
{
    //queue to the res-cue
    std::queue<Node*> q;

    q.push(pRoot.get());

    while (q.empty() == false)
    {
        Node* pCurrent = q.front();
        //the "visiting" step (just printing, in this case):
        std::cout << pCurrent->data << std::endl;

        q.pop();

        //get left and right children (if they exist)
        if (pCurrent->pLeft) //more verbosely: if(pCurrent->pLeft != nullptr)
        {
            q.push(pCurrent->pLeft.get());
        }

        if (pCurrent->pRight)
        {
            q.push(pCurrent->pRight.get());
        }
    }
}

// {
//     pRoot = nullptr;
//     std::cout << "Called default constructor of the binary tree class" << std::endl;
// }




