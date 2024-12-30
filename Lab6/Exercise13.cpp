//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 13
//Notes or Remarks: Modeling a city's road network and identifying traffic bottlenecks

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class RoadNetwork {
private:
    int numIntersections;
    vector<vector<pair<int, int>>> adjacencyList; // Pair (neighbor, travel time)

public:
    RoadNetwork(int intersections) {
        numIntersections = intersections;
        adjacencyList.resize(intersections);
    }

    void addRoad(int src, int dest, int travelTime) {
        adjacencyList[src].emplace_back(dest, travelTime);
        adjacencyList[dest].emplace_back(src, travelTime); // For undirected roads
    }

    void findTrafficBottlenecks() {
        vector<int> bottleneckCount(numIntersections, 0);

        // Identify bottlenecks based on edge usage during shortest path computations
        for (int source = 0; source < numIntersections; source++) {
            vector<int> distances(numIntersections, INT_MAX);
            distances[source] = 0;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
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
                    int travelTime = neighbor.second;
                    int newDist = currentDist + travelTime;

                    if (newDist < distances[nextVertex]) {
                        distances[nextVertex] = newDist;
                        pq.emplace(newDist, nextVertex);
                        bottleneckCount[nextVertex]++;
                    }
                }
            }
        }

        // Display bottleneck intersections
        cout << "Traffic Bottleneck Intersections:\n";
        for (int i = 0; i < numIntersections; i++) {
            cout << "Intersection " << i << ": Usage Count = " << bottleneckCount[i] << endl;
        }
    }
};

int main() {
    int intersections = 6;
    RoadNetwork rn(intersections);

    rn.addRoad(0, 1, 5);
    rn.addRoad(0, 2, 2);
    rn.addRoad(1, 2, 1);
    rn.addRoad(1, 3, 3);
    rn.addRoad(2, 4, 4);
    rn.addRoad(3, 5, 6);
    rn.addRoad(4, 5, 2);

    rn.findTrafficBottlenecks();

    return 0;
}
