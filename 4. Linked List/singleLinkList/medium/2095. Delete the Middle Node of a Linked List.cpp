#include <iostream>
#include<vector>
using namespace std;

// Linked list node structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) {
        val = val;
        next = NULL;
    }
};
class Solution {
  public:
      ListNode* deleteMiddle(ListNode* head) {
          if (!head || !head->next) return nullptr; // base case
          
          // Step 1: Copy all elements to a vector
          vector<int> ans;
          ListNode* temp = head;
          while (temp != nullptr) {
              ans.push_back(temp->val);
              temp = temp->next;
          }
  
          int mid = ans.size() / 2; // middle index
  
          // Step 2: Rebuild list without middle element
          ListNode* newHead = new ListNode(ans[0]);
          ListNode* curr = newHead;
  
          for (int i = 1; i < ans.size(); i++) {
              if (i == mid) continue; // skip middle element
              curr->next = new ListNode(ans[i]);
              curr = curr->next;
          }
  
          return newHead; // return new head
      }
  };

  class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
            // Case 1: Only one node
            if (head == NULL || head->next == NULL)
                return NULL;
    
            ListNode* slow = head;
            ListNode* fast = head->next->next;
    
            // Move fast by 2, slow by 1
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            // slow->next is middle node
            slow->next = slow->next->next;
    
            return head;
        }
    };
    
  