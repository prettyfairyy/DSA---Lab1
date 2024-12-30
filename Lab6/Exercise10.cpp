//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 10
//Notes or Remarks: Implementation of Dijkstra's algorithm using a priority queue

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

    void dijkstra(int source) {
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

        // Display the shortest distances
        cout << "Shortest distances from vertex " << source << ":\n";
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
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

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 4, 6);
    g.addEdge(4, 5, 9);

    int sourceVertex = 0;
    g.dijkstra(sourceVertex);

    return 0;
}
