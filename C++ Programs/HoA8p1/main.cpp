#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include "SortingAlgo.h" 

const int SIZE = 100; 

void printArray(int arr[], int n) { 
    for (int i = 0; i < n; i++) { 
        std::cout << arr[i] << " "; 
    } 
    std::cout << std::endl << std::endl; 
} 

void copyArray(int src[], int dest[], int n) { 
    for (int i = 0; i < n; i++) dest[i] = src[i]; 
} 

int main() { 
    //Preparation Task: generate 100 unsorted random elements
    int original[SIZE]; 
    srand(static_cast<unsigned int>(time(0))); 
    for (int i = 0; i < SIZE; i++) { 
        original[i] = rand() % 1000 + 1; // random values 1-1000 
    } 
    
    std::cout << "=== Table 8-1: Original Unsorted Array (100 elements) ===" << std::endl; 
    printArray(original, SIZE); 

    // ---- A.1 Shell Sort (operates on its own copy of the array) ---- 
    int shellArr[SIZE]; 
    copyArray(original, shellArr, SIZE); 
    shellSort(shellArr, SIZE); 
    std::cout << "=== Table 8-2: Shell Sort Result ===" << std::endl; 
    printArray(shellArr, SIZE); 

    // ---- A.2 Merge Sort ---- 
    int mergeArr[SIZE]; 
    copyArray(original, mergeArr, SIZE); 
    mergeSort(mergeArr, 0, SIZE - 1); 
    std::cout << "=== Table 8-3: Merge Sort Result ===" << std::endl; 
    printArray(mergeArr, SIZE); 

    // ---- A.3 Quick Sort ---- 
    int quickArr[SIZE]; 
    copyArray(original, quickArr, SIZE); 
    quickSort(quickArr, 0, SIZE - 1); 
    std::cout << "=== Table 8-4: Quick Sort Result ===" << std::endl; 
    printArray(quickArr, SIZE); 

    return 0; 
}
