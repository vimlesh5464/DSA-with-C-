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

////////////////////////////////////////////////////////
// 🚩 Brute Force Solution: O(N²)
////////////////////////////////////////////////////////
class BruteForceSolution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        int curr = height(root->left) + height(root->right);
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);

        return max(curr, max(left, right));
    }
};

////////////////////////////////////////////////////////
// 🚀 Optimized Solution: O(N)
////////////////////////////////////////////////////////
class OptimizedSolution {
public:
    int maxDia = 0;

    int height(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = height(root->left);
        int right = height(root->right);

        // Update diameter at this node
        maxDia = max(maxDia, left + right);

        return 1 + max(left, right); // return height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDia;
    }
};

////////////////////////////////////////////////////////
// Main Driver
////////////////////////////////////////////////////////
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    BruteForceSolution brute;
    OptimizedSolution opt;

    cout << "Brute Force Diameter: " << brute.diameterOfBinaryTree(root) << endl;
    cout << "Optimized Diameter:   " << opt.diameterOfBinaryTree(root) << endl;

    return 0;
}
