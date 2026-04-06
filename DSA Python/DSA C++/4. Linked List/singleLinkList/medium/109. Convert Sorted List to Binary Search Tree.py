# 109. Convert Sorted List to Binary Search Tree.py - Python skeleton converted from C++

# Original C++ code:
# // Given the head of a singly linked list where elements are sorted in ascending order, convert it to a binary search tree.
# 
#  
# 
# // Example 1:
# 
# // Input: head = [-10,-3,0,5,9]
# // Output: [0,-3,9,-10,null,5]
# // Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
# 
# // Example 2:
# 
# // Input: head = []
# // Output: []
# 
#  
# 
# // Constraints:
# 
# //     The number of nodes in head is in the range [0, 2 * 104].
# //     -105 <= Node.val <= 105
# 
# #include <iostream>
# #include<vector>
# using namespace std;
# 
# // Definition for singly-linked list.
# struct TreeNode {
#        int val;
#        TreeNode *left;
#        TreeNode *right;
#        TreeNode() : val(0), left(nullptr), right(nullptr) {}
#        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
#        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
#    };
#    struct ListNode {
#     int val;
#     ListNode *next;
#     ListNode() : val(0), next(nullptr) {}
#     ListNode(int x) : val(x), next(nullptr) {}
#     ListNode(int x, ListNode *next) : val(x), next(next) {}
# };
# 
# class Solution {
#   public:
#   TreeNode* buildBST(vector<int>& nums, int start, int end) {
#           if (start > end) return nullptr;
#   
#           int mid = start + (end - start) / 2;
#           TreeNode* root = new TreeNode(nums[mid]);
#   
#           root->left = buildBST(nums, start, mid - 1);
#           root->right = buildBST(nums, mid + 1, end);
#   
#           return root;
#       }
#   
#       TreeNode* sortedListToBST(ListNode* head) {
#           vector<int>nums;
#           ListNode* temp = head;
#           while(temp!=NULL){
#               nums.push_back(temp->val);
#               temp = temp->next;
#           }
#           return buildBST(nums,0,nums.size()-1);
#       }
#   };
# 
#   class Solution {
#     public:
#         TreeNode* sortedListToBST(ListNode* head) {
#             if (!head) return nullptr;
#             if (!head->next) return new TreeNode(head->val);
#     
#             ListNode* slow = head;
#             ListNode* fast = head;
#             ListNode* prev = nullptr;
#     
#             // Find middle (slow)
#             while (fast && fast->next) {
#                 prev = slow;
#                 slow = slow->next;
#                 fast = fast->next->next;
#             }
#     
#             // Disconnect left half from middle
#             prev->next = nullptr;
#     
#             // Middle node is root
#             TreeNode* root = new TreeNode(slow->val);
#     
#             // Recursively build left and right subtrees
#             root->left = sortedListToBST(head);
#             root->right = sortedListToBST(slow->next);
#     
#             return root;
#         }
#     };
#     

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
