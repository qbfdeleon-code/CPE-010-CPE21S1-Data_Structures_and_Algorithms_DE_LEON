#include <iostream>
#include "BinaryTree.h"


/* E
        A
       / \
      B   C
     / \ / \
    D  E F  NULLPTR

*/

int main(){

    //create the root node
    BinaryTree<char>* root = new BinaryTree<char>('A');

    //CREATE THE CHILDREN OF A
    root->insertLeft('B');
    root->insertRight('C');

    //CREATE THE CHILDREN OF B
    root->getLeftChild()->insertLeft('D');
    root->getLeftChild()->insertRight('E');

    //CREATE THE CHILDREN OF C
    root->getRightChild()->insertLeft('F');

    //PRINT TO MATCH PHOTO OUTPUT
    std::cout << "Root: " << root->getRootVal() << std::endl;
    std::cout << "Left Child of A: " << root->getLeftChild()->getRootVal() << std::endl;
    std::cout << "Right Child of A: " << root->getRightChild()->getRootVal() << std::endl;
    std::cout << "Right Child of C: " << root->getRightChild()->getLeftChild()->getRootVal() << std::endl;

    return 0;
}