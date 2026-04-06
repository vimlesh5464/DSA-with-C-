# 1448. Count Good Nodes in Binary Tree.py - Python skeleton converted from C++

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
#   int dfs(TreeNode* root, int maxitem){
#       if(root==NULL){
#           return 0;
#       }
#       int count = 0;
#       if(root->val>=maxitem){
#           count++;
#       }
#       maxitem=max(root->val,maxitem);
#       count += dfs(root->left,maxitem);
#       count += dfs(root->right,maxitem);
#       return count;
#   }
#       int goodNodes(TreeNode* root) {
#           return dfs(root, root->val);
#       }
#   };
# 
# 
# int main() {
#   // Example tree
#   TreeNode* root = new TreeNode(3);
#   root->left = new TreeNode(1);
#   root->right = new TreeNode(4);
#   root->left->left = new TreeNode(3);
#   root->right->left = new TreeNode(1);
#   root->right->right = new TreeNode(5);
# 
#   Solution sol;
#   cout << "Number of good nodes: " << sol.goodNodes(root) << endl;
# 
#   return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
