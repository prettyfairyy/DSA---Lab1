//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 08
//Notes or Remarks: Implementation of the Louvain method for community detection

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyList;
    unordered_map<int, int> community; // Maps vertex to its community

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
    }

    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }

    void initializeCommunities() {
        for (int i = 0; i < numVertices; i++) {
            community[i] = i;
        }
    }

    double modularity() {
        double m = 0;
        for (int i = 0; i < numVertices; i++) {
            m += adjacencyList[i].size();
        }
        m /= 2.0;

        double q = 0.0;
        for (int i = 0; i < numVertices; i++) {
            for (int j : adjacencyList[i]) {
                if (community[i] == community[j]) {
                    q += 1.0 - (double)(adjacencyList[i].size() * adjacencyList[j].size()) / (2 * m);
                }
            }
        }
        return q / (2 * m);
    }

    void optimizeCommunities() {
        bool updated;
        do {
            updated = false;
            for (int vertex = 0; vertex < numVertices; vertex++) {
                unordered_map<int, int> communityEdges;

                for (int neighbor : adjacencyList[vertex]) {
                    communityEdges[community[neighbor]]++;
                }

                int maxCommunity = community[vertex];
                int maxEdges = 0;

                for (auto& [comm, edges] : communityEdges) {
                    if (edges > maxEdges) {
                        maxEdges = edges;
                        maxCommunity = comm;
                    }
                }

                if (maxCommunity != community[vertex]) {
                    community[vertex] = maxCommunity;
                    updated = true;
                }
            }
        } while (updated);
    }

    void detectCommunities() {
        initializeCommunities();

        cout << "Initial modularity: " << modularity() << endl;

        optimizeCommunities();

        cout << "Final modularity: " << modularity() << endl;
        unordered_map<int, vector<int>> communities;
        for (int i = 0; i < numVertices; i++) {
            communities[community[i]].push_back(i);
        }

        cout << "Communities:\n";
        for (auto& [comm, members] : communities) {
            cout << "Community " << comm << ": ";
            for (int member : members) {
                cout << member << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 6;
    Graph g(vertices);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.detectCommunities();

    return 0;
}
