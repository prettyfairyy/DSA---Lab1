#include <iostream>
#include <queue>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

//Depth First Traversals
void preOrder(Node* root){
    if (!root) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if (!root) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if (!root) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

//Breadth First Traversal
void levelOrder(Node* root){
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    
    while (root){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    cout << "Perform pre-order traversals of a binary tree: ";
    preOrder(root);
    cout << endl;
    cout << "Perform in-order traversals of a binary tree: ";
    inOrder(root);
    cout << endl;
    cout << "Perform post-order traversals of a binary tree: ";
    postOrder(root);
    cout << endl;
    cout << "Perform breadth first traversals of a binary tree: ";
    levelOrder(root);
    cout << endl;
}

