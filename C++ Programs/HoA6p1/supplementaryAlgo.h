#include <iostream>
#include <vector>
#include <list>

#ifndef SUPPLEMENTARYALGO_H
#define SUPPLEMENTARYALGO_H

//Problem 1

template <typename T>
int linearSearchCountArr(std::vector<T>& data, T dataFind){
    //Step 1: I := 0
    int i = 0;
    int comparisons = 0;

    //Repeat while 
    while(i < (int)data.size()){
        comparisons++;

        if(dataFind == data[i]){
            std::cout << "the search is success";
            return comparisons;
        }

        i++;
    }

    std::cout << "the element is not found\n";
    return comparisons;
}

//Linked list version
template <typename T>
int linearSearchCountLL(std::list<T>& data, T dataFind){
    int comparisons = 0;
    int index = 0;

    //repeat the loop 
    for(auto it = data.begin(); it != data.end(); ++it, ++index){
        comparisons++;

        if(dataFind == *it){
            std::cout << "the search was a success\n";
            return comparisons;
        }
    }

    //the searching reached the end -> search is unsuccessful
    std::cout << "the search was unsuccessful\n";
    return comparisons;
}

//Problem 2:

template <typename T>
int countOccurrences(std::vector<T>& data, T k){
    int count = 0;

    //Repeat while I <= n 
    for(int i = 0; i < (int)data.size(); i++){
        if(data[i] == k){
            count++;
        }
    }

    std::cout << "'" << k << "' appears " << count << " time(s) in the list\n";
    return count;
}

//Problem 3:

template <typename T>
void binarySearchVerbose(std::vector<T>& data, T findData){

    //start of the array
    int start = 0;

    //last position of the array
    int last = (int)data.size() - 1;
    int step = 1;

    while(start <= last){

        //Find middle element
        int mid = (start + last) / 2;

        std::cout << "  Iteration " << step << ": low = " << start
                   << ", mid = " << mid << " (value " << data[mid]
                   << "), high = " << last << "\n";
        step++;

        //If middle element is equal to key
        if(data[mid] == findData){
            std::cout << "the search was a success\n";
            return;
        }

        else if(data[mid] > findData){
            last = mid - 1;
        }

        else{
            start = mid + 1;
        }
    }

    //Search unsuccessful
    std::cout << "the search was unsuccessful\n";
}


//Problem 4:

template <typename T>
void binarySearchRecursive(std::vector<T>& data, int low, int high, T findData, int step = 1){

    if(low > high){
        std::cout << "the search was unsuccessful\n";
        return;
    }

    int mid = (low + high) / 2;

    std::cout << "  Iteration " << step << ": low = " << low
               << ", mid = " << mid << " (value " << data[mid]
               << "), high = " << high << "\n";

  
    if(data[mid] == findData){
        std::cout << "the search was a success\n";
        return;
    }

    else if(data[mid] > findData){
        binarySearchRecursive(data, low, mid - 1, findData, step + 1);
    }

    else{
        binarySearchRecursive(data, mid + 1, high, findData, step + 1);
    }
}

#endif