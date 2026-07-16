#include <iostream>

// 1. Create a C++ program to swap the two numbers in different variables. 

void swap(int &a, int &b);

int main(){
    int x = 14;
    int y = 28;

    std::cout << "Before swap: x = " << x << ", y = " << y << "\n";

    swap(x, y);

    std::cout << "After swap: x = " << x << ", y = " << y << "\n";

    return 0;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp; 
}