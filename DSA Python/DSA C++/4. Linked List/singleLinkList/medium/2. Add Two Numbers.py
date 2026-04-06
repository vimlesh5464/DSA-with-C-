# 2. Add Two Numbers.py - Python skeleton converted from C++

# Original C++ code:
# // You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
# 
# // You may assume the two numbers do not contain any leading zero, except the number 0 itself.
# 
#  
# 
# // Example 1:
# 
# // Input: l1 = [2,4,3], l2 = [5,6,4]
# // Output: [7,0,8]
# // Explanation: 342 + 465 = 807.
# 
# // Example 2:
# 
# // Input: l1 = [0], l2 = [0]
# // Output: [0]
# 
# // Example 3:
# 
# // Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
# // Output: [8,9,9,9,0,0,0,1]
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
# #include <iostream>
# using namespace std;
# 
# // Definition for singly-linked list
# struct ListNode {
#     int val;
#     ListNode *next;
#     ListNode() : val(0), next(nullptr) {}
#     ListNode(int x) : val(x), next(nullptr) {}
# };
# 
# class Solution {
# public:
#     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
#         ListNode *dummy = new ListNode(); 
#         ListNode *temp = dummy; 
#         int carry = 0;
# 
#         while (l1 != NULL || l2 != NULL || carry) {
#             int sum = carry; 
# 
#             if (l1 != NULL) {
#                 sum += l1->val; 
#                 l1 = l1->next; 
#             }
# 
#             if (l2 != NULL) {
#                 sum += l2->val; 
#                 l2 = l2->next; 
#             }
# 
#             carry = sum / 10; 
#             temp->next = new ListNode(sum % 10); 
#             temp = temp->next; 
#         }
# 
#         return dummy->next; 
#     }
# };
# 
# // Helper function to create list from array
# ListNode* createList(int arr[], int n) {
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
#     int arr1[] = {2, 4, 3}; // 342
#     int arr2[] = {5, 6, 4}; // 465
# 
#     ListNode* l1 = createList(arr1, 3);
#     ListNode* l2 = createList(arr2, 3);
# 
#     Solution sol;
#     ListNode* result = sol.addTwoNumbers(l1, l2);
# 
#     cout << "Result List: ";
#     printList(result); // Expected: 7 -> 0 -> 8 -> NULL (807)
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
