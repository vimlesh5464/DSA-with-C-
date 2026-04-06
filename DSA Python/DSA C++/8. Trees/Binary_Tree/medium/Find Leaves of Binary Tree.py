# Find Leaves of Binary Tree.py - Python skeleton converted from C++

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
#       int countLeaves(TreeNode* root) {
#           if (root == nullptr)
#               return 0;
#   
#           // If it's a leaf node
#           if (root->left == nullptr && root->right == nullptr)
#               return 1;
#   
#           // Otherwise, count in both subtrees
#           return countLeaves(root->left) + countLeaves(root->right);
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
