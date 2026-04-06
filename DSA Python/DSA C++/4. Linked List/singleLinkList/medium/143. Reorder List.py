# 143. Reorder List.py - Python skeleton converted from C++

# Original C++ code:
# // You are given the head of a singly linked-list. The list can be represented as:
# 
# // L0 → L1 → … → Ln - 1 → Ln
# 
# // Reorder the list to be on the following form:
# 
# // L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
# 
# // You may not modify the values in the list's nodes. Only nodes themselves may be changed.
# 
#  
# 
# // Example 1:
# 
# // Input: head = [1,2,3,4]
# // Output: [1,4,2,3]
# 
# // Example 2:
# 
# // Input: head = [1,2,3,4,5]
# // Output: [1,5,2,4,3]
# 
#  
# 
# // Constraints:
# 
# //     The number of nodes in the list is in the range [1, 5 * 104].
# //     1 <= Node.val <= 1000
# 
#  
# #include <iostream>
# using namespace std;
# 
# // Linked list node structure
# struct ListNode {
#     int data;
#     ListNode* next;
#     ListNode(int val) {
#         data = val;
#         next = NULL;
#     }
# };
# 
# class Solution {
#   public:
#       void reorderList(ListNode* head) {
#           if (!head || !head->next) return;
#   
#           // Step 1: Find the middle
#           ListNode* slow = head;
#           ListNode* fast = head;
#           while (fast->next && fast->next->next) {
#               slow = slow->next;
#               fast = fast->next->next;
#           }
#   
#           // Step 2: Reverse the second half
#           ListNode* prev = nullptr;
#           ListNode* curr = slow->next;
#           while (curr) {
#               ListNode* nextTemp = curr->next;
#               curr->next = prev;
#               prev = curr;
#               curr = nextTemp;
#           }
#           slow->next = nullptr; // split the list
#   
#           // Step 3: Merge two halves
#           ListNode* first = head;
#           ListNode* second = prev;
#           while (second) {
#               ListNode* tmp1 = first->next;
#               ListNode* tmp2 = second->next;
#   
#               first->next = second;
#               second->next = tmp1;
#   
#               first = tmp1;
#               second = tmp2;
#           }
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
