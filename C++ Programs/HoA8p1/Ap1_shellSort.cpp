#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include "SortingAlgo.h" 

const int SIZE = 100; 

void printArray(int arr[], int n);

void copyArray(int src[], int dest[], int n);

int main() { 
    //Preparation Task: generate 100 unsorted random elements
    int original[SIZE]; 
    srand(static_cast<unsigned int>(time(0))); 
    for (int i = 0; i < SIZE; i++) { 
        original[i] = rand() % 100;
    } 
    
    std::cout << "=== Table 8-1: Original Unsorted Array ===" << std::endl; 
    printArray(original, SIZE); 

    //A.1 Shell Sort  
    int shellArr[SIZE]; 
    copyArray(original, shellArr, SIZE); 
    shellSort(shellArr, SIZE); 
    std::cout << "=== Table 8-2: Shell Sort Result ===" << std::endl; 
    printArray(shellArr, SIZE); 

    return 0;
}

void printArray(int arr[], int n) { 
    for (int i = 0; i < n; i++) { 
        std::cout << arr[i] << " "; 
    } 
    std::cout << std::endl << std::endl; 
} 

void copyArray(int src[], int dest[], int n) { 
    for (int i = 0; i < n; i++) dest[i] = src[i]; 
} 