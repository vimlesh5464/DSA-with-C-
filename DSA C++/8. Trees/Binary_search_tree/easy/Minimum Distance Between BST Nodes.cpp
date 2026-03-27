#include <iostream>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    int mindiff = INT_MAX;
    TreeNode* prev = nullptr;

    // Inorder traversal (LNR)
    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);

        if (prev != nullptr) {
            mindiff = min(mindiff, root->val - prev->val);
        }
        prev = root;

        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return mindiff;
    }
};

int main() {
    /*
           4
          / \
         2   6
        / \
       1   3
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    cout << "Minimum Difference in BST: " << sol.minDiffInBST(root) << endl;

    return 0;
}
