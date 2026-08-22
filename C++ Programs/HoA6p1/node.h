#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
Node<T>* new_node(T data){
    Node<T>* node = new Node<T>;
    node->data = data;
    node->next = nullptr;
    return node;
}

#endif