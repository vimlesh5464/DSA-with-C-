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
    bool isIdentical(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;

        if (root->val != subRoot->val) return false;

        return isIdentical(root->left, subRoot->left) &&
               isIdentical(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;

        if (root->val == subRoot->val) {
            if (isIdentical(root, subRoot)) return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() {
    /*
          root:       3
                     / \
                    4   5
                   / \
                  1   2

        subRoot:    4
                   / \
                  1   2
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    Solution sol;
    cout << (sol.isSubtree(root, subRoot) ? "Yes, subRoot is a subtree ✅" 
                                          : "No, subRoot is not a subtree ❌")
         << endl;

    return 0;
}
