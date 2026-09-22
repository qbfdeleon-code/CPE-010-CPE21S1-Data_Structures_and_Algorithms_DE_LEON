#ifndef BST_H
#define BST_H
 
#include <iostream>
 
template <typename T>
class BinarySearchTree {
private:
    T key;
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;
 
public:
    BinarySearchTree(T val) : key(val), left(nullptr), right(nullptr) {}
 
    ~BinarySearchTree() {
        delete left;
        delete right;
    }
 
    void insert(T value) {
        if (value < key) {
            if (left == nullptr) {
                left = new BinarySearchTree<T>(value);
            } else {
                left->insert(value);
            }
        } else if (value > key) {
            if (right == nullptr) {
                right = new BinarySearchTree<T>(value);
            } else {
                right->insert(value);
            }
        }
    }
 
    void preOrder() {
        std::cout << key << " ";
 
        if (left != nullptr) {
            left->preOrder();
        }
 
        if (right != nullptr) {
            right->preOrder();
        }
    }
 
    void inOrder() {
        if (left != nullptr) {
            left->inOrder();
        }
 
        std::cout << key << " ";
 
        if (right != nullptr) {
            right->inOrder();
        }
    }
 
    void postOrder() {
        if (left != nullptr) {
            left->postOrder();
        }
 
        if (right != nullptr) {
            right->postOrder();
        }
 
        std::cout << key << " ";
    }
};
 
#endif
