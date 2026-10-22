#ifndef Ap1_H
#define Ap1_H

#include <iostream>
 
// ILO A
// stores adjacency list items
struct adjNode {
int val, cost;
adjNode* next;
};

// structure to store edges
struct graphEdge {
int start_ver, end_ver, weight;
};

class DiaGraph {
// insert new nodes into adjacency list from given graph
adjNode* getAdjListNode(int value, int weight, adjNode* head) {
adjNode* newNode = new adjNode;
newNode->val = value;
newNode->cost = weight;

newNode->next = head;   // point new node to current head
return newNode;
}

int N; // number of nodes in the graph

public:
adjNode **head; //adjacency list as array of pointers

// Constructor
DiaGraph(graphEdge edges[], int n, int N) {
// allocate new node
head = new adjNode*[N]();
this->N = N;

// initialize head pointer for all vertices
for (int i = 0; i < N; ++i)
head[i] = nullptr;

// construct directed graph by adding edges to it
for (int i = 0; i < n; i++) {
int start_ver = edges[i].start_ver;
int end_ver = edges[i].end_ver;
int weight = edges[i].weight;

// insert in the beginning
adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);

// point head pointer to new node
head[start_ver] = newNode;
}
}

// Destructor
~DiaGraph() {
for (int i = 0; i < N; i++) {
           
// FIX: head[i] is a linked list of single nodes, 
// so delete them one by one.
adjNode* ptr = head[i];
while (ptr != nullptr) {
adjNode* temp = ptr;
ptr = ptr->next;
delete temp;
}
}
delete[] head;
}
};

// print all adjacent vertices of given vertex
inline void display_AdjList(adjNode* ptr, int i)
{
while (ptr != nullptr) {
std::cout << "(" << i << ", " << ptr->val
<< ", " << ptr->cost << ") ";
ptr = ptr->next;
}
std::cout << std::endl;
}

#endif // Ap1_H