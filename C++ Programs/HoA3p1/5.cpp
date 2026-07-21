#include <iostream>
#include "singly_ll.h"

int main() {
    // Start with an initial list
    SingleList<int>* head = new SingleList<int>;
    SingleList<int>* second = new SingleList<int>;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = nullptr;

    std::cout << "Initial list: ";
    listTraversal(head);

    // 1. Insert at Head
    std::cout << "Newly inserted head (0): ";
    sllInsertHead(0, &head);
    listTraversal(head);

    // 2. General Insertion (inserting 3 after the second node)
    std::cout << "Newly inserted after second node (3): ";
    sllGeneralInsertion(3, head->next);
    listTraversal(head);

    // 3. Insert at End
    std::cout << "Newly inserted at end (10): ";
    sllInsertEnd(10, &head);
    listTraversal(head);

    // Cleanup memory
    SingleList<int>* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}