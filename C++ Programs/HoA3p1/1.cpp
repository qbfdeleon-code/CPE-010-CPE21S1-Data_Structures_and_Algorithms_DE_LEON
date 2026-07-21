#include <iostream>
#include "singly_ll.h"

int main() {
    // Creating the nodes dynamically
    SingleList<int>* head = new SingleList<int>;
    SingleList<int>* second = new SingleList<int>;
    SingleList<int>* third = new SingleList<int>;

    // Assigning values and pointers
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    // Displaying values manually
    std::cout << "Node 1: " << head->data << std::endl;
    std::cout << "Node 2: " << head->next->data << std::endl;
    std::cout << "Node 3: " << head->next->next->data << std::endl;

    // Deallocation
    delete head;
    delete second;
    delete third;

    return 0;
}