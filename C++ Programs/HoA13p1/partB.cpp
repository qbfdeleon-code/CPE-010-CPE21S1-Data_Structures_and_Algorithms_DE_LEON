#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int total = 0; // Global variable
std::mutex mtx;

void add(int value) {
    if (value == 10)
        std::this_thread::sleep_for(std::chrono::seconds(1));
    else if (value == 20)
        std::this_thread::sleep_for(std::chrono::seconds(2));
    else
        std::this_thread::sleep_for(std::chrono::seconds(3));

    std::lock_guard<std::mutex> lock(mtx);
    total += value;
}

int main() {
    std::thread T1(add, 10);
    std::thread T2(add, 20);
    std::thread T3(add, 30);

    std::cout << "Initial value: " << total << std::endl;

    T1.join();
    std::cout << "After T1.join(): " << total << std::endl;

    T2.join();
    std::cout << "After T2.join(): " << total << std::endl;

    T3.join();
    std::cout << "After T3.join(): " << total << std::endl;

    return 0;
}