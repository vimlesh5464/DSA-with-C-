#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool validateHelper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (root == nullptr) return true;

        if (minNode != nullptr && root->val <= minNode->val) return false;
        if (maxNode != nullptr && root->val >= maxNode->val) return false;

        return validateHelper(root->left, minNode, root) &&
               validateHelper(root->right, root, maxNode);
    }

    bool isValidBST(TreeNode* root) {
        return validateHelper(root, nullptr, nullptr);
    }
};

// Helper: Build a simple tree
TreeNode* buildTestTree() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;

    TreeNode* root = buildTestTree();
    cout << (sol.isValidBST(root) ? "Valid BST" : "Invalid BST") << endl;

    // Create an invalid BST
    TreeNode* bad = new TreeNode(5);
    bad->left = new TreeNode(1);
    bad->right = new TreeNode(4);
    bad->right->left = new TreeNode(3);
    bad->right->right = new TreeNode(6);

    cout << (sol.isValidBST(bad) ? "Valid BST" : "Invalid BST") << endl;

    return 0;
}
