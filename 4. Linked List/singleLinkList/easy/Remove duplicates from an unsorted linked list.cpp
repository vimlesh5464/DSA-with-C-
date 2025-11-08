#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// Linked list node
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
      ListNode* removeDuplicates(ListNode* head) {
          if (head == NULL) return NULL;
  
          unordered_set<int> seen;
          ListNode* curr = head;
          ListNode* prev = NULL;
  
          while (curr != NULL) {
              if (seen.find(curr->val) != seen.end()) {
                  // Duplicate found → remove node
                  prev->next = curr->next;
              } else {
                  seen.insert(curr->val);
                  prev = curr;
              }
              curr = curr->next;
          }
  
          return head;
      }
  };
  
  class Solution {
    public:
        ListNode* removeDuplicates(ListNode* head) {
            if (head == NULL) return NULL;
    
            ListNode* temp = head;
            unordered_set<int> s;
            vector<int> ans;
    
            while (temp != NULL) {
                if (s.find(temp->val) == s.end()) { // not seen before
                    s.insert(temp->val);
                    ans.push_back(temp->val);
                }
                temp = temp->next;
            }
    
            // If no unique elements, return NULL
            if (ans.empty()) return NULL;
    
            ListNode* newHead = new ListNode(ans[0]);
            ListNode* curr = newHead;
            for (int i = 1; i < ans.size(); i++) {
                curr->next = new ListNode(ans[i]);
                curr = curr->next;
            }
    
            return newHead;
        }
    };