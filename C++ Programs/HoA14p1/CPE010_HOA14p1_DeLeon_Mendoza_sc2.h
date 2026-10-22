#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <chrono>
#include <algorithm>

//Algorithm 1: Insertion Sort
inline void insertionSort(std::vector<int> &a, int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        int key = a[i], j = i - 1;
        while (j >= l && a[j] > key) { a[j + 1] = a[j]; j--; }
        a[j + 1] = key;
    }
}

//Algorithm 2: Merge Sort
inline void merge(std::vector<int> &a, int l, int m, int r) {
    std::vector<int> tmp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) tmp.push_back(a[i] <= a[j] ? a[i++] : a[j++]);
    while (i <= m) tmp.push_back(a[i++]);
    while (j <= r) tmp.push_back(a[j++]);
    for (int k = 0; k < (int)tmp.size(); k++) a[l + k] = tmp[k];
}

inline void mergeSort(std::vector<int> &a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}


inline std::vector<int> makeBestCase(int n) {      // already sorted
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = i;
    return v;
}

inline std::vector<int> makeWorstCase(int n) {     // reverse sorted
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = n - i;
    return v;
}

//Average time (microseconds) 
inline double timeSortUs(void (*sortFn)(std::vector<int> &, int, int),
                         const std::vector<int> &data, int reps) {
    double total = 0;
    for (int r = 0; r < reps; r++) {
        std::vector<int> c = data;
        auto t0 = std::chrono::steady_clock::now();
        sortFn(c, 0, (int)c.size() - 1);
        auto t1 = std::chrono::steady_clock::now();
        total += std::chrono::duration<double, std::micro>(t1 - t0).count();
    }
    return total / reps;
}

#endif 