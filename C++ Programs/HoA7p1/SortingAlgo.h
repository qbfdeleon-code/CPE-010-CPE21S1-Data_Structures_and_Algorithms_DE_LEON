#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <utility> // For std::swap

//function for selectionSort to find the index of the smallest element
template <typename T>
int routine_smallest(T arr[], int arrSize, int startIndex) {
    int smallestIndex = startIndex;
    for (int i = startIndex + 1; i < arrSize; i++) {
        if (arr[i] < arr[smallestIndex]) {
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

//Bubble Sort 
template <typename T>
void bubbleSort(T arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        for(int j = i + 1; j < arrSize; j++){
            if(arr[j] < arr[i]){
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

//Insertion Sort 
template <typename T>
void insertionSort(T arr[], int arrSize){
    int k = 1, j;
    T temp;
    
    while(k < arrSize){
        temp = arr[k];
        j = k - 1;
        while(j >= 0 && temp <= arr[j]){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        k++;
    }
}

//Selection Sort 
template <typename T>
void selectionSort(T arr[], int arrSize){
    int POS, temp;
    
    for(int i = 0; i < arrSize; i++){
        POS = routine_smallest(arr, arrSize, i); // returns the index of the smallest
        std::swap(arr[i], arr[POS]);
    }
}

#endif
