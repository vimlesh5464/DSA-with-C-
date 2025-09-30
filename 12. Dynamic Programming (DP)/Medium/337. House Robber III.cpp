#include <iostream>
#include <unordered_map>
#include <algorithm> // for max
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
  public:
  int rec(TreeNode* root){
      if(root==NULL){
          return 0;
      }
      int take = root->val;
      if(root->left!=NULL){
          take += rec(root->left->left)+rec(root->left->right);
      }
      if(root->right!=NULL){
          take += rec(root->right->left)+rec(root->right->right);
      }
      int notTake = rec(root->left)+rec(root->right);
      return max(take, notTake);
  }
      int rob(TreeNode* root) {
          return rec(root);
      }
  };

  class Solution {
    public:
    int rec(TreeNode* root, unordered_map<TreeNode*, int> &memo){
        if(root==NULL){
            return 0;
        }
        if(memo[root]!=NULL){
            return memo[root];
        }
        int take = root->val;
        if(root->left!=NULL){
            take += rec(root->left->left,memo)+rec(root->left->right,memo);
        }
        if(root->right!=NULL){
            take += rec(root->right->left,memo)+rec(root->right->right,memo);
        }
        int notTake = rec(root->left,memo)+rec(root->right,memo);
        return memo[root] = max(take, notTake);
    }
        int rob(TreeNode* root) {
            unordered_map<TreeNode*, int> memo;
            return rec(root,memo);
        }
    };