#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void levelOrder(Node* root){
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        int size = q.size();
        for (int i = 0; i < size; i++){
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    levelOrder(root);
    return 0;
}