# 114. Flatten Binary Tree to Linked List.py - Python skeleton converted from C++

# Original C++ code:
# // Given the root of a binary tree, flatten the tree into a "linked list":
# 
# //     The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
# //     The "linked list" should be in the same order as a pre-order traversal of the binary tree.
# 
#  
# 
# // Example 1:
# 
# // Input: root = [1,2,5,3,4,null,6]
# // Output: [1,null,2,null,3,null,4,null,5,null,6]
# 
# // Example 2:
# 
# // Input: root = []
# // Output: []
# 
# // Example 3:
# 
# // Input: root = [0]
# // Output: [0]
# 
#  
# 
# // Constraints:
# 
# //     The number of nodes in the tree is in the range [0, 2000].
# //     -100 <= Node.val <= 100
# 
#  
# // Follow up: Can you flatten the tree in-place (with O(1) extra space)?
# //✅ Approach 1: Recursive (Reverse Preorder, Optimized O(n))
# #include <iostream>
# #include<stack>
# using namespace std;
# 
# // Definition for a binary tree node.
# struct TreeNode {
#     int val;
#     TreeNode *left;
#     TreeNode *right;
#     TreeNode() : val(0), left(nullptr), right(nullptr) {}
#     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
#     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
# };
# 
# class Solution {
# public:
#     TreeNode* prev = nullptr;
# 
#     void flatten(TreeNode* root) {
#         if (!root) return;
# 
#         // Flatten right first, then left (reverse preorder)
#         flatten(root->right);
#         flatten(root->left);
# 
#         // Rearrange pointers
#         root->right = prev;
#         root->left = nullptr;
#         prev = root;
#     }
# };
# 
# //✅ Approach 2: Iterative (Stack-based)
# // Time: O(n) (each node pushed/popped once)
# // Space: O(n) (explicit stack in worst case)
# class Solution {
#   public:
#       void flatten(TreeNode* root) {
#           if (!root) return;
#   
#           stack<TreeNode*> st;
#           st.push(root);
#   
#           while (!st.empty()) {
#               TreeNode* node = st.top();
#               st.pop();
#   
#               if (node->right) st.push(node->right);
#               if (node->left) st.push(node->left);
#   
#               if (!st.empty()) {
#                   node->right = st.top();
#               }
#               node->left = nullptr; // must set left null
#           }
#       }
#   };
#   
# 
# // Example usage
# int main() {
#     Solution sol;
# 
#     // Tree:   1
#     //       /   \
#     //      2     5
#     //     / \     \
#     //    3   4     6
#     TreeNode* root = new TreeNode(1);
#     root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
#     root->right = new TreeNode(5, nullptr, new TreeNode(6));
# 
#     sol.flatten(root);
# 
#     // Print flattened list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
#     TreeNode* curr = root;
#     while (curr) {
#         cout << curr->val << " ";
#         curr = curr->right;
#     }
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
