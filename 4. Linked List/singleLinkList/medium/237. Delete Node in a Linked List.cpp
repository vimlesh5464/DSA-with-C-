#include <iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
      void deleteNode(ListNode* node) {
          if (node == nullptr || node->next == nullptr)
              return; // Can't delete last or null node
  
          // Copy next node's value to current node
          node->val = node->next->val;
  
          // Remove next node
          ListNode* temp = node->next;
          node->next = node->next->next;
          delete temp;
      }
  };
  
  class Solution {
    public:
        ListNode* deleteNodeByValue(ListNode* head, int val) {
            if (!head) return nullptr;
    
            // If deleting the head node
            if (head->val == val) {
                ListNode* temp = head;
                head = head->next;
                delete temp;
                return head;
            }
    
            ListNode* curr = head;
            while (curr->next && curr->next->val != val) {
                curr = curr->next;
            }
    
            if (!curr->next) return head; // Value not found
    
            ListNode* nodeToDelete = curr->next;
            curr->next = curr->next->next;
            delete nodeToDelete;
    
            return head;
        }
    };
    