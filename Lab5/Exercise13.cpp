#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;
        if (!t1) return t2;
        if (!t2) return t1;

        // Merge the values of the two nodes
        t1->val += t2->val;

        // Recur for left and right children
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
};

// Helper function to print the tree in inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Create two example binary trees
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);

    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(7);

    Solution solution;
    TreeNode* mergedTree = solution.mergeTrees(t1, t2);

    cout << "Merged Tree Inorder: ";
    printInorder(mergedTree);
    cout << endl;

    // Free memory (optional)
    delete t1->left->left;
    delete t1->left;
    delete t1->right;
    delete t1;
    delete t2->left->right;
    delete t2->left;
    delete t2->right->right;
    delete t2->right;
    delete t2;

    return 0;
}
