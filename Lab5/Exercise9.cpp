#include <iostream>
#include <climits>
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
    // Variable to store the global maximum path sum
    int globalMax = INT_MIN;

    // Function to find the maximum path sum through the tree
    int findMaxPath(TreeNode* node) {
        if (!node) return 0;

        // Find the maximum path sum in the left and right subtrees
        int leftSum = max(0, findMaxPath(node->left)); // Consider 0 if negative
        int rightSum = max(0, findMaxPath(node->right)); // Consider 0 if negative

        // Calculate the maximum path sum through this node
        int maxSingle = node->val + max(leftSum, rightSum); // Max path sum using single branch
        int maxTop = node->val + leftSum + rightSum; // Max path sum including both branches

        // Update the global maximum
        globalMax = max(globalMax, maxTop);

        return maxSingle;
    }

    // Main function to return the maximum path sum
    int maxPathSum(TreeNode* root) {
        findMaxPath(root);
        return globalMax;
    }
};

int main() {
    // Example Tree
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    cout << "Maximum Path Sum: " << solution.maxPathSum(root) << endl;

    // Freeing allocated memory (optional for this example)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}

