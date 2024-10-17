//STT: 22520836
//Full Name: Ngo Thi Hong Ly

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
    Node* prev;
    Node(string u) : url(u), next(nullptr), prev(nullptr) {}
};

class BrowserHistory {
private:
    Node* current;

public:
    // Constructor that sets the homepage
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    // Visit a new URL, clear forward history
    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    // Go back a certain number of steps
    string back(int steps) {
        while (steps-- && current->prev) {
            current = current->prev;
        }
        return current->url;
    }

    // Go forward a certain number of steps
    string forward(int steps) {
        while (steps-- && current->next) {
            current = current->next;
        }
        return current->url;
    }
};

int main() {
    string homepage, command, url;
    int steps;

    // Initialize the browser with a homepage from keyboard input
    cout << "Enter homepage URL: ";
    cin >> homepage;
    BrowserHistory browser(homepage);

    while (true) {
        cout << "\nEnter command (visit, back, forward, exit): ";
        cin >> command;

        if (command == "visit") {
            cout << "Enter URL to visit: ";
            cin >> url;
            browser.visit(url);

        } else if (command == "back") {
            cout << "Enter steps to go back: ";
            cin >> steps;
            cout << "Back to: " << browser.back(steps) << endl;

        } else if (command == "forward") {
            cout << "Enter steps to go forward: ";
            cin >> steps;
            cout << "Forward to: " << browser.forward(steps) << endl;

        } else if (command == "exit") {
            break;

        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}
