#include <iostream>
#include "singly_ll.h"

class Node{
    public:
    char data;
    Node* next;
};


int main(){
    //this line creates a empty linked list
    SingleList<int> *head = new SingleList<int>;
    SingleList<int> *second = new SingleList<int>;
    SingleList<int> *third = new SingleList<int>;
    

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next =third;

    third->data = 3;
    third->next = nullptr;
;
    

    std:: cout << "Linked list traversal: ";
    listTraversal(head);

    delete head;
    delete second;
    delete third;
    return 0;

}