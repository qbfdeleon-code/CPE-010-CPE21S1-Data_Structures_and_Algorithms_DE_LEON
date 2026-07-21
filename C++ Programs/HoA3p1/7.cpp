#include <iostream>
#include "singly_ll.h"

int main() {
    SingleList<int>* head = new SingleList<int>;
    SingleList<int>* second = new SingleList<int>;
    SingleList<int>* third = new SingleList<int>;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = nullptr;

    std::cout << "Initial list: ";
    listTraversal(head);

    std::cout << "Deleting node 20:\n";
    sllDelete(20, &head);
    listTraversal(head);

    std::cout << "Deleting head node 10:\n";
    sllDelete(10, &head);
    listTraversal(head);

    // Cleanup
    SingleList<int>* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}