#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

template <typename T>
void insertionSort(T arr[], const int N) {
    int k = 0, J, temp;

    while (k < N) {    
        temp = arr[k];

        J = k - 1;
        
        while (J >= 0 && temp <= arr[J]) {
            
            arr[J + 1] = arr[J];
            
            J--;
            
        }

        
        arr[J + 1] = temp;
        
        k++;
    }
    
}

#endif 