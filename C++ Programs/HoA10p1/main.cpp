#include <iostream>
#include <map>
#include <string>
#include <vector>

class Vertex {
public:
    std::string id;
    std::map<std::string, float> connectedTo;

    Vertex();
    Vertex(const std::string& key);
    void addNeighbor(const std::string& nbr, float weight = 0);
};

class Graph {
public:
    std::map<std::string, Vertex> vertList;
    bool directional;

    Graph(bool directed = true);
    void addVertex(const std::string& key);
    void addEdge(const std::string& from, const std::string& to, float cost = 0);
};

void buildGraph(Graph& g);
void printGraph(const Graph& g);

int main() {
    Graph g(true);      // directed graph 

    buildGraph(g);
    printGraph(g);

    return 0;
}

Vertex::Vertex() {}

Vertex::Vertex(const std::string& key) : id(key) {}

void Vertex::addNeighbor(const std::string& nbr, float weight) {
    connectedTo[nbr] = weight;
}

Graph::Graph(bool directed) : directional(directed) {}

void Graph::addVertex(const std::string& key) {
    vertList[key] = Vertex(key);
}

void Graph::addEdge(const std::string& from, const std::string& to, float cost) {
    if (!vertList.count(from)) addVertex(from);
    if (!vertList.count(to))   addVertex(to);

    vertList[from].addNeighbor(to, cost);
    if (!directional)
        vertList[to].addNeighbor(from, cost);
}

void buildGraph(Graph& g) {
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");

    g.addEdge("A", "B", 3);
    g.addEdge("A", "C", 2);
    g.addEdge("C", "B", 1);
    g.addEdge("D", "A", 4);
}

void printGraph(const Graph& g) {
    for (const auto& v : g.vertList) {
        std::cout << v.first << " -> ";
        for (const auto& n : v.second.connectedTo)
            std::cout << "(" << n.first << ", w=" << n.second << ") ";
        std::cout << std::endl;
    }
}