#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50;

int main() {

    //generate random values:
    int dataset[max_size];

    srand(time(0));

    for(int i = 0; i < max_size; i++){
        dataset[i] = rand();
    }

    for(int i = 0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }

    std::cout << std::endl;


    //create a user input to ask what value to find:
    int toFind;

    std::cout << "what value you want to search? ";
    std::cin >> toFind;

    linearSearchArr(dataset, max_size, toFind);


    //linear search:
    std::cout << "what value you want to search? ";
    std::cin >> toFind;

    linearSearchArr(dataset, max_size, toFind);



    Node<char>* name1 = new_node('D');
    Node<char>* name2 = new_node('I');
    Node<char>* name3 = new_node('J');
    Node<char>* name4 = new_node('L');
    Node<char>* name5 = new_node('M');
    Node<char>* name6 = new_node('O');
    Node<char>* name7 = new_node('R');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;

    
    std::cout << "Linear Search for Array 'D': ";
    linearSearchArr(name1, 'D');

    std::cout << "Linear Search for Linked List result: 'O' ";
    linearSearchLL(name1, 'O');


    //Binary Search for Linked List

    std::cout << "\nLinked List Binary Search for 'R': ";
    binarySearchLL(name1, 'R');

    std::cout << "Linked List Binary Search for 'Z': ";
    binarySearchLL(name1, 'Z');


    //Binary Search for Array
    int numbers[7] = {10, 20, 30, 40, 50, 60, 70};

    std::cout << "\nBinary Search for Array result: ";
    binarySearchArr(numbers, 7, 50);

    std::cout << "Binary Search for Array result: ";
    binarySearchArr(numbers, 7, 90);


    return 0;
}