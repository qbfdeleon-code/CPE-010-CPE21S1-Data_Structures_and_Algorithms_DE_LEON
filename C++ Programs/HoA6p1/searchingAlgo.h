#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind){
    //Step 1: I := 0
    int i = 0;

    //Repeat while I <= n
    while(i < arrSize){
        if(dataFind == data[i]){
            std::cout << "the search is success\n";
            return;
        }

        //increment i to move to the next element
        i++;
    }

    std::cout << "the element is not found\n";
    return;
}


template <typename T>
void linearSearchArr(Node<T>* node, T dataFind){
    while(node != nullptr){
        if(dataFind == node->data){
            std::cout << "the search is success\n";
            return;
        }
        node = node->next;
    }

    std::cout << "the element is not found\n";
    return;
}


template <typename T>
void linearSearchLL(Node<T>* node, T dataFind){
    //repeat the loop until the current node is not null
    while(node != nullptr){

        //if item = current node's data then display searching is successful
        if(dataFind == node->data){
            std::cout << "the search was a success\n";
            return;
        }

        //if not, move to the next node
        node = node->next;
    }

    //the searching reached nullptr -> search is unsuccessful
    std::cout << "the search was unsuccessful\n";
}


/*
getMiddle, must take the first and last node as its parameters.

1. Traverse the singly linked list using two pointers.
2. Move one pointer by one step ahead and the other pointer by two steps.
3. When the fast pointer reaches the end of the singly linked list,
   the slow pointer will reach the middle of the singly linked list.
4. Return slow pointer address.
*/

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){

    //use two pointers:
    //slow moves one node at a time
    //fast moves two nodes at a time
    Node<T>* slow = start;
    Node<T>* fast = start;

    //get middle:
    while(fast != last && fast->next != last){

        //move slow (one step)
        slow = slow->next;

        //move fast (two steps)
        fast = fast->next->next;
    }

    return slow;
}


/*
Binary Search for Linked List

1. Start node is set to head of the list and the last node is set to NULL.
2. Middle element is calculated using the two pointers approach.
3. If the middle element is same as the key to be searched, we return it.
4. Else if middle element is greater than the key to be searched,
   search the LEFT side.
5. Else if middle element is less than the key to be searched,
   search the RIGHT side.
6. If the key is found or the entire linked list gets traversed,
   we stop the loop.
*/

template <typename T>
void binarySearchLL(Node<T>* start, T findData){

    Node<T>* last = nullptr;

    while(last == nullptr || last != start){

        //Find middle element using two pointers
        Node<T>* mid = getMiddle(start, last);

        //If middle element is empty/null, break loop
        if(mid == nullptr){
            break;
        }

        //If middle element is equal to key
        if(mid->data == findData){
            std::cout << "the search was a success\n";
            return;
        }

        //If middle element is greater than key,
        //search the LEFT side
        else if(mid->data > findData){
            last = mid;
        }

        //If middle element is less than key,
        //search the RIGHT side
        else{
            start = mid->next;
        }
    }

    //Search unsuccessful
    std::cout << "the search was unsuccessful\n";
}


// create a binary search using array : getmiddle and / binarySearchArr
template <typename T>
int getMiddle(T data[], int start, int last){

    //find the middle index
    int middle = (start + last) / 2;

    return middle;
}


template <typename T>
void binarySearchArr(T data[], int arrSize, T findData){

    //start of the array
    int start = 0;

    //last position of the array
    int last = arrSize - 1;

    while(start <= last){

        //Find middle element
        int mid = getMiddle(data, start, last);

        //If middle element is equal to key
        if(data[mid] == findData){
            std::cout << "the search was a success\n";
            return;
        }

        //If middle element is greater than key,
        //search the LEFT side
        else if(data[mid] > findData){
            last = mid - 1;
        }

        //If middle element is less than key,
        //search the RIGHT side
        else{
            start = mid + 1;
        }
    }

    //Search unsuccessful
    std::cout << "the search was unsuccessful\n";
}


#endif