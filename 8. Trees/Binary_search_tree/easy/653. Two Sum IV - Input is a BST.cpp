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
  void inorderTraversal(TreeNode* root, vector<int>& inorder) {
          // If root is null, stop recursion
          if (!root) return;
  
          // Traverse left subtree
          inorderTraversal(root->left, inorder);
          // Add current node value to vector
          inorder.push_back(root->val);
          // Traverse right subtree
          inorderTraversal(root->right, inorder);
      }
      bool findTarget(TreeNode* root, int k) {
          // Vector stores inorder traversal of BST
          vector<int> inorder;
  
          // Call helper to fill vector
          inorderTraversal(root, inorder);
  
          // Initialize two pointers for searching in sorted inorder array
          int left = 0;
          int right = inorder.size() - 1;
  
          // Loop until pointers meet
          while (left < right) {
              // Calculate sum of current pair
              int sum = inorder[left] + inorder[right];
  
              // If sum equals k, we found a pair
              if (sum == k) {
                  return true;
              }
              // If sum smaller than k, move left pointer forward
              else if (sum < k) {
                  left++;
              }
              // If sum larger than k, move right pointer backward
              else {
                  right--;
              }
          }
  
          // If no such pair found, return false
          return false;
      }
  };