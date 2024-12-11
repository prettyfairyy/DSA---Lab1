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
    TreeNode* buildTree(int inorder[], int postorder[], int n) {
        int postIndex = n - 1;  // Start from the end of postorder array
        return helper(inorder, postorder, 0, n - 1, postIndex);
    }

private:
    TreeNode* helper(int inorder[], int postorder[], int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd) return nullptr;

        // Create the root node from postorder array
        TreeNode* root = new TreeNode(postorder[postIndex--]);

        // Find the index of the root in the inorder array
        int inIndex = find(inorder, inStart, inEnd, root->val);

        // Recur for right subtree, then left subtree
        root->right = helper(inorder, postorder, inIndex + 1, inEnd, postIndex);
        root->left = helper(inorder, postorder, inStart, inIndex - 1, postIndex);

        return root;
    }

    // Helper function to find the index of a value in the inorder array
    int find(int arr[], int start, int end, int value) {
        for (int i = start; i <= end; i++) {
            if (arr[i] == value) return i;
        }
        return -1;
    }
};

// Helper function to print inorder traversal of the tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Solution solution;
    TreeNode* root = solution.buildTree(inorder, postorder, n);

    cout << "Reconstructed Tree Inorder: ";
    printInorder(root);
    cout << endl;

    return 0;
}
