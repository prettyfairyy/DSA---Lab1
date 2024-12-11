#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <string>
#include <iomanip>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class binaryTree {
public:
    Node* createBinaryTree(int depth);
    void printTree(Node* root, int depth);
    Node* insertNode(Node* root, int data);
    void delRightMostNode(Node* root);
    Node* delNode(Node* root, int deldata);
};

// Recursive function to calculate the depth of the binary tree
int calculateDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(calculateDepth(root->left), calculateDepth(root->right));
}

// Recursive function to create a binary tree ensuring all non-leaf nodes have at least one child
Node* binaryTree::createBinaryTree(int depth) {
    if (depth < 1) return nullptr;

    Node* node = new Node(rand() % 100 + 1);
    if (depth > 1) {
        if (rand() % 2 == 0) {
            node->left = createBinaryTree(depth - 1);
            if (!node->left) node->right = createBinaryTree(depth - 1);
        }
        else {
            node->right = createBinaryTree(depth - 1);
            if (!node->right) node->left = createBinaryTree(depth - 1);
        }
        if (!node->left && !node->right)
            node->left = createBinaryTree(depth - 1);
    }
    return node;
}

void binaryTree::printTree(Node* root, int depth) {
    if (!root) {
        cout << "Tree is empty" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    int currentLevel = 0;
    int maxNode = pow(2, depth) - 1;
    int space = 4 * (maxNode / 2);

    while (currentLevel < depth) {
        int levelNode = pow(2, currentLevel);
        vector<string> level;

        for (int i = 0; i < levelNode; i++) {
            if (!q.empty()) {
                Node* node = q.front();
                q.pop();
                if (node) {
                    level.push_back(to_string(node->data));
                    q.push(node->left);
                    q.push(node->right);
                }
                else {
                    level.push_back(" ");
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }
            else {
                level.push_back(" ");
            }
        }

        cout << string(space, ' '); // Center align
        for (const auto& val : level) {
            cout << setw(4) << val << string(space * 2 - 4, ' ');
        }
        cout << endl;

        currentLevel++;
        space /= 2; // Reduce space for the next level
    }
}

Node* binaryTree::insertNode(Node* root, int data) {
    if (root == nullptr) {
        root = new  Node(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp->left != nullptr)
            q.push(temp->left);
        else {
            temp->left = new Node(data);
            return root;
        }
        if (temp->right != nullptr)
            q.push(temp->right);
        else {
            temp->right = new Node(data);
            return root;
        }
    }
}

void binaryTree::delRightMostNode(Node* root) {
    queue<Node*> q;
    q.push(root);

    Node* temp;
    Node* parent;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->right) {
            parent = temp;
            if (!temp->right->left && !temp->right->right) {
                delete temp->right;
                parent->right = nullptr;
                return;
            }
            else q.push(temp->right);
        }

        if (temp->left) {
            parent = temp;
            if (!temp->left->left && !temp->left->right) {
                delete temp->left;
                parent->left = nullptr;
                return;
            }
            else q.push(temp->left);
        }
    }
}

Node* binaryTree::delNode(Node* root, int deldata) {
    if (!root) return nullptr;

    queue<Node*> q;
    q.push(root);

    Node* target = nullptr;
    Node* temp;

    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->data == deldata) {
            target = temp;
        }

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

    if (!target) {
        cout << deldata << " is not found in the tree." << endl;
        return root;
    }

    int rightmostData = temp->data;
    delRightMostNode(root);
    target->data = rightmostData;

    return root;
}

int main() {
    srand(time(0));
    binaryTree tree;

    int depth;
    cout << "Enter the depth of the binary tree: ";
    cin >> depth;

    Node* root = tree.createBinaryTree(depth);
    cout << "\nInitial Binary Tree:" << endl;
    tree.printTree(root, calculateDepth(root));

    int numNewNodes;
    cout << "Enter the number of nodes to insert: ";
    cin >> numNewNodes;
    for (int i = 0; i < numNewNodes; i++) {
        int data;
        cout << "Enter value for new node " << i + 1 << ": ";
        cin >> data;
        tree.insertNode(root, data);
    }
    cout << "\nBinary Tree after inserting nodes:" << endl;
    tree.printTree(root, calculateDepth(root));

    int numDelNodes;
    cout << "Enter the number of nodes to delete: ";
    cin >> numDelNodes;
    for (int i = 0; i < numDelNodes; i++) {
        int deldata;
        cout << "Enter value for delete node " << i + 1 << ": ";
        cin >> deldata;
        root = tree.delNode(root, deldata);
    }
    cout << "\nBinary Tree after deleting nodes:" << endl;
    tree.printTree(root, calculateDepth(root));

    return 0;
}
