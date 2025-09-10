#include <iostream>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

//////////////////////////////////////////////////////
// 🚩 Brute Force Solution (O(N²))
//////////////////////////////////////////////////////
class BruteForceSolution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        int left = height(root->left);
        int right = height(root->right);

        if (abs(left - right) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

//////////////////////////////////////////////////////
// 🚀 Optimized Solution (O(N))
//////////////////////////////////////////////////////
class OptimizedSolution {
public:
    int check(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = check(root->left);
        if (left == -1) return -1;

        int right = check(root->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return 1 + max(left, right); // return height
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
};

//////////////////////////////////////////////////////
// Main Driver
//////////////////////////////////////////////////////
int main() {
    /*
           1
          / \
         2   3
        /
       4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    BruteForceSolution brute;
    OptimizedSolution opt;

    cout << "Brute Force:  " 
         << (brute.isBalanced(root) ? "Balanced ✅" : "Not Balanced ❌") << endl;

    cout << "Optimized:    " 
         << (opt.isBalanced(root) ? "Balanced ✅" : "Not Balanced ❌") << endl;

    return 0;
}
