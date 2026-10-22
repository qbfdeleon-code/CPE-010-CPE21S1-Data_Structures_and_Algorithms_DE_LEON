#include <iostream>
#include <vector>
#include <chrono>

//Problem 1: Unique(A) 
long long comparisons = 0;

bool unique_elements(std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1 + 1; i++) {       
        for (int j = i + 1; j < n; j++) {       
            comparisons++;
            if (A[i] == A[j])
                return false;
        }
    }
    return true;
}

//Problem 2: power functions
long long calls = 0;

unsigned long long rpower(unsigned long long x, int n) {
    calls++;
    if (n == 0) return 1;
    else return x * rpower(x, n - 1);
}

unsigned long long brpower(unsigned long long x, int n) {
    calls++;
    if (n == 0) return 1;
    unsigned long long y;
    if (n % 2 == 1) {
        y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        y = brpower(x, n / 2);
        return y * y;
    }
}

int main() {
    using clk = std::chrono::steady_clock;
    using us = std::chrono::microseconds;

    std::cout << "PROBLEM 1: Unique(A) - worst case (all elements unique)\n";
    std::cout << "n\tcomparisons\tn(n-1)/2\ttime(us)\n";
    for (int n : {1000, 2000, 4000, 8000, 16000}) {
        std::vector<int> A(n);
        for (int i = 0; i < n; i++) A[i] = i;
        comparisons = 0;
        auto b = clk::now();
        bool r = unique_elements(A);
        auto e = clk::now();
        std::cout << n << "\t" << comparisons << "\t\t" << (long long)n * (n - 1) / 2
                  << "\t\t" << std::chrono::duration_cast<us>(e - b).count()
                  << (r ? "" : " (not unique)") << "\n";
    }

    std::cout << "\nPROBLEM 2: rpower vs brpower (x = 1 to avoid overflow)\n";
    std::cout << "n\trpower calls\trpower(us)\tbrpower calls\tbrpower(us)\n";
    for (int n : {1000, 2000, 4000, 8000, 16000}) {
        calls = 0;
        auto b1 = clk::now();
        rpower(1, n);
        auto e1 = clk::now();
        long long c1 = calls;

        calls = 0;
        auto b2 = clk::now();
        brpower(1, n);
        auto e2 = clk::now();
        long long c2 = calls;

        std::cout << n << "\t" << c1 << "\t\t"
                  << std::chrono::duration_cast<us>(e1 - b1).count() << "\t\t"
                  << c2 << "\t\t"
                  << std::chrono::duration_cast<us>(e2 - b2).count() << "\n";
    }
    return 0;
}
