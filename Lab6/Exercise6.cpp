//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 06
//Notes or Remarks: Finding all connected components in an undirected graph using BFS

#include <iostream>
#include <vector>
#include <queue>
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
        adjacencyList[dest].push_back(src);
    }

    void BFS(int startVertex, vector<bool>& visited, vector<int>& component) {
        queue<int> q;
        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            component.push_back(vertex);

            for (int neighbor : adjacencyList[vertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void findConnectedComponents() {
        vector<bool> visited(numVertices, false);
        vector<vector<int>> components;

        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                vector<int> component;
                BFS(i, visited, component);
                components.push_back(component);
            }
        }

        // Display the connected components
        cout << "Connected Components:\n";
        for (int i = 0; i < components.size(); i++) {
            cout << "Component " << i + 1 << ": ";
            for (int vertex : components[i]) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 8;
    Graph g(vertices);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.findConnectedComponents();

    return 0;
}
