#include <iostream>
#include "singly_ll.h"

int main() {
    SingleList<int>* head = new SingleList<int>;
    SingleList<int>* second = new SingleList<int>;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = nullptr;

    std::cout << "Linked list traversal: ";
    listTraversal(head);

    std::cout << "Newly inserted head of Linked list: ";
    sllInsertHead(0, &head);
    listTraversal(head);

    // Dynamic deletion starting from current head pointer
    SingleList<int>* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}