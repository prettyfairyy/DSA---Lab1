//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 16
//Notes or Remarks: Implementation of pathfinding using A* algorithm in a grid graph

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    int x, y;
    double cost, heuristic;
    Node* parent;

    Node(int x, int y, double cost = 0, double heuristic = 0, Node* parent = nullptr)
        : x(x), y(y), cost(cost), heuristic(heuristic), parent(parent) {}

    double totalCost() const { return cost + heuristic; }

    bool operator>(const Node& other) const { return totalCost() > other.totalCost(); }
};

class GridGraph {
private:
    int rows, cols;
    vector<vector<int>> grid;
    vector<pair<int, int>> directions;

public:
    GridGraph(int r, int c, const vector<vector<int>>& gridData)
        : rows(r), cols(c), grid(gridData) {
        directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right
    }

    bool isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0;
    }

    double heuristic(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2); // Manhattan distance
    }

    void AStar(int startX, int startY, int goalX, int goalY) {
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        pq.emplace(startX, startY, 0, heuristic(startX, startY, goalX, goalY));

        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();

            if (visited[current.x][current.y]) continue;
            visited[current.x][current.y] = true;

            if (current.x == goalX && current.y == goalY) {
                vector<pair<int, int>> path;
                Node* pathNode = &current;
                while (pathNode) {
                    path.emplace_back(pathNode->x, pathNode->y);
                    pathNode = pathNode->parent;
                }
                reverse(path.begin(), path.end());
                cout << "Path found:\n";
                for (auto& p : path) {
                    cout << "(" << p.first << ", " << p.second << ") ";
                }
                cout << endl;
                return;
            }

            for (auto& dir : directions) {
                int nx = current.x + dir.first;
                int ny = current.y + dir.second;
                if (isValid(nx, ny) && !visited[nx][ny]) {
                    pq.emplace(nx, ny, current.cost + 1,
                               heuristic(nx, ny, goalX, goalY),
                               new Node(current));
                }
            }
        }

        cout << "No path found." << endl;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}};

    GridGraph graph(5, 5, grid);
    graph.AStar(0, 0, 4, 4);

    return 0;
}
