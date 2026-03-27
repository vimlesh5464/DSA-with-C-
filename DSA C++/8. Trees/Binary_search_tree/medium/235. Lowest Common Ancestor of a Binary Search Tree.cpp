
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
      TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          if (root == nullptr) return nullptr;
  
          // If both p and q are smaller than root
          if (p->val < root->val && q->val < root->val)
              return lowestCommonAncestor(root->left, p, q);
  
          // If both p and q are greater than root
          else if (p->val > root->val && q->val > root->val)
              return lowestCommonAncestor(root->right, p, q);
  
          // Otherwise, root is the split point (LCA)
          else
              return root;
      }
  };
  