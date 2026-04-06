# 445. Add Two Numbers II.py - Python skeleton converted from C++

# Original C++ code:
# // You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
# 
# // You may assume the two numbers do not contain any leading zero, except the number 0 itself.
# 
#  
# 
# // Example 1:
# 
# // Input: l1 = [7,2,4,3], l2 = [5,6,4]
# // Output: [7,8,0,7]
# 
# // Example 2:
# 
# // Input: l1 = [2,4,3], l2 = [5,6,4]
# // Output: [8,0,7]
# 
# // Example 3:
# 
# // Input: l1 = [0], l2 = [0]
# // Output: [0]
# 
#  
# 
# // Constraints:
# 
# //     The number of nodes in each linked list is in the range [1, 100].
# //     0 <= Node.val <= 9
# //     It is guaranteed that the list represents a number that does not have leading zeros.
# 
#  
# 
# // Follow up: Could you solve it without reversing the input lists?
# #include <iostream>
# #include<vector>
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
# 
# class Solution {
#   public:
#       ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
#           vector<int> v1, v2;
#   
#           // Step 1: Convert both lists to vectors
#           while (l1) {
#               v1.push_back(l1->val);
#               l1 = l1->next;
#           }
#           while (l2) {
#               v2.push_back(l2->val);
#               l2 = l2->next;
#           }
#   
#           // Step 2: Traverse from back to front
#           int i = v1.size() - 1;
#           int j = v2.size() - 1;
#           int carry = 0;
#           vector<int> res;
#   
#           while (i >= 0 || j >= 0 || carry) {
#               int sum = carry;
#               if (i >= 0) sum += v1[i--];
#               if (j >= 0) sum += v2[j--];
#   
#               res.push_back(sum % 10);
#               carry = sum / 10;
#           }
#   
#           // Step 3: Build linked list from reversed result
#           reverse(res.begin(), res.end());
#           ListNode* dummy = new ListNode(0);
#           ListNode* curr = dummy;
#   
#           for (int num : res) {
#               curr->next = new ListNode(num);
#               curr = curr->next;
#           }
#   
#           return dummy->next;
#       }
#   };
# 
#   class Solution {
#     public:
#         // Helper: reverse a linked list
#         ListNode* reverseList(ListNode* head) {
#             ListNode* prev = nullptr;
#             while (head) {
#                 ListNode* nextNode = head->next;
#                 head->next = prev;
#                 prev = head;
#                 head = nextNode;
#             }
#             return prev;
#         }
#     
#         ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
#             // Step 1: Reverse both lists
#             l1 = reverseList(l1);
#             l2 = reverseList(l2);
#     
#             // Step 2: Add the numbers
#             int carry = 0;
#             ListNode* head = nullptr;
#     
#             while (l1 || l2 || carry) {
#                 int sum = carry;
#                 if (l1) {
#                     sum += l1->val;
#                     l1 = l1->next;
#                 }
#                 if (l2) {
#                     sum += l2->val;
#                     l2 = l2->next;
#                 }
#     
#                 // Create new node with sum%10
#                 ListNode* newNode = new ListNode(sum % 10);
#                 newNode->next = head;  // prepend to the result list
#                 head = newNode;
#     
#                 carry = sum / 10;
#             }
#     
#             // Step 3: Reverse result before returning
#             return head; // already built in reverse order by prepending
#         }
#     };
#     

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
