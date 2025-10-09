
#include<iostream>
#include<vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
      void inorder(TreeNode* root, int &k, int &ans) {
          if (root == nullptr) return;
  
          // Traverse left subtree
          inorder(root->left, k, ans);
  
          // Visit current node
          k--;
          if (k == 0) {
              ans = root->val;
              return;
          }
  
          // Traverse right subtree
          inorder(root->right, k, ans);
      }
  
      int kthSmallest(TreeNode* root, int k) {
          int ans = -1;
          inorder(root, k, ans);
          return ans;
      }
  };
  