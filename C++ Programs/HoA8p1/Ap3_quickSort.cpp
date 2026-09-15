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

    ///A.3 Quick Sort 
    int quickArr[SIZE]; 
    copyArray(original, quickArr, SIZE); 
    quickSort(quickArr, 0, SIZE - 1); 
    std::cout << "=== Table 8-4: Quick Sort Result ===" << std::endl; 
    printArray(quickArr, SIZE); 

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