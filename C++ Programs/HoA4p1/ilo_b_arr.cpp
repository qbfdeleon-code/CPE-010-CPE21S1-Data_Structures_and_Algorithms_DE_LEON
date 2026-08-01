#include <iostream>


//static array, what do we need?
const size_t maxCap = 100;
int stack[maxCap];
int top = -1, i, newData, choice;


void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void all_Stack();


int main(){
    std:: cout<<"Give the number of max elemenets for the new stack: ";
    std::cin>> i;
    

    while(true){
        std::cout<<"\nStack operations:"<<std::endl;
        std::cout<< "1. PUSH\n2. POP\n3. TOP\n4. isEMPTY\n5. Show all elements of the stack\n" << std::endl;
        std::cin>> choice;
        
        switch (choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout<< isEmpty()<<std::endl;
            break;
            case 5: all_Stack();
            break;
            default: std::cout<<"Invalid choice"<<std:: endl;
            break;

        }
    }




    return 0;
}

bool isEmpty(){
//  create a conditiom to check wether the top element is equal to -1
    if (top == -1) return true;
    return false;
}
bool isFull(){
    //check if we reached the maximum capacity of the array:
    if(top >= i - 1) return true;
    return false;
}
void push(){
    //check if full -> if yes return an error
    if(top == i-1){
        std:: cout << "Stack overflow\n";
        return;
    }
    std::cout<< "New Value to add into the stack"<<std::endl;
    std::cin >> newData;
    //increment the top(index by 1) then assign the new data;
    stack[++top]= newData;
}

void Top(){
    //check if the stack is empty
    if(isEmpty()){
        std:: cout<< "Stack is Empty."<<std:: endl;
        return;
    }

    std:: cout<<"The element on the top of the stack is " << stack[top]<<std::endl;

}


void pop(){
    //check if empty -> if yes, return error
    if(isEmpty()){
        std::cout << "Stack Underflow." << std::endl;
    return;
}
    //display the top value
    std::cout << "Popping: " << stack[top] << std::endl;
    //decrement top value from stack
    top--;
}

void all_Stack(){
    //print all elements
    if(isEmpty()){
        std::cout << "Stack is Empty." << std::endl;
    return;
}
    
    for (int j = top; j >= 0; j--) {
        std::cout << stack[j] << " ";
    }
    std::cout << std::endl;
}
