#include <iostream>
#include<queue>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Time Complexity: O(n)
// Space Complexity: O(h) (worst-case O(n), balanced tree O(log n))

class Solution {
public:
    // Find path from root to a given node value
    bool rootNodePath(TreeNode* root, int n, vector<int> &path) {
        if (root == NULL) {
            return false;
        }
        path.push_back(root->val);

        if (root->val == n) {
            return true;
        }

        bool isLeft = rootNodePath(root->left, n, path);
        bool isRight = rootNodePath(root->right, n, path);

        if (isLeft || isRight) {
            return true;
        }

        path.pop_back();
        return false;
    }

    // Main function to find LCA
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> path1, path2;

        rootNodePath(root, p->val, path1);
        rootNodePath(root, q->val, path2);

        int lcaVal = -1;
        for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++) {
            if (path1[i] != path2[j]) {
                break;
            }
            lcaVal = path1[i];
        }

        return findNode(root, lcaVal);  // Convert LCA value → TreeNode*
    }

    // Find node in tree by value
    TreeNode* findNode(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val == val) return root;
        TreeNode* left = findNode(root->left, val);
        if (left) return left;
        return findNode(root->right, val);
    }
};

// Helper: Build a sample tree
TreeNode* buildTree() {
    // Example Tree:
    //       3
    //      / \
    //     5   1
    //    / \ / \
    //   6  2 0  8
    //     / \
    //    7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildTree();

    TreeNode* p = root->left;              // Node 5
    TreeNode* q = root->left->right->right; // Node 4

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    return 0;
}
