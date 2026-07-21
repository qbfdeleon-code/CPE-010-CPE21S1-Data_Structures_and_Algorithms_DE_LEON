#include <iostream>
#include "singly_ll.h"

int main() {
    SingleList<int>* head = new SingleList<int>;
    head->data = 1;
    head->next = nullptr;

    std::cout << "Initial list: ";
    listTraversal(head);

    sllInsertEnd(10, &head);
    std::cout << "After inserting 10 at end: ";
    listTraversal(head);

    sllInsertEnd(20, &head);
    std::cout << "After inserting 20 at end: ";
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