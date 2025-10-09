
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
      void reorderList(ListNode* head) {
          if (!head || !head->next) return;
  
          // Step 1: Find the middle
          ListNode* slow = head;
          ListNode* fast = head;
          while (fast->next && fast->next->next) {
              slow = slow->next;
              fast = fast->next->next;
          }
  
          // Step 2: Reverse the second half
          ListNode* prev = nullptr;
          ListNode* curr = slow->next;
          while (curr) {
              ListNode* nextTemp = curr->next;
              curr->next = prev;
              prev = curr;
              curr = nextTemp;
          }
          slow->next = nullptr; // split the list
  
          // Step 3: Merge two halves
          ListNode* first = head;
          ListNode* second = prev;
          while (second) {
              ListNode* tmp1 = first->next;
              ListNode* tmp2 = second->next;
  
              first->next = second;
              second->next = tmp1;
  
              first = tmp1;
              second = tmp2;
          }
      }
  };
  