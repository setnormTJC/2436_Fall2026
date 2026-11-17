//
// Created by Work on 11/12/2026.
//

#ifndef INC_2436_FALL2026_BINARYTREE_H
#define INC_2436_FALL2026_BINARYTREE_H

#include<memory>


// class SinglyLinkedNode
// {
//     int data;
//     // SinglyLinkedNode* pNext;
//
//     std::unique_ptr<SinglyLinkedNode> pNext  = new Node<int;
//     //int* pNext;
// };


class Node
{
    char data = '*';
    std::unique_ptr<Node> pLeft;
    std::unique_ptr<Node> pRight;

public:
    Node();
    Node(char data);

    friend class BinaryTree; //gives BinaryTree access to the three private member variables
};


class BinaryTree
{
    std::unique_ptr<Node> pRoot;

public:
    BinaryTree();
    BinaryTree(char dataInTheRoot);

    void addData(char newData) const;

    ///@brief This is a depth-first search (or traversal) or DFS algorithm - it is recursive
    void print(Node* pCurrent) const;

    Node* getPRoot() const;
};


#endif //INC_2436_FALL2026_BINARYTREE_H
