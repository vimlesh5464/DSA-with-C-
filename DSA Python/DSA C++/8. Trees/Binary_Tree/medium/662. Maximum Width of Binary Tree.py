# 662. Maximum Width of Binary Tree.py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# #include<queue>
# using namespace std;
# 
# 
# // Definition for a binary tree node.
# struct TreeNode {
#     int val;
#     TreeNode *left;
#     TreeNode *right;
#     TreeNode() : val(0), left(nullptr), right(nullptr) {}
#     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
#     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
# };
# 
# // Time Complexity: O(n) → Each node is visited once.
# // Space Complexity: O(n) → Queue stores up to one level of nodes.
# /**
#  * Definition for a binary tree node.
#  * struct TreeNode {
#  *     int val;
#  *     TreeNode *left;
#  *     TreeNode *right;
#  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
#  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
#  *     TreeNode(int x, TreeNode *left, TreeNode *right)
#  *         : val(x), left(left), right(right) {}
#  * };
#  */
# 
#  class Solution {
#   public:
#       int widthOfBinaryTree(TreeNode* root) {
#           // If tree is empty, width is 0
#           if (!root) return 0;
#   
#           long long maxWidth = 0;
#   
#           // Queue stores (node, index)
#           // Index represents the position in a complete binary tree
#           queue<pair<TreeNode*, long long>> q;
#   
#           // Start with root at index 0
#           q.push({root, 0});
#   
#           // Perform level order traversal (BFS)
#           while (!q.empty()) {
#   
#               // Number of nodes in current level
#               int currLevelSize = q.size();
#   
#               // Index of first and last node at this level
#               long long startIdx = q.front().second;
#               long long endIdx   = q.back().second;
#   
#               // Width of current level
#               maxWidth = max(maxWidth, endIdx - startIdx + 1);
#   
#               // Process all nodes of the current level
#               for (int i = 0; i < currLevelSize; i++) {
#                   auto curr = q.front();
#                   q.pop();
#   
#                   TreeNode* node = curr.first;
#   
#                   // Normalize index to prevent integer overflow
#                   long long idx = curr.second - startIdx;
#   
#                   // Left child index = 2 * idx + 1
#                   if (node->left)
#                       q.push({node->left, 2 * idx + 1});
#   
#                   // Right child index = 2 * idx + 2
#                   if (node->right)
#                       q.push({node->right, 2 * idx + 2});
#               }
#           }
#   
#           // Return maximum width found
#           return maxWidth;
#       }
#   };
#   
# 
# // Example usage
# int main() {
#     Solution sol;
# 
#     // Tree:
#     //        1
#     //      /   \
#     //     3     2
#     //    / \     \
#     //   5   3     9
#     TreeNode* root = new TreeNode(1);
#     root->left = new TreeNode(3, new TreeNode(5), new TreeNode(3));
#     root->right = new TreeNode(2, nullptr, new TreeNode(9));
# 
#     cout << sol.widthOfBinaryTree(root) << endl; // Output: 4
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
