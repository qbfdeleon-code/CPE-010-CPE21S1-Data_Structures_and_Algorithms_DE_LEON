#ifndef QUEUE_H 
#define QUEUE_H 
#include <iostream>

template <typename T> 
class qNode {
public:
    T data; 
    qNode *next;
};

// creating a new node
template <typename T>
qNode<T>* new_node(T newdata) {
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newdata; 
    newNode->next = nullptr; 
    return newNode;
}

template<typename T> 
void enqueue(qNode<T>** frontPtr, qNode<T>** backPtr, T newData) {
    // creating a NEW NODE 
    qNode<T>* newNode = new_node(newData);
    
    // INSERTING TO AN EMPTY QUEUE
    if((*frontPtr) == nullptr && (*backPtr) == nullptr) {
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }
    // inserting an item into a non empty queue
    else { 
        // point the backPtr NEXT TO THE newNode
        (*backPtr)->next = newNode;
        (*backPtr) = newNode;
    }
}

template<typename T> 
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr) {
    // check if the queue is empty to prevent crashes
    if((*frontPtr) == nullptr) {
        return;
    }
    
    // create a temporary node to store the node to be deleted
    qNode<T>* deleteNode = nullptr;
    deleteNode = (*frontPtr);
    
    // check if the queue is only 1 node
    if((*frontPtr) == (*backPtr)) {
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr; 
        delete deleteNode; 
        return;
    }
    
    // deleting of the node 
    (*frontPtr) = deleteNode->next;
    delete deleteNode;
}

// display all elements in the list
template<typename T> 
void display(qNode<T>* frontPtr) {
    qNode<T> *temp = frontPtr;
    while(temp != nullptr) { 
        std::cout << " " << temp->data;
        temp = temp->next;
    }
}

// return the front 
template<typename T>
T front(qNode<T>* frontPtr) { 
    return frontPtr->data;
}

#endif