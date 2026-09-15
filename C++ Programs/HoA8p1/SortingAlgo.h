#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H

#include <utility> // std::swap

//A.1 SHELL SORT
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        //gap-insertion sort for this interval
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}


//A.2 MERGE SORT
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;   // size of left sub-array
    int n2 = right - mid;      // size of right sub-array

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; 
        mergeSort(arr, left, mid);           
        mergeSort(arr, mid + 1, right);      
        merge(arr, left, mid, right);        
    }
}


//A.3 QUICK SORT
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]); // place pivot in its correct spot
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

#endif 