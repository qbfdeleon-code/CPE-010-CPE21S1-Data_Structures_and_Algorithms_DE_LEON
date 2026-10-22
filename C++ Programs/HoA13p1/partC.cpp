#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

void merge(std::vector<int> &a, int l, int m, int r) {
    std::vector<int> tmp;
    int i = l, j = m + 1;
    while (i <= m && j <= r) tmp.push_back(a[i] <= a[j] ? a[i++] : a[j++]);
    while (i <= m) tmp.push_back(a[i++]);
    while (j <= r) tmp.push_back(a[j++]);
    for (int k = 0; k < (int)tmp.size(); k++) a[l + k] = tmp[k];
}

void mergeSort(std::vector<int> &a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

void parallelMergeSort(std::vector<int> &a, int l, int r) {
    int m = (l + r) / 2;
    std::thread left(mergeSort, std::ref(a), l, m);   //left half in a new thread
    mergeSort(a, m + 1, r);                           //right half in main thread
    left.join();
    merge(a, l, m, r);
}

int main() {
    const int N = 2000000;
    std::vector<int> a(N);
    for (int &x : a) x = std::rand();
    std::vector<int> b = a;

    auto t0 = std::chrono::steady_clock::now();
    mergeSort(a, 0, N - 1);
    auto t1 = std::chrono::steady_clock::now();
    parallelMergeSort(b, 0, N - 1);
    auto t2 = std::chrono::steady_clock::now();

    std::cout << "Single-thread: " << std::chrono::duration<double, std::milli>(t1 - t0).count() << " ms" << std::endl;
    std::cout << "Two-thread:    " << std::chrono::duration<double, std::milli>(t2 - t1).count() << " ms" << std::endl;
    std::cout << "Same result: " << (a == b ? "yes" : "no") << std::endl;
    return 0;
}