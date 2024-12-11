#include <iostream>
#include <queue>
#include <vector>
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
    void verticalOrderTraversal(TreeNode* root) {
        if (!root) return;

        // Predefined size for horizontal distance range
        const int OFFSET = 50;  // Assume HD is in range [-50, 50]
        const int SIZE = 101;   // Total range of HD is 101 (50 left, 50 right)
        TreeNode* levels[SIZE][100];  // Fixed-size storage for nodes
        int nodeCount[SIZE] = {0};    // Count of nodes in each vertical slice

        // Perform level-order traversal
        queue<pair<TreeNode*, int>> q;  // {node, HD}
        q.push({root, OFFSET});  // Start with HD = OFFSET (normalized to be non-negative)

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int hd = front.second;

            // Store the node in its respective vertical level
            levels[hd][nodeCount[hd]++] = node;

            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }

        // Print the vertical order
        for (int i = 0; i < SIZE; i++) {
            if (nodeCount[i] > 0) {  // If there are nodes at this vertical level
                cout << "HD " << (i - OFFSET) << ": ";
                for (int j = 0; j < nodeCount[i]; j++) {
                    cout << levels[i][j]->val << " ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    // Example binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    cout << "Vertical Order Traversal:" << endl;
    solution.verticalOrderTraversal(root);

    // Free allocated memory (optional for this example)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
