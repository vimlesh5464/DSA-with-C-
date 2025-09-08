#include <iostream>
#include<queue>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//Time Complexity = O(n)
//Space Complexity = O(n)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int leftMost = root->val;

        while (!q.empty()) {
            int size = q.size();
            leftMost = q.front()->val; // first node of this level

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return leftMost;
    }
};

// Helper function to build a sample tree
TreeNode* buildTree() {
    // Example Tree:
    //       2
    //      / \
    //     1   3
    //    /
    //   4
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTree();

    cout << "Bottom Left Value: " << sol.findBottomLeftValue(root) << endl;

    return 0;
}
