# 113. Path Sum II.py - Python skeleton converted from C++

# Original C++ code:
# 
# #include<iostream>
# #include<vector>
# 
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
# 
# class Solution {
#   public:
#       void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& res) {
#           if (!root) return;
#   
#           path.push_back(root->val);
#   
#           // If it's a leaf node and sum matches
#           if (!root->left && !root->right && targetSum == root->val) {
#               res.push_back(path);
#           } else {
#               // Recurse left and right with reduced sum
#               dfs(root->left, targetSum - root->val, path, res);
#               dfs(root->right, targetSum - root->val, path, res);
#           }
#   
#           path.pop_back(); // backtrack
#       }
#   
#       vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
#           vector<vector<int>> res;
#           vector<int> path;
#           dfs(root, targetSum, path, res);
#           return res;
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
