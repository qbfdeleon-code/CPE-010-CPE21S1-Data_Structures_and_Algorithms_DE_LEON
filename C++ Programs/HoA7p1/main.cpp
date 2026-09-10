#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SortingAlgo.h"

const int maxSize = 100;

// Function Prototype
void displayArr(int arr[]);

int main(){
    int unsortedArr[maxSize];
    srand(time(0));
    
    // --- 1. BUBBLE SORT TEST ---
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand() % 100;
    }
    std::cout << "Original Array:\n";
    displayArr(unsortedArr);
    
    std::cout << "\nBubble sort: \n";
    bubbleSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
    
    // --- 2. INSERTION SORT TEST ---
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand() % 100;
    }
    std::cout << "\nOriginal Array:\n";
    displayArr(unsortedArr);
    
    std::cout << "\ninsertionSort: \n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
    
    // --- 3. SELECTION SORT TEST ---
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand() % 100;
    }
    std::cout << "\nOriginal Array:\n";
    displayArr(unsortedArr);
    
    std::cout << "\nselectionSort: \n";
    selectionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);
    
    return 0;
}

// Display function definition
void displayArr(int arr[]){
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
