# 1019. Next Greater Node In Linked List.py - Python skeleton converted from C++

# Original C++ code:
# // You are given the head of a linked list with n nodes.
# 
# // For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.
# 
# // Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.
# 
#  
# 
# // Example 1:
# 
# // Input: head = [2,1,5]
# // Output: [5,5,0]
# 
# // Example 2:
# 
# // Input: head = [2,7,4,3,5]
# // Output: [7,0,5,5,0]
# 
#  
# 
# // Constraints:
# 
# //     The number of nodes in the list is n.
# //     1 <= n <= 104
# //     1 <= Node.val <= 109
# 
# #include <iostream>
# #include<vector>
# #include<stack>
# using namespace std;
# 
# // Definition for singly-linked list.
# struct ListNode {
#     int val;
#     ListNode *next;
#     ListNode() : val(0), next(nullptr) {}
#     ListNode(int x) : val(x), next(nullptr) {}
#     ListNode(int x, ListNode *next) : val(x), next(next) {}
# };
# class Solution {
#   public:
#       vector<int> nextLargerNodes(ListNode* head) {
#           // Step 1: Convert linked list to array
#           vector<int> nums;
#           ListNode* temp = head;
#           while (temp) {
#               nums.push_back(temp->val);
#               temp = temp->next;
#           }
#   
#           int n = nums.size();
#           vector<int> ans(n, 0);
#           stack<int> st; // store indices
#   
#           // Step 2: Traverse from right to left
#           for (int i = n - 1; i >= 0; i--) {
#               // Pop all smaller or equal elements
#               while (!st.empty() && nums[st.top()] <= nums[i]) {
#                   st.pop();
#               }
#   
#               // If stack not empty, top is next greater
#               if (!st.empty()) {
#                   ans[i] = nums[st.top()];
#               }
#   
#               // Push current index
#               st.push(i);
#           }
#   
#           return ans;
#       }
#   };
#   
# 
#   class Solution {
#     public:
#         vector<int> nextLargerNodes(ListNode* head) {
#             vector<int> nums;
#             for (ListNode* curr = head; curr; curr = curr->next) {
#                 nums.push_back(curr->val);
#             }
#     
#             int n = nums.size();
#             vector<int> ans(n, 0);
#             stack<int> st; // store indices of elements waiting for next greater
#     
#             for (int i = 0; i < n; i++) {
#                 // Pop all indices whose value is smaller than current value
#                 while (!st.empty() && nums[i] > nums[st.top()]) {
#                     ans[st.top()] = nums[i];
#                     st.pop();
#                 }
#                 st.push(i);
#             }
#     
#             return ans;
#         }
#     };
#     

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
