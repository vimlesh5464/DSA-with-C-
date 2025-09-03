#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function returns sum of subtree if it is sum tree, else -1
int sumTreeHelper(TreeNode* root) {
    if (!root) return 0;              // empty tree
    if (!root->left && !root->right)  // leaf node
        return root->val;

    int leftSum = sumTreeHelper(root->left);
    if (leftSum == -1) return -1;

    int rightSum = sumTreeHelper(root->right);
    if (rightSum == -1) return -1;

    if (root->val != leftSum + rightSum)
        return -1;

    return root->val + leftSum + rightSum;
}

bool isSumTree(TreeNode* root) {
    return sumTreeHelper(root) != -1;
}

// Test
int main() {
    TreeNode* root = new TreeNode(26);
    root->left = new TreeNode(10);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(3);

    if (isSumTree(root))
        cout << "The tree is a Sum Tree" << endl;
    else
        cout << "The tree is NOT a Sum Tree" << endl;

    return 0;
}
