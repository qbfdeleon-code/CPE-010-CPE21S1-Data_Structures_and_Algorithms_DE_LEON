// PART B.2: Array-Based (Circular) Queue Implementation

#include <iostream>
#include "2queuearr.h"

int main() {
    queueArr<int> myQueue(5);   // a queue that can hold 5 numbers

    std::cout << "Enqueue 10, 20, 30, 40, 50\n";
    myQueue.Enqueue(10);
    myQueue.Enqueue(20);
    myQueue.Enqueue(30);
    myQueue.Enqueue(40);
    myQueue.Enqueue(50);

    std::cout << "\nFront: " << myQueue.Front() << "\n";
    std::cout << "Back : " << myQueue.Back() << "\n";
    std::cout << "Size : " << myQueue.Size() << "\n";
    std::cout << "Full?: " << std::boolalpha << myQueue.Full() << "\n";

    std::cout << "\nDequeue twice\n";
    myQueue.Dequeue();
    myQueue.Dequeue();
    std::cout << "Front now: " << myQueue.Front() << "\nSize: " << myQueue.Size() << "\n";

    std::cout << "\nEnqueue 60, 70\n";
    myQueue.Enqueue(60);
    myQueue.Enqueue(70);
    std::cout << "Back now: " << myQueue.Back() << "\nFull?: " << myQueue.Full() << "\n";

    std::cout << "\nCopy constructor:\n";
    queueArr<int> copy(myQueue);
    std::cout << "\ncopy.Front(): " << copy.Front() << "\ncopy.Back(): " << copy.Back() << "\n";

    std::cout << "\nClear()\n";
    myQueue.Clear();
    std::cout << "Empty? " << myQueue.Empty() << "\n";

    return 0;
}