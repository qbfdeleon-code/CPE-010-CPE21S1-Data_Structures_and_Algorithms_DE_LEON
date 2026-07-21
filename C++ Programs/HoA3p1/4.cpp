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

    std::cout << "Newly inserted after head node:\n";
    sllGeneralInsertion(3, head);
    listTraversal(head);

    std::cout << "Newly inserted after second node:\n";
    sllGeneralInsertion(4, head->next);
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