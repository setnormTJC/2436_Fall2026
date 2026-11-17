
#include "BinaryTree.h"

int main()
{
    BinaryTree binaryTree('a');

    binaryTree.addData('b');

    binaryTree.addData('c');
    binaryTree.addData('d');
    binaryTree.addData('e');

    Node* pRoot = binaryTree.getPRoot();

    binaryTree.print(pRoot);

    // binaryTree.depthFirstTraverse();
}
