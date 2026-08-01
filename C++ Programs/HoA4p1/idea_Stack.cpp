#include <iostream>

// Static array configurations
const size_t maxCap = 100;
int stack[maxCap];
int top = -1; 
int i;         // This stores the user's custom maximum size
int newData, choice;

// Function declarations
void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void all_Stack();

int main() {
    std::cout << "Give the number of max elements for the new stack (Max 100): ";
    std::cin >> i;
    
    // Safety check to ensure user doesn't exceed array boundary
    if (i > maxCap) {
        std::cout << "Forcing max elements to 100 (array capacity limit).\n";
        i = maxCap;
    }

    while (true) {
        std::cout << "\n--- STACK OPERATIONS ---" << std::endl;
        std::cout << "1. PUSH\n2. POP\n3. TOP\n4. isEMPTY\n5. Show all elements\n6. EXIT\nChoice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: 
                push();
                break;
            case 2: 
                pop();
                break;
            case 3: 
                Top();
                break;
            case 4: 
                std::cout << (isEmpty() ? "Stack is Empty (True)" : "Stack is Not Empty (False)") << std::endl;
                break;
            case 5: 
                all_Stack();
                break;
            case 6:
                std::cout << "Exiting program..." << std::endl;
                return 0;
            default: 
                std::cout << "Invalid choice" << std::endl;
                break;
        }
    }
    return 0;
}

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    // Fixed: Must check against the user's limit 'i', not hardcoded 100
    return (top == i - 1);
}

void push() {
    // Fixed: Replaced custom condition with the isFull() helper function
    if (isFull()) {
        std::cout << "Stack Overflow! Cannot add more elements." << std::endl;
        return;
    }
    std::cout << "New Value to add into the stack: ";
    std::cin >> newData;
    
    stack[++top] = newData;
}

void Top() {
    if (isEmpty()) {
        std::cout << "Stack is Empty." << std::endl;
        return; // Fixed: Added return to prevent accessing stack[-1]
    }
    std::cout << "The element on the top of the stack is: " << stack[top] << std::endl;
}

void pop() {
    if (isEmpty()) {
        std::cout << "Stack Underflow. Cannot pop." << std::endl;
        return;
    }
    std::cout << "Popping: " << stack[top] << std::endl;
    top--;
}

// Completed: Displays all elements from Top down to Bottom
void all_Stack() {
    if (isEmpty()) {
        std::cout << "Stack is Empty. Nothing to show." << std::endl;
        return;
    }
    
    std::cout << "Current Stack (Top to Bottom):\n";
    for (int index = top; index >= 0; index--) {
        std::cout << "| " << stack[index] << " |\n";
    }
    std::cout << "-------\n";
}
