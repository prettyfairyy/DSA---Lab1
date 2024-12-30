//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 15
//Notes or Remarks: Modeling a computer network and optimizing topology for efficiency and reliability

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Network {
private:
    int numDevices;
    vector<vector<pair<int, int>>> adjacencyList; // Pair (neighbor, latency)

public:
    Network(int devices) {
        numDevices = devices;
        adjacencyList.resize(devices);
    }

    void addConnection(int src, int dest, int latency) {
        adjacencyList[src].emplace_back(dest, latency);
        adjacencyList[dest].emplace_back(src, latency); // Bidirectional connection
    }

    void optimizeTopology() {
        vector<bool> inMST(numDevices, false);
        vector<int> key(numDevices, INT_MAX);
        vector<int> parent(numDevices, -1);
        key[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0); // (key, vertex)

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;

            inMST[u] = true;

            for (const auto& [v, weight] : adjacencyList[u]) {
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.emplace(key[v], v);
                }
            }
        }

        // Display the optimized network topology
        cout << "Optimized Network Topology (Minimum Spanning Tree):\n";
        for (int i = 1; i < numDevices; i++) {
            if (parent[i] != -1) {
                cout << "Device " << parent[i] << " - Device " << i << " (Latency: " << key[i] << ")\n";
            }
        }
    }
};

int main() {
    int devices = 6;
    Network network(devices);

    network.addConnection(0, 1, 4);
    network.addConnection(0, 2, 3);
    network.addConnection(1, 2, 1);
    network.addConnection(1, 3, 2);
    network.addConnection(2, 3, 4);
    network.addConnection(3, 4, 2);
    network.addConnection(4, 5, 6);

    network.optimizeTopology();

    return 0;
}