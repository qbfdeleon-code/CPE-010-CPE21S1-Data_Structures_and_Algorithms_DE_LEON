#include <iostream>
#include <ctime>
#include "SortingAlgo.h"

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

//PROBLEM 1
void QuickShellSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        int leftSize = pivotIndex - low;
        int rightSize = high - pivotIndex;

        //Sort left sub-list with shellSort instead of recursive quicksort
        if (leftSize > 0) {
            int* leftSub = new int[leftSize];
            for (int i = 0; i < leftSize; i++)
                leftSub[i] = arr[low + i];

            shellSort(leftSub, leftSize);

            for (int i = 0; i < leftSize; i++)
                arr[low + i] = leftSub[i];

            delete[] leftSub;
        }

        //Sort right sub-list with shellSort instead of recursive quicksort
        if (rightSize > 0) {
            int* rightSub = new int[rightSize];
            for (int i = 0; i < rightSize; i++)
                rightSub[i] = arr[pivotIndex + 1 + i];

            shellSort(rightSub, rightSize);

            for (int i = 0; i < rightSize; i++)
                arr[pivotIndex + 1 + i] = rightSub[i];

            delete[] rightSub;
        }
    }
}

void Problem1() {
    std::cout << "Problem 1: Quicksort" << std::endl;

    int arr[] = {8, 24, 7, 6, 18, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArr(arr, n);

    QuickShellSort(arr, 0, n - 1);

    std::cout << "Sorted array (sorted by shellSort): ";
    printArr(arr, n);
    std::cout << std::endl;
}

//PROBLEM 2
void Problem2() {
    std::cout << "Problem 2: Quicksort vs Merge Sort" << std::endl;

    int original[] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    int n = sizeof(original) / sizeof(original[0]);

    std::cout << "Original array: ";
    printArr(original, n);

    //Quick Sort
    int quickArr[15];
    for (int i = 0; i < n; i++) quickArr[i] = original[i];

    clock_t startQ = clock();
    quickSort(quickArr, 0, n - 1);
    clock_t endQ = clock();

    std::cout << "Quicksort result: ";
    printArr(quickArr, n);
    std::cout << "Quicksort time: " << (endQ - startQ) << std::endl;

    //Merge Sort
    int mergeArr[15];
    for (int i = 0; i < n; i++) mergeArr[i] = original[i];

    clock_t startM = clock();
    mergeSort(mergeArr, 0, n - 1);
    clock_t endM = clock();

    std::cout << "Merge sort result: ";
    printArr(mergeArr, n);
    std::cout << "Merge sort time: " << (endM - startM) << std::endl;
}

int main() {
    
    Problem1();
    Problem2();
    
    return 0;
}