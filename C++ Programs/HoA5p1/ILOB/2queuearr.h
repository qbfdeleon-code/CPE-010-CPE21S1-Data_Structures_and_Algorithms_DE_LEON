#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <cstddef>    // gives us size_t
#include <stdexcept>  // gives us std::runtime_error

template <typename T>
class queueArr {
private:
    T* data;            // the array that holds the items
    size_t capacity;     // how many items the array can hold
    size_t frontIndex;   // index of the front item
    size_t backIndex;    // index of the back item
    size_t count;        // how many items are currently stored

public:
    bool Empty();
    bool Full();
    size_t Size();
    void Clear();

    T Front();
    T Back();

    void Enqueue(T newData);
    void Dequeue();

    queueArr(size_t cap);                 
    ~queueArr();                          

    queueArr(const queueArr& other);              // copy constructor
    queueArr& operator=(const queueArr& other);    // copy assignment
};

// Build a new, empty queue that can hold "cap" items.
template <typename T>
queueArr<T>::queueArr(size_t cap) {
    capacity = cap;
    count = 0;
    frontIndex = 0;
    backIndex = 0;
    data = new T[capacity];
}

// Free the array when the queue is destroyed.
template <typename T>
queueArr<T>::~queueArr() {
    delete[] data;
}

// Make a brand-new queue that is a copy of "other".
template <typename T>
queueArr<T>::queueArr(const queueArr& other) {
    capacity = other.capacity;
    frontIndex = other.frontIndex;
    backIndex = other.backIndex;
    count = other.count;

    data = new T[capacity];
    for (size_t i = 0; i < capacity; i++) {
        data[i] = other.data[i];
    }
}

// Copy the contents of "other" into a queue that already exists.
template <typename T>
queueArr<T>& queueArr<T>::operator=(const queueArr& other) {
    if (this == &other) {
        return *this;   
    }

    delete[] data;   // free our old array first

    capacity = other.capacity;
    frontIndex = other.frontIndex;
    backIndex = other.backIndex;
    count = other.count;

    data = new T[capacity];
    for (size_t i = 0; i < capacity; i++) {
        data[i] = other.data[i];
    }

    return *this;
}

// Is the queue empty?
template <typename T>
bool queueArr<T>::Empty() {
    return count == 0;
}

// Is the queue full?
template <typename T>
bool queueArr<T>::Full() {
    return count == capacity;
}

// How many items are stored rn?
template <typename T>
size_t queueArr<T>::Size() {
    return count;
}

// Reset the queue back to empty.
template <typename T>
void queueArr<T>::Clear() {
    frontIndex = 0;
    backIndex = 0;
    count = 0;
}

// front of the queue.
template <typename T>
T queueArr<T>::Front() {
    if (Empty()) {
        throw std::runtime_error("Front() called on empty queue");
    }
    return data[frontIndex];
}

// back of the queue.
template <typename T>
T queueArr<T>::Back() {
    if (Empty()) {
        throw std::runtime_error("Back() called on empty queue");
    }
    return data[backIndex];
}

// Add new item to the back of the queue.
template <typename T>
void queueArr<T>::Enqueue(T newItem) {
    if (Full()) {
        throw std::runtime_error("Enqueue() called on full queue");
    }

    if (count == 0) {
        backIndex = 0;   // this is the very first item
    } else {
        // move one step forward, wrapping back to 0 after the last slot
        backIndex = (backIndex + 1) % capacity;
    }

    data[backIndex] = newItem;
    count++;
}

// Remove item at the front of the queue.
template <typename T>
void queueArr<T>::Dequeue() {
    if (Empty()) {
        throw std::runtime_error("Dequeue() called on empty queue");
    }
    frontIndex = (frontIndex + 1) % capacity;   // wrap around if needed
    count--;
}

#endif