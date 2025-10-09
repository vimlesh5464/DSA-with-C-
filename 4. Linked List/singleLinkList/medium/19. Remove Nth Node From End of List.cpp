#include <iostream>
using namespace std;

// Linked list node structure
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
      int getsize(ListNode* head) {
          int sz = 0;
          while (head != NULL) {
              head = head->next;
              sz++;
          }
          return sz;
      }
  
      ListNode* removeNthFromEnd(ListNode* head, int n) {
          int size = getsize(head);
  
          // If the head node is to be deleted
          if (n == size) {
              ListNode* temp = head;
              head = head->next;
              delete temp;
              return head;
          }
  
          // Find the node before the one to delete
          ListNode* prev = head;
          for (int i = 0; i < size - n - 1; i++) {
              prev = prev->next;
          }
  
          ListNode* toDelete = prev->next;
          prev->next = prev->next->next;
          delete toDelete;
  
          return head;
      }
  };
  
//approach 2

class Solution {
  public:
      ListNode* removeNthFromEnd(ListNode* head, int n) {
          ListNode* dummy = new ListNode(0);
          dummy->next = head;
          ListNode* fast = dummy;
          ListNode* slow = dummy;
  
          // Move fast ahead by n+1 steps
          for (int i = 0; i <= n; i++) {
              fast = fast->next;
          }
  
          // Move fast to the end, slow will be just before the target
          while (fast != nullptr) {
              fast = fast->next;
              slow = slow->next;
          }
  
          // Remove the nth node
          //ListNode* nodeToDelete = slow->next;
          slow->next = slow->next->next;
          //delete nodeToDelete; // free memory
  
          return dummy->next;
      }
  };
  