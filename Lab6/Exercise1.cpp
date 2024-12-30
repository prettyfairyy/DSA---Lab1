//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 01
//Notes or Remarks: Implementation of graph using both adjacency list and adjacency matrix

#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyList;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
        adjacencyMatrix.resize(vertices, vector<int>(vertices, 0));
    }

    void addEdgeList(int src, int dest) {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src); // For undirected graph
    }

    void addEdgeMatrix(int src, int dest) {
        adjacencyMatrix[src][dest] = 1;
        adjacencyMatrix[dest][src] = 1; // For undirected graph
    }

    void displayAdjacencyList() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjacencyList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    void displayAdjacencyMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;
    Graph g(vertices);

    // Adding edges for both representations
    g.addEdgeList(0, 1);
    g.addEdgeList(0, 4);
    g.addEdgeList(1, 2);
    g.addEdgeList(1, 3);
    g.addEdgeList(1, 4);
    g.addEdgeList(2, 3);
    g.addEdgeList(3, 4);

    g.addEdgeMatrix(0, 1);
    g.addEdgeMatrix(0, 4);
    g.addEdgeMatrix(1, 2);
    g.addEdgeMatrix(1, 3);
    g.addEdgeMatrix(1, 4);
    g.addEdgeMatrix(2, 3);
    g.addEdgeMatrix(3, 4);

    // Display the representations
    g.displayAdjacencyList();
    g.displayAdjacencyMatrix();

    return 0;
}
