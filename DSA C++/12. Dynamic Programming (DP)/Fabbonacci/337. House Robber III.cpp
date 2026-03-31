// The thief has found himself a new place for his thievery again. There is only one
// entrance to this area, called root.

// Besides the root, each house has one and only one parent house. After a tour, the 
//smart thief realized that all houses in this place form a binary tree. It will 
//automatically contact the police if two directly-linked houses were broken into on
// the same night.

// Given the root of the binary tree, return the maximum amount of money the thief 
//can rob without alerting the police.

 

// Example 1:

// Input: root = [3,2,3,null,3,null,1]
// Output: 7
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

// Example 2:

// Input: root = [3,4,5,1,3,null,1]
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 104].
//     0 <= Node.val <= 104

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