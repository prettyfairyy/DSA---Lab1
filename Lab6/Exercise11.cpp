//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 11
//Notes or Remarks: Implementation of a route planning algorithm using Dijkstra's algorithm

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<pair<int, int>>> adjacencyList; // Pair (neighbor, weight)

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
    }

    void addEdge(int src, int dest, int weight) {
        adjacencyList[src].emplace_back(dest, weight);
        adjacencyList[dest].emplace_back(src, weight); // For undirected graph
    }

    vector<int> dijkstra(int source) {
        vector<int> distances(numVertices, INT_MAX);
        distances[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Min-heap (distance, vertex)
        pq.emplace(0, source);

        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int currentVertex = pq.top().second;
            pq.pop();

            if (currentDist > distances[currentVertex]) {
                continue;
            }

            for (const auto& neighbor : adjacencyList[currentVertex]) {
                int nextVertex = neighbor.first;
                int weight = neighbor.second;
                int newDist = currentDist + weight;

                if (newDist < distances[nextVertex]) {
                    distances[nextVertex] = newDist;
                    pq.emplace(newDist, nextVertex);
                }
            }
        }

        return distances;
    }

    void printShortestPaths(int source) {
        vector<int> distances = dijkstra(source);

        cout << "Shortest distances from source " << source << ":\n";
        for (int i = 0; i < numVertices; i++) {
            cout << "To vertex " << i << ": ";
            if (distances[i] == INT_MAX) {
                cout << "Infinity";
            } else {
                cout << distances[i];
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 6;
    Graph g(vertices);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 5);

    int sourceVertex = 0;
    g.printShortestPaths(sourceVertex);

    return 0;
}
