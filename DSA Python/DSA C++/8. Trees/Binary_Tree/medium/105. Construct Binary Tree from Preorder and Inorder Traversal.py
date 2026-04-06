# 105. Construct Binary Tree from Preorder and Inorder Traversal.py - Python skeleton converted from C++

# Original C++ code:
# 
# #include<iostream>
# #include<unordered_map>
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
#       TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
#                                 vector<int>& inorder, int inStart, int inEnd,
#                                 unordered_map<int, int>& inMap) {
#           if (preStart > preEnd || inStart > inEnd)
#               return nullptr;
#   
#           // Root node = first element of preorder
#           TreeNode* root = new TreeNode(preorder[preStart]);
#   
#           // Find index of root in inorder
#           int inRoot = inMap[root->val];
#           int numsLeft = inRoot - inStart;
#   
#           // Build left subtree
#           root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
#                                        inorder, inStart, inRoot - 1, inMap);
#   
#           // Build right subtree
#           root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
#                                         inorder, inRoot + 1, inEnd, inMap);
#   
#           return root;
#       }
#   
#       TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
#           unordered_map<int, int> inMap;
#           for (int i = 0; i < inorder.size(); i++) {
#               inMap[inorder[i]] = i;
#           }
#   
#           return buildTreeHelper(preorder, 0, preorder.size() - 1,
#                                  inorder, 0, inorder.size() - 1, inMap);
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
