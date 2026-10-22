#include <iostream>
#include <iomanip>
#include "sorting.h"

int main() {
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Best and Worst Case: Insertion Sort vs Merge Sort\n";
    std::cout << "Best case = sorted input, Worst case = reverse-sorted input\n\n";
    std::cout << std::left << std::setw(8) << "n"
              << std::setw(12) << "Case"
              << std::setw(24) << "Insertion Sort (us)"
              << std::setw(24) << "Merge Sort (us)" << "\n";
    std::cout << std::string(68, '-') << "\n";

    for (int n : {100, 1000, 10000}) {
        int reps = (n == 10000) ? 20 : (n == 1000 ? 200 : 5000);
        std::vector<int> best = makeBestCase(n);
        std::vector<int> worst = makeWorstCase(n);

        std::cout << std::left << std::setw(8) << n << std::setw(12) << "Best"
                  << std::setw(24) << timeSortUs(insertionSort, best, reps)
                  << std::setw(24) << timeSortUs(mergeSort, best, reps) << "\n";
        std::cout << std::left << std::setw(8) << n << std::setw(12) << "Worst"
                  << std::setw(24) << timeSortUs(insertionSort, worst, reps)
                  << std::setw(24) << timeSortUs(mergeSort, worst, reps) << "\n";
    }

    std::cout << "\nTheoretical time complexity\n";
    std::cout << "Insertion Sort: best O(n), worst O(n^2)\n";
    std::cout << "Merge Sort:     best O(n log n), worst O(n log n)\n";
    return 0;
}