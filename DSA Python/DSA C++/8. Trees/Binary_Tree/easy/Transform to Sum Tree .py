# Transform to Sum Tree .py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# using namespace std;
# 
# // Definition for a binary tree node.
# class Node {
# public:
#     int data;
#     Node* left;
#     Node* right;
# 
#     Node(int val) {
#         data = val;
#         left = right = nullptr;
#     }
# };
# 
# // Solution class to convert tree to Sum Tree
# 
# class Solution {
#   public:
#   
#       // Helper function that returns sum of subtree
#       int helper(Node* node) {
#         if (!node) return 0;
# 
#         // Save original value
#         int oldVal = node->data;
# 
#         // Recursively convert left and right subtrees
#         int leftSum = helper(node->left);
#         int rightSum = helper(node->right);
# 
#         // Update current node to sum of left and right subtrees
#         node->data = leftSum + rightSum;
# 
#         // Return sum including original value for parent calculation
#         return node->data + oldVal;
#       }
#   
#       void toSumTree(Node* node) {
#           helper(node);
#       }
#   };
# 
# // Function to print in-order traversal
# void inorder(Node* root) {
#     if (!root) return;
#     inorder(root->left);
#     cout << root->data << " ";
#     inorder(root->right);
# }
# 
# int main() {
#     // Build example tree
#     Node* root = new Node(10);
#     root->left = new Node(-2);
#     root->right = new Node(6);
#     root->left->left = new Node(8);
#     root->left->right = new Node(-4);
#     root->right->left = new Node(7);
#     root->right->right = new Node(5);
# 
#     cout << "Original tree in-order: ";
#     inorder(root);
#     cout << endl;
# 
#     Solution sol;
#     sol.toSumTree(root);
# 
#     cout << "Sum tree in-order: ";
#     inorder(root);
#     cout << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
