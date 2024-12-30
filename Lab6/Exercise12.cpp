//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 12
//Notes or Remarks: Modeling a social network and analyzing influential users using centrality measures

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

class SocialNetwork {
private:
    int numUsers;
    vector<vector<int>> adjacencyList;

public:
    SocialNetwork(int users) {
        numUsers = users;
        adjacencyList.resize(users);
    }

    void addFriendship(int user1, int user2) {
        adjacencyList[user1].push_back(user2);
        adjacencyList[user2].push_back(user1);
    }

    vector<int> calculateDegreeCentrality() {
        vector<int> centrality(numUsers, 0);
        for (int i = 0; i < numUsers; i++) {
            centrality[i] = adjacencyList[i].size();
        }
        return centrality;
    }

    void printInfluentialUsers() {
        vector<int> centrality = calculateDegreeCentrality();
        cout << "User Centrality Scores (Degree Centrality):\n";
        for (int i = 0; i < numUsers; i++) {
            cout << "User " << i << ": " << centrality[i] << endl;
        }

        int maxCentrality = *max_element(centrality.begin(), centrality.end());
        cout << "\nMost Influential Users (Highest Degree Centrality):\n";
        for (int i = 0; i < numUsers; i++) {
            if (centrality[i] == maxCentrality) {
                cout << "User " << i << endl;
            }
        }
    }
};

int main() {
    int users = 6;
    SocialNetwork sn(users);

    sn.addFriendship(0, 1);
    sn.addFriendship(0, 2);
    sn.addFriendship(1, 3);
    sn.addFriendship(2, 3);
    sn.addFriendship(3, 4);
    sn.addFriendship(4, 5);

    sn.printInfluentialUsers();

    return 0;
}
