#ifndef STACK_LIST_H
#define STACK_LIST_H

template <typename T>
class Node{
    public:
    T data;
    Node* next;
};

template <typename T>
Node<T> *head = nullptr;

template <typename T>
void push(T newData){

    Node<T>* newNode = new Node<T>;
    newNode->data= newData;

    newNode->next = head<T>;
    head<T> = newNode;

}

template <typename T>
T pop(){

    if (head<T> == nullptr)
    std::cout<< "Stack Overflow \n";

Node<T>* temp = head<T>;

T tempVal = temp->data;

head<T> = head<T>->next;

delete temp;

return tempVal;

}

template <typename T>
void Top(){

    if(head<T> == nullptr){
        std::cout<<"\n----- Stack Underflow -----\n"<<std::endl;
        return;
    }

    std::cout<<"Top of Stack: " <<head<T>->data <<std::endl;
}

template<typename T>
bool isEmpty(){
    return head <T> == nullptr;
}

template<typename T>
void displayAll(){

    if(head<T> == nullptr){

        std::cout<<"The Stack is Empty\n";
        return;
    }
    std::cout<<"\n---- Displaying the Stack ----\n";
    Node<T>* currentNode = head<T>;

    while(currentNode != nullptr){

        std::cout<< currentNode->data << std:: endl;
        currentNode = currentNode-> next;
    }
    std::cout << "\n";
}

#endif
