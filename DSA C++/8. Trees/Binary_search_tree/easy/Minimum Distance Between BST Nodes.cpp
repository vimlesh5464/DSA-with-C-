// Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

 

// Example 1:

// Input: root = [4,2,6,1,3]
// Output: 1

// Example 2:

// Input: root = [1,0,48,null,null,12,49]
// Output: 1

 

// Constraints:

//     The number of nodes in the tree is in the range [2, 100].
//     0 <= Node.val <= 105

 

// Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 
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
