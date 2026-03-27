#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Find the inorder successor (leftmost node in right subtree)
    TreeNode* getInorderSuccessor(TreeNode* root) {
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node to delete found
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            TreeNode* IS = getInorderSuccessor(root->right);
            root->val = IS->val;
            root->right = deleteNode(root->right, IS->val);
        }

        return root;
    }
};

// Helper: Inorder traversal to print BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Original BST (inorder): ";
    inorder(root);
    cout << endl;

    Solution sol;
    root = sol.deleteNode(root, 3);  // delete node with value 3

    cout << "BST after deleting 3: ";
    inorder(root);
    cout << endl;

    return 0;
}
