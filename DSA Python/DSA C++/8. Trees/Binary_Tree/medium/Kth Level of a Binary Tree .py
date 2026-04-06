# Kth Level of a Binary Tree .py - Python skeleton converted from C++

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
# class Tree{
#   public:
#   void helper(TreeNode* root, int k, vector<int>& result) {
#     if (!root) return;
# 
#     if (k == 1) {
#         result.push_back(root->data);
#         return;
#     }
# 
#     helper(root->left, k - 1, result);
#     helper(root->right, k - 1, result);
# }
# 
# vector<int> Kth_order(TreeNode* root, int k) {
#     vector<int> result;
#     helper(root, k, result);
#     return result;
# }
# };
# int main() {
#   Tree tree;
#   TreeNode* root = new TreeNode(26);
#   root->left = new TreeNode(10);
#   root->right = new TreeNode(3);
#   root->left->left = new TreeNode(4);
#   root->left->right = new TreeNode(6);
#   root->right->right = new TreeNode(3);
#   int k = 3;
#   vector<int> ans=tree.Kth_order(root, k);
#   for(int i = 0; i < ans.size(); i++){
#     cout<<ans[i]<<endl;
#   }
# 
#   return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
