# 100Same Tree.py - Python skeleton converted from C++

# Original C++ code:
# // Given the roots of two binary trees p and q, write a function to check if they are the same or not.
# 
# // Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
# 
#  
# 
# // Example 1:
# 
# // Input: p = [1,2,3], q = [1,2,3]
# // Output: true
# 
# // Example 2:
# 
# // Input: p = [1,2], q = [1,null,2]
# // Output: false
# 
# // Example 3:
# 
# // Input: p = [1,2,1], q = [1,1,2]
# // Output: false
# 
#  
# 
# // Constraints:
# 
# //     The number of nodes in both trees is in the range [0, 100].
# //     -104 <= Node.val <= 104
# 
#  
# #include <iostream>
# #include <vector>
# using namespace std;
# 
# // Definition for a binary tree node.
# class TreeNode {
# public:
#     int val;
#     TreeNode* left;
#     TreeNode* right;
# 
#     TreeNode(int x) {
#         val = x;
#         left = right = nullptr;
#     }
# };
# 
# class Solution {
# public:
#     bool isSameTree(TreeNode* p, TreeNode* q) {
#         if (p == NULL && q == NULL)
#             return true;
# 
#         if (p == NULL || q == NULL)
#             return false;
# 
#         return (p->val == q->val &&
#                 isSameTree(p->left, q->left) &&
#                 isSameTree(p->right, q->right));
#     }
# };
# 
# static int idx;
# 
# // Build tree using preorder input
# TreeNode* buildTree(vector<int>& nodes) {
#     idx++;
# 
#     if (idx >= nodes.size() || nodes[idx] == -1)
#         return nullptr;
# 
#     TreeNode* currNode = new TreeNode(nodes[idx]);
#     currNode->left = buildTree(nodes);
#     currNode->right = buildTree(nodes);
# 
#     return currNode;
# }
# 
# int main() {
# 
#     int n1;
#     cin >> n1;
# 
#     vector<int> nodes1(n1);
#     for (int i = 0; i < n1; i++)
#         cin >> nodes1[i];
# 
#     idx = -1;
#     TreeNode* root1 = buildTree(nodes1);
# 
#     int n2;
#     cin >> n2;
# 
#     vector<int> nodes2(n2);
#     for (int i = 0; i < n2; i++)
#         cin >> nodes2[i];
# 
#     idx = -1;
#     TreeNode* root2 = buildTree(nodes2);
# 
#     Solution obj;
# 
#     if (obj.isSameTree(root1, root2))
#         cout << "True\n";
#     else
#         cout << "False\n";
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
