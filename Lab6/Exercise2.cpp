//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 02
//Notes or Remarks: Implementation of Depth-First Search (DFS) using recursive and iterative approaches

#include <iostream>
#include <vector>
#include <stack>
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
        adjacencyList[dest].push_back(src); // For undirected graph
    }

    void DFSRecursive(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjacencyList[vertex]) {
            if (!visited[neighbor]) {
                DFSRecursive(neighbor, visited);
            }
        }
    }

    void DFSRecursiveWrapper(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "DFS (Recursive): ";
        DFSRecursive(startVertex, visited);
        cout << endl;
    }

    void DFSIterative(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> s;
        s.push(startVertex);

        cout << "DFS (Iterative): ";
        while (!s.empty()) {
            int vertex = s.top();
            s.pop();

            if (!visited[vertex]) {
                visited[vertex] = true;
                cout << vertex << " ";

                for (auto it = adjacencyList[vertex].rbegin(); it != adjacencyList[vertex].rend(); ++it) {
                    if (!visited[*it]) {
                        s.push(*it);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int vertices = 5;
    Graph g(vertices);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    int startVertex = 0;
    g.DFSRecursiveWrapper(startVertex);
    g.DFSIterative(startVertex);

    return 0;
}
