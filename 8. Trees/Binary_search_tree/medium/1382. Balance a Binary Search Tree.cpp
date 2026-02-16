#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
  public:
      void inorder(TreeNode* root, vector<int>& arr) {
          if (!root) return;
  
          inorder(root->left, arr);
          arr.push_back(root->val);
          inorder(root->right, arr);
      }
  
      TreeNode* buildBST(vector<int>& arr, int start, int end) {
          if (start > end) return nullptr;
  
          int mid = start + (end - start) / 2;
          TreeNode* root = new TreeNode(arr[mid]);
  
          root->left = buildBST(arr, start, mid - 1);
          root->right = buildBST(arr, mid + 1, end);
  
          return root;
      }
  
      TreeNode* balanceBST(TreeNode* root) {
          vector<int> arr;
          inorder(root, arr);
          return buildBST(arr, 0, arr.size() - 1);
      }
  };