#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SortingAlgo.h"

const int maxSize = 100;

//Function Prototype
void displayArr(int arr[]);

int main(){
    int unsortedArr[maxSize];
    srand(time(0));
    
    for(int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand() % 100;
    }
    
    displayArr(unsortedArr);

  return 0;
}

  void displayArr(int arr[]){
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
