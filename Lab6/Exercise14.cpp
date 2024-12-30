//STT: 22520836
//Full Name: Ngo Thi Hong Ly
//Session 01 - Exercise 14
//Notes or Remarks: Building a recommendation system using collaborative filtering with user-item interaction graph

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class RecommendationSystem {
private:
    int numUsers;
    int numItems;
    vector<unordered_set<int>> userItemGraph;

public:
    RecommendationSystem(int users, int items) {
        numUsers = users;
        numItems = items;
        userItemGraph.resize(users);
    }

    void addInteraction(int user, int item) {
        userItemGraph[user].insert(item);
    }

    vector<int> recommendItems(int user) {
        unordered_map<int, int> itemScores;

        for (int neighborUser = 0; neighborUser < numUsers; neighborUser++) {
            if (neighborUser == user) continue;

            unordered_set<int> commonItems;
            for (int item : userItemGraph[user]) {
                if (userItemGraph[neighborUser].count(item)) {
                    commonItems.insert(item);
                }
            }

            for (int item : userItemGraph[neighborUser]) {
                if (!userItemGraph[user].count(item)) {
                    itemScores[item] += commonItems.size();
                }
            }
        }

        vector<pair<int, int>> scoredItems(itemScores.begin(), itemScores.end());
        sort(scoredItems.begin(), scoredItems.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        vector<int> recommendations;
        for (auto& [item, score] : scoredItems) {
            recommendations.push_back(item);
        }

        return recommendations;
    }

    void displayRecommendations(int user) {
        vector<int> recommendations = recommendItems(user);

        cout << "Recommendations for user " << user << ": ";
        for (int item : recommendations) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    int users = 5;
    int items = 10;
    RecommendationSystem rs(users, items);

    rs.addInteraction(0, 1);
    rs.addInteraction(0, 2);
    rs.addInteraction(1, 2);
    rs.addInteraction(1, 3);
    rs.addInteraction(2, 3);
    rs.addInteraction(2, 4);
    rs.addInteraction(3, 5);
    rs.addInteraction(4, 6);

    for (int user = 0; user < users; user++) {
        rs.displayRecommendations(user);
    }

    return 0;
}
