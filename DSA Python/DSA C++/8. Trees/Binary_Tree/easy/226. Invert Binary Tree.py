# 226. Invert Binary Tree.py - Python skeleton converted from C++

# Original C++ code:
# 
# #include<iostream>
# #include<vector>
# 
# using namespace std;
# 
# class TreeNode {
# public:
#     int data;
#     TreeNode* left;
#     TreeNode* right;
# 
#     TreeNode(int data) {
#         this->data = data;
#         left = right = nullptr;
#     }
# };
# 
# class Solution {
#   public:
#       TreeNode* invertTree(TreeNode* root) {
#           if(root==NULL){
#               return root;
#           }
#           TreeNode* left = invertTree(root->left);
#           TreeNode* right = invertTree(root->right);
#           // Swap children
#           root->left = right;
#           root->right = left;
#           return root;
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
