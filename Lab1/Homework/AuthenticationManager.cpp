#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> tokenMap;  

public:
    // Constructor
    AuthenticationManager(int ttl) : timeToLive(ttl) {}

    // Generate a new token with the given tokenId at currentTime
    void generate(string tokenId, int currentTime) {
        tokenMap[tokenId] = currentTime + timeToLive;
        cout << "null" << endl;
    }

    // Renew the token if it is not expired
    void renew(string tokenId, int currentTime) {
        if (tokenMap.find(tokenId) != tokenMap.end() && tokenMap[tokenId] > currentTime) {
            tokenMap[tokenId] = currentTime + timeToLive;
        }
        cout << "null" << endl;
    }

    // Count how many tokens are still valid at the given currentTime
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto it = tokenMap.begin(); it != tokenMap.end();) {
            if (it->second > currentTime) {
                ++count;
                ++it;
            } else {
                it = tokenMap.erase(it); // Remove expired tokens
            }
        }
        return count;
    }
};

int main() {
    int ttl, currentTime;
    string command, tokenId;

    cout << "Enter time to live (TTL) for tokens: ";
    cin >> ttl;

    AuthenticationManager manager(ttl);

    while (true) {
        cout << "\nEnter command (generate, renew, countUnexpiredTokens, exit): ";
        cin >> command;

        if (command == "generate") {
            cin >> tokenId >> currentTime;
            manager.generate(tokenId, currentTime);
        } else if (command == "renew") {
            cin >> tokenId >> currentTime;
            manager.renew(tokenId, currentTime);
        } else if (command == "countUnexpiredTokens") {
            cin >> currentTime;
            int count = manager.countUnexpiredTokens(currentTime);
            cout << count << endl;
        } else if (command == "exit") {
            break;  // Exit the loop when the user enters "exit"
        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}
