#include <iostream>
#include "Tree.h"
 
int main() {
    //NODE
    GeneralTree<char> A('A');
 
    GeneralTree<char>* B = A.addChild('B');
    GeneralTree<char>* C = A.addChild('C');
    GeneralTree<char>* D = A.addChild('D');
    GeneralTree<char>* E = A.addChild('E');
    GeneralTree<char>* F = A.addChild('F');
    GeneralTree<char>* G = A.addChild('G');
 
    GeneralTree<char>* H = D->addChild('H');
    GeneralTree<char>* I = E->addChild('I');
    GeneralTree<char>* J = E->addChild('J');
    GeneralTree<char>* P = J->addChild('P');
    GeneralTree<char>* Q = J->addChild('Q');
    GeneralTree<char>* K = F->addChild('K');
    GeneralTree<char>* L = F->addChild('L');
    GeneralTree<char>* M = F->addChild('M');
    GeneralTree<char>* N = G->addChild('N');
 
     
    std::cout << "\n===== Task 3.2: Traversal Output =====\n";
    std::cout << "Pre-order:  "; A.preOrder();  std::cout << "\n";
    std::cout << "Post-order: "; A.postOrder(); std::cout << "\n";
    std::cout << "In-order:   "; A.inOrder();   std::cout << "\n";
 
    std::cout << "\n===== Task 3.3: findData Demo =====\n";
    bool found1 = false;
    std::cout << "findData(1, 'J') -> ";
    A.findData(1, 'J', found1);
    if (!found1) std::cout << "(not found)\n";
 
    bool found2 = false;
    std::cout << "findData(2, 'Z') -> ";
    A.findData(2, 'Z', found2);
    if (!found2) std::cout << "(no output, key not in tree)\n";
 
    std::cout << "\n===== Task 3.4: Add leaf 'O' as a child of G =====\n";
    G->addChild('O');
    std::cout << "Pre-order after insert:  "; A.preOrder(); std::cout << "\n";
 
    bool found3 = false;
    std::cout << "findData(1, 'O') -> ";
    A.findData(1, 'O', found3);
    if (!found3) std::cout << "(not found)\n";
 
    return 0;
}
