# 25. Reverse Nodes in k-Group.py - Python skeleton converted from C++

# Original C++ code:
# // Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
# 
# // k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
# 
# // You may not alter the values in the list's nodes, only nodes themselves may be changed.
# 
#  
# 
# // Example 1:
# 
# // Input: head = [1,2,3,4,5], k = 2
# // Output: [2,1,4,3,5]
# 
# // Example 2:
# 
# // Input: head = [1,2,3,4,5], k = 3
# // Output: [3,2,1,4,5]
# 
#  
# 
# // Constraints:
# 
# //     The number of nodes in the list is n.
# //     1 <= k <= n <= 5000
# //     0 <= Node.val <= 1000
# 
#  
# 
# // Follow-up: Can you solve the problem in O(1) extra memory space?
# #include <iostream>
# using namespace std;
# 
# // Definition for singly-linked list
# struct ListNode {
#     int val;
#     ListNode* next;
#     ListNode(int x) : val(x), next(nullptr) {}
# };
# 
# class Solution {
# public:
#     // Helper to get the k-th node from 'start'
#     ListNode* getKthNode(ListNode* start, int k) {
#         while (start && --k) {
#             start = start->next;
#         }
#         return start;
#     }
# 
#     ListNode* reverseKGroup(ListNode* head, int k) {
#         if (!head || k == 1) return head;
# 
#         ListNode dummy(0);
#         dummy.next = head;
#         ListNode* groupPrev = &dummy;
# 
#         while (true) {
#             // Get the k-th node from the current group
#             ListNode* kth = getKthNode(groupPrev->next, k);
#             if (!kth) break;
# 
#             ListNode* groupNext = kth->next;
# 
#             // Reverse the k-group
#             ListNode* prev = groupNext;
#             ListNode* curr = groupPrev->next;
#             while (curr != groupNext) {
#                 ListNode* tmp = curr->next;
#                 curr->next = prev;
#                 prev = curr;
#                 curr = tmp;
#             }
# 
#             // Connect previous group to the reversed group
#             ListNode* tmp = groupPrev->next;
#             groupPrev->next = kth;
#             groupPrev = tmp;
#         }
# 
#         return dummy.next;
#     }
# };
# 
# // Helper function to create linked list from array
# ListNode* createList(int arr[], int n) {
#     if (n == 0) return nullptr;
#     ListNode* head = new ListNode(arr[0]);
#     ListNode* curr = head;
#     for (int i = 1; i < n; i++) {
#         curr->next = new ListNode(arr[i]);
#         curr = curr->next;
#     }
#     return head;
# }
# 
# // Helper function to print linked list
# void printList(ListNode* head) {
#     while (head) {
#         cout << head->val << " -> ";
#         head = head->next;
#     }
#     cout << "NULL" << endl;
# }
# 
# int main() {
#     int arr[] = {1, 2, 3, 4, 5, 6, 7};
#     ListNode* head = createList(arr, 7);
# 
#     cout << "Original List: ";
#     printList(head);
# 
#     Solution sol;
#     head = sol.reverseKGroup(head, 3);
# 
#     cout << "Reversed in groups of 3: ";
#     printList(head);
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
