#include <iostream>
#include <vector>
#include <list>
#include "supplementaryAlgo.h"

int main() {

    //Problem 1
    std::vector<int> arrList = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    std::list<int> llList = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    std::cout << "Problem 1:\n";

    std::cout << "Array approach: ";
    linearSearchCountArr(arrList, 18);

    std::cout << "\nLinked List approach: ";
    linearSearchCountLL(llList, 18);


    //Problem 2
    std::cout << "\nProblem 2:\n";
    countOccurrences(arrList, 18);


    //Problem 3: 
    std::vector<int> sortedList = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    std::cout << "\nProblem 3:\n";
    binarySearchVerbose(sortedList, 8);


    //Problem 4: 
    std::cout << "\nProblem 4:\n";
    binarySearchRecursive(sortedList, 0, (int)sortedList.size() - 1, 8);


    return 0;
}