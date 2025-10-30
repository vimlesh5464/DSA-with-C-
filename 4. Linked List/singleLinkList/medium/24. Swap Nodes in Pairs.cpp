#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
      ListNode* swapPairs(ListNode* head) {
          if (head == NULL || head->next == NULL) return head;
  
          ListNode* first = head;
          ListNode* second = head->next;
          ListNode* prev = NULL;
  
          while (first != NULL && second != NULL) {
              ListNode* third = second->next;
  
              // Swap
              second->next = first;
              first->next = third;
  
              if (prev != NULL) {
                  prev->next = second;
              } else {
                  head = second; // Update head after first swap
              }
  
              // Move pointers
              prev = first;
              first = third;
              if (third != NULL) second = third->next;
              else second = NULL;
          }
  
          return head;
      }
  };
  