//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 07
//Notes or Remarks: Finding all bridges in an undirected graph using DFS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyList;
    vector<bool> visited;
    vector<int> discoveryTime;
    vector<int> low;
    int timeCounter;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
        visited.resize(vertices, false);
        discoveryTime.resize(vertices, -1);
        low.resize(vertices, -1);
        timeCounter = 0;
    }

    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }

    void findBridgesUtil(int vertex, int parent) {
        visited[vertex] = true;
        discoveryTime[vertex] = low[vertex] = ++timeCounter;

        for (int neighbor : adjacencyList[vertex]) {
            if (!visited[neighbor]) {
                findBridgesUtil(neighbor, vertex);

                // Update the low value for the current vertex
                low[vertex] = min(low[vertex], low[neighbor]);

                // If the condition for a bridge is met
                if (low[neighbor] > discoveryTime[vertex]) {
                    cout << "Bridge found: " << vertex << " - " << neighbor << endl;
                }
            } else if (neighbor != parent) {
                // Update low value for back edges
                low[vertex] = min(low[vertex], discoveryTime[neighbor]);
            }
        }
    }

    void findBridges() {
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                findBridgesUtil(i, -1);
            }
        }
    }
};

int main() {
    int vertices = 5;
    Graph g(vertices);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    cout << "Bridges in the graph:\n";
    g.findBridges();

    return 0;
}
