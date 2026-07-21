#include <iostream>
#include "singly_ll.h"

int main() {
    SingleList<int>* head = new SingleList<int>;
    SingleList<int>* second = new SingleList<int>;
    SingleList<int>* third = new SingleList<int>;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    std::cout << "Linked list traversal: ";
    listTraversal(head);

    delete head;
    delete second;
    delete third;

    return 0;
}