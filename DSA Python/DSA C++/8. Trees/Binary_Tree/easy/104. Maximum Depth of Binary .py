# 104. Maximum Depth of Binary .py - Python skeleton converted from C++

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
#       int maxDepth(TreeNode* root) {
#           if(root == NULL){
#               return 0;
#           }
#           int leftht = maxDepth(root->left);
#           int rightht = maxDepth(root->right);
#           int curht = max(leftht, rightht)+1;
#   
#           return curht;
#       }
#   };
# 
#   int main() {
#     // Example tree
#     TreeNode* root = new TreeNode(1);
#     root->left = new TreeNode(2);
#     root->right = new TreeNode(3);
#     root->left->left = new TreeNode(4);
#     root->left->right = new TreeNode(5);
# 
#     Solution sol;
#     cout << "Max Depth of tree: " << sol.maxDepth(root) << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
