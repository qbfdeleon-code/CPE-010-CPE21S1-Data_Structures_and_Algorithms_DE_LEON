#ifndef SINGLY_LL_H //header file name 
#define SINGLY_LL_H  

#include <iostream> // Added to allow std::cout to work

template <typename T> //This makes the class accept any data type 
class SingleList {     
public:     
    T data;     
    SingleList<T> *next = nullptr; // FIXED: Capitalized 'S' to match the class name 
};   

template <typename T> 
void listTraversal(SingleList<T>* head) {      
    while(head != nullptr) { // FIXED: Removed space between ! and =
        std::cout << head->data; // FIXED: Changed < to << 
        
        // to check if the next line is not equal to null         
        if (head->next != nullptr) {             
            std::cout << "->";         
        }         
        head = head->next;     
    }     
    std::cout << std::endl; 
} // FIXED: Removed trailing semicolon (not needed for functions)

#endif
