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
    
    std::cout << "=== Original Unsorted Array ===" << std::endl; 
    printArray(original, SIZE); 

    //A.2 Merge Sort
    int mergeArr[SIZE]; 
    copyArray(original, mergeArr, SIZE); 
    mergeSort(mergeArr, 0, SIZE - 1); 
    std::cout << "=== Table 8-3: Merge Sort Result ===" << std::endl; 
    printArray(mergeArr, SIZE);

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