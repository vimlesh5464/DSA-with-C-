# 103. Binary Tree Zigzag Level Order Traversal.py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# #include<queue>
# using namespace std;
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
# // Time Complexity: O(n) → Every node is visited once.
# // Space Complexity: O(n) → Queue for BFS + result storage.
# class Solution {
# public:
#     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
#         vector<vector<int>> result;
#         if (!root) return result;
# 
#         queue<TreeNode*> q;
#         q.push(root);
#         bool leftToRight = true;
# 
#         while (!q.empty()) {
#             int size = q.size();
#             vector<int> level(size);
# 
#             for (int i = 0; i < size; i++) {
#                 TreeNode* node = q.front();
#                 q.pop();
# 
#                 // Decide position based on traversal direction
#                 int index = leftToRight ? i : (size - 1 - i);
#                 level[index] = node->val;
# 
#                 if (node->left) q.push(node->left);
#                 if (node->right) q.push(node->right);
#             }
# 
#             result.push_back(level);
#             leftToRight = !leftToRight; // flip direction
#         }
# 
#         return result;
#     }
# };
# // ---------------- Recursive Build from Vector (Preorder) ----------------
# int idx = -1;  // global index for recursive build
# TreeNode* buildTree(vector<int>& nodes) {
#     idx++;
#     if (idx >= nodes.size() || nodes[idx] == -1) return nullptr;
# 
#     TreeNode* currNode = new TreeNode(nodes[idx]);
#     currNode->left = buildTree(nodes);
#     currNode->right = buildTree(nodes);
#     return currNode;
# }
# 
# // ---------------- Inorder Print ----------------
# void printInorder(TreeNode* root) {
#     if (!root) return;
#     printInorder(root->left);
#     cout << root->val << " ";
#     printInorder(root->right);
# }
# // Example usage
# int main() {
#   int n;
#   cout << "Enter number of nodes: ";
#   cin >> n;
# 
#   vector<int> nodes(n);
#   cout << "Enter nodes level-order (-1 for NULL): ";
#   for (int i = 0; i < n; i++) cin >> nodes[i];
# 
#   // Build tree
#   TreeNode* root = buildTree(nodes);
# 
#   // Solve
#   Solution sol;
#   vector<vector<int>> res = sol.zigzagLevelOrder(root);
# 
#   // Print Output
#   cout << "\nZigzag Level Order Traversal:\n";
#   for (auto &level : res) {
#       for (int val : level) cout << val << " ";
#       cout << endl;
#   }
# 
#   return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
