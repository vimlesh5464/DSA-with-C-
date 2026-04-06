# 257. Binary Tree Paths.py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# #include <vector>
# using namespace std;
# 
# class TreeNode {
# public:
#     int val;
#     TreeNode* left;
#     TreeNode* right;
# 
#     TreeNode(int val) {
#         this->val = val;
#         left = right = nullptr;
#     }
# };
# class Solution {
#   public:
#       vector<string> binaryTreePaths(TreeNode* root) {
#           vector<string> res;
#           if (!root) return res;
#   
#           dfs(root, "", res);
#           return res;
#       }
#   
#       void dfs(TreeNode* node, string path, vector<string>& res) {
#           if (!node) return;
#   
#           // Build path
#           if (path.empty()) path = to_string(node->val);
#           else path += "->" + to_string(node->val);
#   
#           // If leaf → push to result
#           if (!node->left && !node->right) {
#               res.push_back(path);
#               return;
#           }
#   
#           // Recursive calls
#           dfs(node->left, path, res);
#           dfs(node->right, path, res);
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
