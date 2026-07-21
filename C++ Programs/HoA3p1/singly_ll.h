#ifndef SINGLY_LL_H
#define SINGLY_LL_H


// 1. SIMPLY LINKED LIST IMPLEMENTATION
template <typename T>
class SingleList {
public:
    T data;
    SingleList<T>* next = nullptr;
};

// 2. LINKED LIST TRAVERSAL
template <typename T>
void listTraversal(SingleList<T>* head) {
    while (head != nullptr) {
        std::cout << head->data;
        if (head->next != nullptr) {
            std::cout << "->";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

// 3. NODE INSERTION AT HEAD
template <typename T>
void sllInsertHead(T newData, SingleList<T>** currentHead) {
    SingleList<T>* newNode = new SingleList<T>;
    newNode->data = newData;
    newNode->next = *currentHead;
    *currentHead = newNode;
}

// 4. GENERAL NODE INSERTION (AFTER A NODE)
template <typename T>
void sllGeneralInsertion(T newData, SingleList<T>* prevNode) {
    if (prevNode == nullptr) {
        std::cout << "Previous node cannot be null." << std::endl;
        return;
    }
    SingleList<T>* newNode = new SingleList<T>;
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// 5. INSERT NODE AT THE END
template <typename T>
void sllInsertEnd(T newData, SingleList<T>** head) {
    SingleList<T>* newNode = new SingleList<T>;
    newNode->data = newData;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    SingleList<T>* currentNode = *head;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

// 6. DELETE A NODE (BY VALUE)
template <typename T>
void sllDelete(T findData, SingleList<T>** head) {
    if (*head == nullptr) return;

    SingleList<T>* currNode = *head;
    SingleList<T>* prevNode = nullptr;

    while (currNode != nullptr && currNode->data != findData) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == nullptr) return;

    if (prevNode == nullptr) {
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    delete currNode;
}

// 7. DELETE ENTIRE LIST (CLEANUP)
template <typename T>
void sllDeleteList(SingleList<T>** head) {
    SingleList<T>* currentNode = *head;

    while (currentNode != nullptr) {
        SingleList<T>* temp = currentNode;
        currentNode = currentNode->next;
        delete temp;
    }

    *head = nullptr;
}

#endif