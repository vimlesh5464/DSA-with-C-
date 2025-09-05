//identical Tree
#include <iostream>
using namespace std;

// Definition for a binary tree node.
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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;  // both trees are empty
        }
        if (p == NULL || q == NULL) {
            return false; // one is empty, the other is not
        }

        // check current node + left subtree + right subtree
        return (p->val == q->val &&
                isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right));
    }
};

int main() {
    /*
         Tree 1:        1
                       / \
                      2   3

         Tree 2:        1
                       / \
                      2   3
    */

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    cout << (sol.isSameTree(p, q) ? "Trees are Same" : "Trees are Different") << endl;

    return 0;
}
