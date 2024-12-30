//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 04
//Notes or Remarks: Detect cycles in directed and undirected graphs using DFS

#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
    }

    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
    }

    bool detectCycleDirectedUtil(int vertex, vector<bool>& visited, vector<bool>& recStack) {
        visited[vertex] = true;
        recStack[vertex] = true;

        for (int neighbor : adjacencyList[vertex]) {
            if (!visited[neighbor] && detectCycleDirectedUtil(neighbor, visited, recStack)) {
                return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }

        recStack[vertex] = false;
        return false;
    }

    bool detectCycleDirected() {
        vector<bool> visited(numVertices, false);
        vector<bool> recStack(numVertices, false);

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i] && detectCycleDirectedUtil(i, visited, recStack)) {
                return true;
            }
        }
        return false;
    }

    bool detectCycleUndirectedUtil(int vertex, vector<bool>& visited, int parent) {
        visited[vertex] = true;

        for (int neighbor : adjacencyList[vertex]) {
            if (!visited[neighbor]) {
                if (detectCycleUndirectedUtil(neighbor, visited, vertex)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    bool detectCycleUndirected() {
        vector<bool> visited(numVertices, false);

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i] && detectCycleUndirectedUtil(i, visited, -1)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Graph directedGraph(4);
    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(2, 0);
    directedGraph.addEdge(2, 3);

    cout << "Cycle in directed graph: " << (directedGraph.detectCycleDirected() ? "Yes" : "No") << endl;

    Graph undirectedGraph(4);
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(2, 3);
    undirectedGraph.addEdge(3, 0);

    cout << "Cycle in undirected graph: " << (undirectedGraph.detectCycleUndirected() ? "Yes" : "No") << endl;

    return 0;
}
