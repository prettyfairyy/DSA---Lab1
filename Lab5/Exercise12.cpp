#include <iostream>

using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int x) : data(x), left(nullptr), right(nullptr) {}
};

node* createTree(node* root, int x){
    if (!root) 
        return new node(x);
    else{
        if (x < root->data) root->left = createTree(root->left, x);
        else root->right = createTree(root->right, x);
    }
    return root;
}

node* LCA(node* root, int val1, int val2){
    if (!root) return nullptr;
    if (root->data > val1 && root->data > val2)
        return LCA(root->left, val1, val2);
    if (root->data < val1 && root->data < val2)
        return LCA(root->right, val1, val2);
    return root;
}

int main(){
    int num, val1, val2;
    cout << "Enter number of node: ";
    cin >> num;
    int data;
    node* root = nullptr;
    for (int i = 0; i < num; i++){
        cin >> data;
        root = createTree(root, data);
    }
    cout << "Enter 2 value: " ;
    cin >> val1 >> val2;
    if (LCA(root, val1, val2)) cout << "The LCA is " << LCA(root, val1, val2)->data;
    else cout << "There is no LCA.";
    return 0;
}