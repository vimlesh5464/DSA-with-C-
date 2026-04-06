# 513. Find Bottom Left Tree Value.py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# #include<queue>
# #include<vector>
# #include<map>
# using namespace std;
# 
# // Definition for a binary tree node.
# struct TreeNode {
#     int val;
#     TreeNode *left;
#     TreeNode *right;
#     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
# };
# //Time Complexity = O(n)
# //Space Complexity = O(n)
# class Solution {
# public:
#     int findBottomLeftValue(TreeNode* root) {
#         queue<TreeNode*> q;
#         q.push(root);
#         int leftMost = root->val;
# 
#         while (!q.empty()) {
#             int size = q.size();
#             leftMost = q.front()->val; // first node of this level
# 
#             for (int i = 0; i < size; ++i) {
#                 TreeNode* node = q.front();
#                 q.pop();
# 
#                 if (node->left) q.push(node->left);
#                 if (node->right) q.push(node->right);
#             }
#         }
# 
#         return leftMost;
#     }
# };
# 
# 
# class Solution {
#   public:
#     vector<int> bottomView(TreeNode *root) {
#         vector<int> ans;
#         if (!root) return ans;
# 
#         map<int, int> mp; // HD -> node value
#         queue<pair<TreeNode*, int>> q;
# 
#         q.push({root, 0});
# 
#         while (!q.empty()) {
#             auto it = q.front();
#             q.pop();
# 
#             TreeNode* node = it.first;
#             int hd = it.second;
# 
#             // overwrite value at this HD
#             mp[hd] = node->val;
# 
#             if (node->left)
#                 q.push({node->left, hd - 1});
#             if (node->right)
#                 q.push({node->right, hd + 1});
#         }
# 
#         for (auto x : mp)
#             ans.push_back(x.second);
# 
#         return ans;
#     }
# };
# // Helper function to build a sample tree
# TreeNode* buildTree() {
#     // Example Tree:
#     //       2
#     //      / \
#     //     1   3
#     //    /
#     //   4
#     TreeNode* root = new TreeNode(2);
#     root->left = new TreeNode(1);
#     root->right = new TreeNode(3);
#     root->left->left = new TreeNode(4);
#     return root;
# }
# 
# int main() {
#     Solution sol;
#     TreeNode* root = buildTree();
# 
#     vector<int>ans= sol.bottomView(root);
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
