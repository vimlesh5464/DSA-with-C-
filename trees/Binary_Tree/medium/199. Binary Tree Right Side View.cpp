#include <iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recursive(TreeNode* root, int level, vector<int> &result) {
        if(root == NULL) {
            return;
        }
        // If we are visiting this level for the first time, add the node's value
        if(result.size() == level) 
            result.push_back(root->val);
        
        // Visit right subtree first so rightmost element is recorded first
        recursive(root->right, level + 1, result);
        recursive(root->left, level + 1, result);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        recursive(root, 0, result);
        return result;
    }
};

// Helper function to build a sample tree
TreeNode* buildTree() {
    // Example Tree:
    //       1
    //      / \
    //     2   3
    //      \   \
    //       5   4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTree();

    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
