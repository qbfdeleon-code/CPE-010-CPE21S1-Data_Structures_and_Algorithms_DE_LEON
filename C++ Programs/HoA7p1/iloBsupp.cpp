#include <iostream>
#include <cstdlib>
#include <ctime>
#include "iloBsupp.h"

void generateVotes(int A[], int n);

void printArray(int A[], int n);

void countVotes(int A[], int n, int counts[6]);

int findWinner(int counts[6]);

std::string candidates[6] = {
    "",
    "Bo Dalton Capistrano",       
    "Cornelius Raymon Agustin",   
    "Deja Jayla Banaga",          
    "Lalla Brielle Yabut",       
    "Franklin Relano Castro"     
};


int main() {

    const int size = 100;

    int A[size];
    int counts[6];

    
    generateVotes(A, size);
    std::cout << "Unsorted array: " << std::endl;
    printArray(A, size);

    insertionSort(A, size);
    std::cout << "\nSorted array: " << std::endl;
    printArray(A, size);
    
    countVotes(A, size, counts);

    std::cout << "\nCandidates:" << std::endl;
    for (int i = 1; i <= 5; i++) {
        std::cout << "Candidate " << i << ": " << candidates[i] << std::endl;
    }

    std::cout << "\nVote Result" << std::endl;
    int totalVotes = 0;
    for (int i = 1; i <= 5; i++) {
        std::cout << "Candidate " << i << " (" << candidates[i] << "): "
                  << counts[i] << " votes" << std::endl;
        totalVotes += counts[i];
    }
   
    int winner = findWinner(counts);
    std::cout << "\nWinning Candidate" << std::endl;
    std::cout << "Candidate " << winner << " - " << candidates[winner]
              << " wins with " << counts[winner] << " votes!" << std::endl;

    return 0;
}


void generateVotes(int A[], int n) {
    std::srand((unsigned int)std::time(0));
    for (int i = 0; i < n; i++) {
        A[i] = (std::rand() % 5) + 1;
    }
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
        if ((i + 1) % 20 == 0) std::cout << std::endl;
    }
    std::cout << std::endl;
}


void countVotes(int A[], int n, int counts[6]) {
    for (int i = 1; i <= 5; i++) counts[i] = 0;
    for (int i = 0; i < n; i++) {
        counts[A[i]]++;
    }
}

int findWinner(int counts[6]) {
    int winner = 1;
    for (int i = 2; i <= 5; i++) {
        if (counts[i] > counts[winner]) winner = i;
    }
    return winner;
}