#include <iostream>
#include <algorithm>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x): data(x), left(nullptr), right(nullptr) {}
};

int diameter(Node* root, int &maxDiameter){
    if (!root) return 0;

    int leftHeight = diameter(root->left, maxDiameter);
    int rightHeight = diameter(root->right, maxDiameter);
    maxDiameter = max(maxDiameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int findDiameter(Node* root){
    int maxDiameter = 0;
    diameter(root, maxDiameter);
    return maxDiameter;
}

int main(){
    // Example tree:
    //           5
    //        /     \
    //       3       9
    //      / \     / \
    //     4   2   10  7
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(9);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    root->right->left = new Node(10);
    root->right->right = new Node(7);
    cout << "Diameter of the binary tree: " << findDiameter(root) << endl;
    return 0;
}