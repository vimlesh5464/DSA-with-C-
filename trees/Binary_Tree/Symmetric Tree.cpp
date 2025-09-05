#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
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


// -------------------- OPTIMIZED RECURSIVE --------------------
class RecursiveSolution {
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;

        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};

// -------------------- OPTIMIZED ITERATIVE BFS --------------------
class IterativeSolution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();

            if (!left && !right) continue;
            if (!left || !right) return false;
            if (left->val != right->val) return false;

            q.push(left->left);
            q.push(right->right);

            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};

// -------------------- DRIVER CODE --------------------
int main() {
    /*
           1
          / \
         2   2
        / \ / \
       3  4 4  3
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

   
    RecursiveSolution recursive;
    IterativeSolution iterative;

    
    cout << "Recursive Result:   " << recursive.isSymmetric(root) << endl;
    cout << "Iterative Result:   " << iterative.isSymmetric(root) << endl;

    return 0;
}
