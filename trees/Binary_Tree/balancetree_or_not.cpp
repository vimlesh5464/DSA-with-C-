#include <iostream>
using namespace std;

// Definition for a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    // Function to check height and balance together
    int check(Node* root) {
        if (root == NULL) {
            return 0; // height = 0 for null node
        }

        int left = check(root->left);
        if (left == -1) {
            return -1; // left subtree unbalanced
        }

        int right = check(root->right);
        if (right == -1) {
            return -1; // right subtree unbalanced
        }

        if (abs(left - right) > 1) {
            return -1; // current node unbalanced
        }

        return 1 + max(left, right); // return height of current node
    }

    // Main function to check if tree is balanced
    bool isBalanced(Node* root) {
        return check(root) != -1;
    }
};

int main() {
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    if (sol.isBalanced(root)) {
        cout << "Tree is Balanced\n";
    } else {
        cout << "Tree is Not Balanced\n";
    }

    return 0;
}
