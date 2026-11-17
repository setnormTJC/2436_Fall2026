
#include "BinaryTree.h"

int main()
{
    BinaryTree binaryTree('a');

    Node* pRoot = binaryTree.getPRoot();

    for (char letter = 'b'; letter <= 'z'; ++letter)
    {
        binaryTree.addData(letter);
    }

    // binaryTree.depthFirstTraverse(pRoot);
    binaryTree.breadthFirstTraverse();

    // binaryTree.depthFirstTraverse();
}
