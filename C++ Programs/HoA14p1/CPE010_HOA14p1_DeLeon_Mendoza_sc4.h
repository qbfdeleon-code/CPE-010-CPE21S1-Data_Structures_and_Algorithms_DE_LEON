#ifndef SEARCHING_H
#define SEARCHING_H

#include <vector>
#include <chrono>
#include <algorithm>

// Linear Search (Worst Case: element not found or at the last index)
inline int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

// Binary Search (Iterative - requires sorted input)
inline int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = static_cast<int>(arr.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Helper: Generates a sorted vector containing elements 0 to n-1
inline std::vector<int> generateSortedArray(int n) {
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
    return v;
}

// Timing Function: Measures average execution time in microseconds
inline double timeSearchUs(int (*searchFn)(const std::vector<int>&, int),
                          const std::vector<int>& data, int target, int reps) {
    double total = 0;
    for (int r = 0; r < reps; ++r) {
        auto t0 = std::chrono::steady_clock::now();
        volatile int result = searchFn(data, target); // volatile prevents compiler optimization
        (void)result;
        auto t1 = std::chrono::steady_clock::now();
        total += std::chrono::duration<double, std::micro>(t1 - t0).count();
    }
    return total / reps;
}

#endif 