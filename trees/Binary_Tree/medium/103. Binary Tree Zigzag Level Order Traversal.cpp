#include <iostream>
#include<queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time Complexity: O(n) → Every node is visited once.
// Space Complexity: O(n) → Queue for BFS + result storage.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Decide position based on traversal direction
                int index = leftToRight ? i : (size - 1 - i);
                level[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
            leftToRight = !leftToRight; // flip direction
        }

        return result;
    }
};

// Example usage
int main() {
    Solution sol;

    // Tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3, new TreeNode(6), new TreeNode(7));

    vector<vector<int>> res = sol.zigzagLevelOrder(root);

    for (auto& level : res) {
        for (int val : level) cout << val << " ";
        cout << endl;
    }
    // Output:
    // 1
    // 3 2
    // 4 5 6 7
}
