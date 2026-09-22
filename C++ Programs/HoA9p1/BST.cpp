#include <iostream>
#include "BST.h"
 
int main() {
    // NODE
    BinarySearchTree<int> tree(2);
 
    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);
 
    std::cout << "Pre-order:  "; tree.preOrder();  std::cout << "\n";
    std::cout << "In-order:   "; tree.inOrder();   std::cout << "\n";
    std::cout << "Post-order: "; tree.postOrder(); std::cout << "\n";
 
    return 0;
}