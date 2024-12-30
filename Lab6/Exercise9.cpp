//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 09
//Notes or Remarks: Implementation of the PageRank algorithm for ranking web pages

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyList;
    vector<double> pageRank;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
        pageRank.resize(vertices, 1.0 / vertices);
    }

    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
    }

    void calculatePageRank(double dampingFactor = 0.85, int maxIterations = 100, double tolerance = 1e-6) {
        vector<double> newPageRank(numVertices, 0.0);
        int iteration = 0;

        while (iteration < maxIterations) {
            for (int i = 0; i < numVertices; i++) {
                newPageRank[i] = (1.0 - dampingFactor) / numVertices;
                for (int j = 0; j < numVertices; j++) {
                    if (find(adjacencyList[j].begin(), adjacencyList[j].end(), i) != adjacencyList[j].end()) {
                        newPageRank[i] += dampingFactor * (pageRank[j] / adjacencyList[j].size());
                    }
                }
            }

            double diff = 0.0;
            for (int i = 0; i < numVertices; i++) {
                diff += abs(newPageRank[i] - pageRank[i]);
                pageRank[i] = newPageRank[i];
            }

            if (diff < tolerance) {
                break;
            }

            iteration++;
        }

        cout << fixed << setprecision(6);
        cout << "PageRank after " << iteration << " iterations:\n";
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": " << pageRank[i] << endl;
        }
    }
};

int main() {
    int vertices = 4;
    Graph g(vertices);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.calculatePageRank();

    return 0;
}
