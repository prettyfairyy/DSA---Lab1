#include <iostream>
#include <algorithm>
using namespace std;

// Definition of the binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Helper method to insert a new value into the BST
    TreeNode* insert(TreeNode* node, int value) {
        if (!node) return new TreeNode(value);
        if (value < node->val)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    // Helper method to find the minimum value in a subtree
    int findMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node->val;
    }

    // Helper method to find the maximum value in a subtree
    int findMax(TreeNode* node) {
        while (node->right) {
            node = node->right;
        }
        return node->val;
    }

    // Helper method to calculate the height of a subtree
    int calculateHeight(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(calculateHeight(node->left), calculateHeight(node->right));
    }

    // Helper method to check if the tree is balanced
    bool isBalancedHelper(TreeNode* node) {
        if (!node) return true;

        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        return abs(leftHeight - rightHeight) <= 1 &&
               isBalancedHelper(node->left) &&
               isBalancedHelper(node->right);
    }

    // Helper method for inorder traversal
    void inorderTraversal(TreeNode* node) {
        if (!node) return;
        inorderTraversal(node->left);
        cout << node->val << " ";
        inorderTraversal(node->right);
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }

    // Find the minimum value in the BST
    int findMin() {
        if (!root) throw runtime_error("Tree is empty");
        return findMin(root);
    }

    // Find the maximum value in the BST
    int findMax() {
        if (!root) throw runtime_error("Tree is empty");
        return findMax(root);
    }

    // Calculate the height of the BST
    int calculateHeight() {
        return calculateHeight(root);
    }

    // Check if the tree is balanced
    bool isBalanced() {
        return isBalancedHelper(root);
    }

    // Print the tree in inorder traversal
    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert elements
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    cout << "Inorder Traversal: ";
    bst.inorderTraversal();

    cout << "Minimum Value: " << bst.findMin() << endl;
    cout << "Maximum Value: " << bst.findMax() << endl;
    cout << "Height of Tree: " << bst.calculateHeight() << endl;
    cout << "Is Balanced: " << (bst.isBalanced() ? "Yes" : "No") << endl;

    return 0;
}


