#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// ✅ Time & Space Complexity
// Time Complexity
// We do a reverse in-order traversal, visiting each node once.
// Each visit takes O(1) work (update sum + assign value).
// Total = O(n), where n = number of nodes.

// Space Complexity
// The recursion stack depth = height of tree = O(h).
// In worst case (skewed tree) → O(n).
// In balanced BST → O(log n).
// ✅ Time = O(n), Space = O(h)
class Solution {
public:
    int sum = 0;  // running total of node values

    TreeNode* bstToGst(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        // Reverse in-order: right → node → left
        bstToGst(root->right);

        sum += root->val;       // add current value
        root->val = sum;        // update to running sum

        bstToGst(root->left);

        return root;
    }
};

// Helper: Insert nodes into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Helper: Print Inorder Traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    TreeNode* root = nullptr;

    // Example BST: [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
    root = insert(root, 4);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 0);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 8);

    cout << "Inorder of Original BST: ";
    inorder(root);
    cout << endl;

    root = sol.bstToGst(root);

    cout << "Inorder of Greater Sum Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
