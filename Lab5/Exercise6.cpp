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

int height(Node* root){
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool heightBalanced(Node* root){
    if (!root) return true;
    if (abs(height(root->left) - height(root->right) > 1)) return false;
    return heightBalanced(root->left) && heightBalanced(root->right);
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
    if (heightBalanced) cout << "The binary tree is height-balanced.";
    else cout << "The binary tree is not height-balanced.";
    return 0;
}