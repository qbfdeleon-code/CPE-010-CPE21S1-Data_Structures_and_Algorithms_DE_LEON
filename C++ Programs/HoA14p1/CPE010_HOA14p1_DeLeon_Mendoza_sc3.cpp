#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "suppSorting.h"

int main() {
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Empirical Complexity Benchmark: Linear Search vs Binary Search\n";
    std::cout << "Worst-Case Analysis (Target element absent from array)\n\n";

    std::cout << std::left << std::setw(12) << "N"
              << std::setw(30) << "Binary Search (us)"
              << std::setw(30) << "Linear Search (us)" << "\n";
    std::cout << std::string(72, '-') << "\n";

    for (int n : {1000, 10000, 100000}) {
        // High repetition count for accuracy with small elapsed times
        int reps = (n == 100000) ? 500 : ((n == 10000) ? 2000 : 10000);

        std::vector<int> data = generateSortedArray(n);
        int target = -1; // Target not present ensures strict worst-case runtime

        double binaryTime = timeSearchUs(binarySearch, data, target, reps);
        double linearTime = timeSearchUs(linearSearch, data, target, reps);

        std::cout << std::left << std::setw(12) << n
                  << std::setw(30) << binaryTime
                  << std::setw(30) << linearTime << "\n";
    }

    std::cout << "\nTheoretical Time Complexity:\n";
    std::cout << "Binary Search: Worst-case O(log N), Best-case O(1), Space O(1)\n";
    std::cout << "Linear Search: Worst-case O(N),     Best-case O(1), Space O(1)\n";

    return 0;
}