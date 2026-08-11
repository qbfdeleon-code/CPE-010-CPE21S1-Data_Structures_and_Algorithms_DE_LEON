// SUPPLEMENTARY ACTIVITY - ILO C

#include <iostream>


// Job class 
class Job {
public:
    int id;
    std::string userName;
    int pages;

    Job() : id(0), userName(""), pages(0) {}
    Job(int id_, const std::string& userName_, int pages_)
        : id(id_), userName(userName_), pages(pages_) {}
};

// queue node
struct JobNode {
    Job data;
    JobNode* next;
    JobNode(const Job& j) : data(j), next(nullptr) {}
};

class JobQueue {
private:
    JobNode* frontPtr;
    JobNode* backPtr;
    int count;

public:
    JobQueue() : frontPtr(nullptr), backPtr(nullptr), count(0) {}

    bool isEmpty() const { return frontPtr == nullptr; }
    int size() const { return count; }

    void enqueue(const Job& j) {
        JobNode* newNode = new JobNode(j);
        if (isEmpty()) {
            frontPtr = backPtr = newNode;
        } else {
            backPtr->next = newNode;
            backPtr = newNode;
        }
        count++;
    }

    bool dequeue(Job& outJob) {
        if (isEmpty()) return false;
        JobNode* temp = frontPtr;
        outJob = temp->data;
        frontPtr = frontPtr->next;
        if (frontPtr == nullptr) backPtr = nullptr; 
        delete temp;
        count--;
        return true;
    }

    ~JobQueue() {
        Job dummy;
        while (dequeue(dummy)) {}
    }
};

// printer class
class Printer {
private:
    JobQueue pendingJobs;
    int nextJobId;

public:
    Printer() : nextJobId(1) {}

    void addJob(const std::string& userName, int pages) {
        Job j(nextJobId++, userName, pages);
        pendingJobs.enqueue(j);
        std::cout << "[SUBMIT] Job #" << j.id << " from " << userName
                   << " (" << pages << " pages) added to queue.\n";
    }

    // process every pending job (first come first served)
    void processAllJobs() {
        std::cout << "\n--- Printer starting to process " << pendingJobs.size()
                   << " job(s) ---\n";
        Job current;
        while (pendingJobs.dequeue(current)) {
            std::cout << "[PRINTING] Job #" << current.id << " for " << current.userName
                       << " -> " << current.pages << " page(s)... Done.\n";
        }
        std::cout << "--- Print queue empty. All jobs completed. ---\n";
    }

    bool hasPendingJobs() const {
        return !pendingJobs.isEmpty();
    }
};

int main() {
    Printer officePrinter;

    std::cout << "=== Multiple users submitting print jobs (FIFO order) ===\n";
    officePrinter.addJob("Aiko", 3);
    officePrinter.addJob("Ben", 12);
    officePrinter.addJob("Carlo", 1);
    officePrinter.addJob("Diane", 7);

    // Printer processes everything currently pending, in submission order
    officePrinter.processAllJobs();

    std::cout << "\n=== A second wave of jobs arrives after the first batch finished ===\n";
    officePrinter.addJob("Elmo", 5);
    officePrinter.addJob("Fiona", 2);
    officePrinter.processAllJobs();

    std::cout << "\nAny jobs still pending? " << std::boolalpha << officePrinter.hasPendingJobs() << "\n";

    return 0;
}