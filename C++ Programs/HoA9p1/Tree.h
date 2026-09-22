#ifndef TREE_H
#define TREE_H
 
#include <iostream>
 
template <typename T>
class GeneralTree {
private:
    T key;
    GeneralTree<T>* firstChild;
    GeneralTree<T>* nextSibling;
 
public:
    GeneralTree(T val) : key(val), firstChild(nullptr), nextSibling(nullptr) {}
 
    ~GeneralTree() {
        delete firstChild;
        delete nextSibling;
    }
 
    T getKey() {
        return key;
    }
 
    //Creates a new node 
    GeneralTree<T>* addChild(T value) {
        GeneralTree<T>* child = new GeneralTree<T>(value);
 
        if (firstChild == nullptr) {
            firstChild = child;
        } else {
            GeneralTree<T>* sibling = firstChild;
            while (sibling->nextSibling != nullptr) {
                sibling = sibling->nextSibling;
            }
            sibling->nextSibling = child;
        }
 
        return child;
    }
 
   
 
 
    void preOrder() {
        std::cout << key << " ";
 
        for (GeneralTree<T>* c = firstChild; c != nullptr; c = c->nextSibling) {
            c->preOrder();
        }
    }
 
    void postOrder() {
        for (GeneralTree<T>* c = firstChild; c != nullptr; c = c->nextSibling) {
            c->postOrder();
        }
 
        std::cout << key << " ";
    }
 

    void inOrder() {
        if (firstChild != nullptr) {
            firstChild->inOrder();
        }
 
        std::cout << key << " ";
 
        if (firstChild != nullptr) {
            for (GeneralTree<T>* c = firstChild->nextSibling; c != nullptr; c = c->nextSibling) {
                c->inOrder();
            }
        }
    }
 
    //Locates the node holding `value` anywhere in this subtree.
    GeneralTree<T>* find(T value) {
        if (key == value) {
            return this;
        }
 
        for (GeneralTree<T>* c = firstChild; c != nullptr; c = c->nextSibling) {
            GeneralTree<T>* result = c->find(value);
            if (result != nullptr) {
                return result;
            }
        }
 
        return nullptr;
    }
 
    //Traverses using the chosen order
    void findData(int choice, T target, bool& foundFlag) {
        if (foundFlag) {
            return;
        }
 
        if (choice == 1) {
            if (key == target) {
                std::cout << target << " was found!" << std::endl;
                foundFlag = true;
            }
            for (GeneralTree<T>* c = firstChild; c != nullptr && !foundFlag; c = c->nextSibling) {
                c->findData(choice, target, foundFlag);
            }
        } else if (choice == 2) {
            for (GeneralTree<T>* c = firstChild; c != nullptr && !foundFlag; c = c->nextSibling) {
                c->findData(choice, target, foundFlag);
            }
            if (!foundFlag && key == target) {
                std::cout << target << " was found!" << std::endl;
                foundFlag = true;
            }
        } else if (choice == 3) {
            if (firstChild != nullptr) {
                firstChild->findData(choice, target, foundFlag);
            }
            if (!foundFlag && key == target) {
                std::cout << target << " was found!" << std::endl;
                foundFlag = true;
            }
            if (firstChild != nullptr) {
                for (GeneralTree<T>* c = firstChild->nextSibling; c != nullptr && !foundFlag; c = c->nextSibling) {
                    c->findData(choice, target, foundFlag);
                }
            }
        }
    }
};
 
#endif