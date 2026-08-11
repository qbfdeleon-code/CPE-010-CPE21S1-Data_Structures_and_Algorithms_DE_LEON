#include <iostream> 
#include "1queuell.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue(&front, &back, 'J');
    std::cout << front->data << " " << back->data << std::endl;

    enqueue(&front, &back, 'I');
    std::cout << front->data << " " << back->data << std::endl;

    enqueue(&front, &back, 'M');
    std::cout << front->data << " " << back->data << std::endl;

    dequeue(&front, &back); 
    std::cout << front->data << " " << back->data << std::endl;

    return 0;
}