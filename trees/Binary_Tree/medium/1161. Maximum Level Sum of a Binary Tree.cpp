#include <iostream>
#include<queue>
#include<vector>
using namespace std;
//Time Complexity: O(n)
//Space Complexity: O(n)
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int maxSum = INT_MIN;
        int maxLevel = 1;
        int currentLevel = 1;

        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxLevel = currentLevel;
            }

            currentLevel++;
        }

        return maxLevel;
    }
};

// Helper function to build a sample tree
TreeNode* buildTree() {
    // Example Tree:
    //       1
    //      / \
    //     7   0
    //    / \
    //   7  -8
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTree();

    int result = sol.maxLevelSum(root);

    cout << "Level with Maximum Sum: " << result << endl;

    return 0;
}
