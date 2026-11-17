//
// Created by Work on 11/12/2026.
//

#include "BinaryTree.h"

#include<iostream>

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
    //for singly-linked lists, we used "raw" pointers:
    // Node* pNew = new Node(newData);

    std::unique_ptr<Node> pNew = std::make_unique<Node>(newData);
    //std::unique_ptr
    if (pRoot->pLeft == nullptr)
    {
        pRoot->pLeft = std::move(pNew);
    }

    else if (pRoot->pRight == nullptr)
    {
        pRoot->pRight = std::move(pNew);
    }

    //second level (begin the SILLY approach):
    else if (pRoot->pLeft->pLeft == nullptr)
    {
        pRoot->pLeft->pLeft = std::move(pNew);
    }

    else if (pRoot->pLeft->pRight == nullptr)
    {
        pRoot->pLeft->pRight = std::move(pNew);
    }
}

Node* BinaryTree::getPRoot() const
{
    return pRoot.get();
}

void BinaryTree::print(Node* pCurrent) const
{
    if (pCurrent == nullptr) //base case (termination) of recursion
    {
        return;
    }

    std::cout << pCurrent->data << std::endl; //"visit"
    print(pCurrent->pLeft.get()); //recurse!
    print(pCurrent->pRight.get());
}

// {
//     pRoot = nullptr;
//     std::cout << "Called default constructor of the binary tree class" << std::endl;
// }




