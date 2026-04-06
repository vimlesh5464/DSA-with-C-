# 206 reverseLinkList.py - Python skeleton converted from C++

# Original C++ code:
# // Given the head of a singly linked list, reverse the list, and return the reversed list.
# 
#  
# 
# // Example 1:
# 
# // Input: head = [1,2,3,4,5]
# // Output: [5,4,3,2,1]
# 
# // Example 2:
# 
# // Input: head = [1,2]
# // Output: [2,1]
# 
# // Example 3:
# 
# // Input: head = []
# // Output: []
# 
#  
# 
# // Constraints:
# 
# //     The number of nodes in the list is the range [0, 5000].
# //     -5000 <= Node.val <= 5000
# 
#  
# 
# // Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
# #include <iostream>
# #include<vector>
# using namespace std;
# 
# // Node definition
# struct ListNode {
#     int val;
#     ListNode* next;
# 
#     ListNode(int val) {
#         val = val;
#         next = nullptr;
#     }
# };
# 
# // Function to reverse the linked list
# ListNode* reverse(ListNode* root) {
#   ListNode* prev = nullptr;
#   ListNode* curr = root;
#     while (curr != nullptr) {
#       ListNode* next = curr->next;
#         curr->next = prev;
#         prev = curr;
#         curr = next;
#     }
#     return prev; // new head
# }
# 
# // ------------------------------------------------------------
# // Reverse Linked List using vector
# // ------------------------------------------------------------
# class Solution {
# public:
#     ListNode* reverseList(ListNode* head) {
#         if (!head) return head;
# 
#         vector<int> arr;
#         ListNode* temp = head;
# 
#         // Step 1: Copy values into vector
#         while (temp) {
#             arr.push_back(temp->val);
#             temp = temp->next;
#         }
# 
#         // Step 2: Reverse the vector
#         reverse(arr.begin(), arr.end());
# 
#         // Step 3: Put values back into linked list
#         ListNode* temp1 = new ListNode(arr[0]);
#           ListNode* curr = temp1;
#           for(int i = 1; i < arr.size(); i++){
#               curr->next = new ListNode(arr[i]);
#               curr = curr->next;
#           }
#           return temp1;
#     }
# };
# 
# // ------------------------------------------------------------
# // Linked List Helper Functions
# // ------------------------------------------------------------
# ListNode* createList(vector<int>& arr) {
#     if (arr.empty()) return NULL;
#     ListNode* head = new ListNode(arr[0]);
#     ListNode* temp = head;
# 
#     for (int i = 1; i < arr.size(); i++) {
#         temp->next = new ListNode(arr[i]);
#         temp = temp->next;
#     }
#     return head;
# }
# 
# void printList(ListNode* head) {
#     while (head) {
#         cout << head->val;
#         if (head->next) cout << " ";
#         head = head->next;
#     }
#     cout << "\n";
# }
# 
# // ------------------------------------------------------------
# // MAIN PROGRAM
# // ------------------------------------------------------------
# int main() {
#     int n;
#     cin >> n;
# 
#     vector<int> arr(n);
#     for (int i = 0; i < n; i++) cin >> arr[i];
# 
#     ListNode* head = createList(arr);
# 
#     Solution sol;
#     head = sol.reverseList(head);
# 
#     printList(head);
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
