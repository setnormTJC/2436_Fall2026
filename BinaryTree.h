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

    ///@brief adds data from top to bottom, left to right <br>
    ///ex: if adding in order: a, b, c, d, tree looks like:
    ///     a
    ///    / \
    ///   b   c
    ///  /
    /// d
    void addData(char newData) const;

    ///@brief This is a depth-first search (or traversal) or DFS algorithm - it is recursive <br>
    ///In particular, it is a "NLR" (pre-order -> visit Node BEFORE left and right children) DFS
    void depthFirstTraverse(Node* pCurrent) const;

    void breadthFirstTraverse() const;

    Node* getPRoot() const;

private:
    ///@brief private helper that is called by "client-facing" `addData` function
    /// (prevents client from having to worry with pRoot)
    void helpAddData(char newData, Node* pCurrent) const;
};


#endif //INC_2436_FALL2026_BINARYTREE_H
