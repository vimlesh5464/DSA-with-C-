//✅ Approach 1: Recursive (Reverse Preorder, Optimized O(n))
#include <iostream>
#include<stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
        if (!root) return;

        // Flatten right first, then left (reverse preorder)
        flatten(root->right);
        flatten(root->left);

        // Rearrange pointers
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};

//✅ Approach 2: Iterative (Stack-based)
// Time: O(n) (each node pushed/popped once)
// Space: O(n) (explicit stack in worst case)
class Solution {
  public:
      void flatten(TreeNode* root) {
          if (!root) return;
  
          stack<TreeNode*> st;
          st.push(root);
  
          while (!st.empty()) {
              TreeNode* node = st.top();
              st.pop();
  
              if (node->right) st.push(node->right);
              if (node->left) st.push(node->left);
  
              if (!st.empty()) {
                  node->right = st.top();
              }
              node->left = nullptr; // must set left null
          }
      }
  };
  

// Example usage
int main() {
    Solution sol;

    // Tree:   1
    //       /   \
    //      2     5
    //     / \     \
    //    3   4     6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(5, nullptr, new TreeNode(6));

    sol.flatten(root);

    // Print flattened list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    TreeNode* curr = root;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    return 0;
}
