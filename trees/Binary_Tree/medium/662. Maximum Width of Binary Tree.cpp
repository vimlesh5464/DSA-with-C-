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

// Time Complexity: O(n) → Each node is visited once.
// Space Complexity: O(n) → Queue stores up to one level of nodes.
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});  // (node, index)

        while (!q.empty()) {
            int size = q.size();
            long long minIndex = q.front().second;  // offset to avoid overflow
            long long first, last;

            for (int i = 0; i < size; i++) {
                long long currIndex = q.front().second - minIndex;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = currIndex;
                if (i == size - 1) last = currIndex;

                if (node->left) q.push({node->left, 2 * currIndex});
                if (node->right) q.push({node->right, 2 * currIndex + 1});
            }
            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};

// Example usage
int main() {
    Solution sol;

    // Tree:
    //        1
    //      /   \
    //     3     2
    //    / \     \
    //   5   3     9
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3, new TreeNode(5), new TreeNode(3));
    root->right = new TreeNode(2, nullptr, new TreeNode(9));

    cout << sol.widthOfBinaryTree(root) << endl; // Output: 4
    return 0;
}
