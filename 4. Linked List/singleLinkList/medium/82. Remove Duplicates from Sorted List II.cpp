#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
  public:
      ListNode* deleteDuplicates(ListNode* head) {
          if (!head) return nullptr;
          
          // Step 1: Store all values
          vector<int> ans;
          ListNode* temp = head;
          while(temp != nullptr){
              ans.push_back(temp->val);
              temp = temp->next;
          }
  
          // Step 2: Count frequencies
          unordered_map<int, int> freq;
          for (int val : ans) {
              freq[val]++;
          }
  
          // Step 3: Keep only elements with frequency 1
          vector<int> uniqueVals;
          for (int val : ans) {
              if (freq[val] == 1) {
                  uniqueVals.push_back(val);
              }
          }
  
          // Step 4: Build the new linked list
          if (uniqueVals.empty()) return nullptr;  // No unique elements
  
          ListNode* newHead = new ListNode(uniqueVals[0]);
          ListNode* curr = newHead;
          for (int i = 1; i < uniqueVals.size(); i++) {
              curr->next = new ListNode(uniqueVals[i]);
              curr = curr->next;
          }
  
          return newHead;
      }
  };
  class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if (!head) return NULL;
    
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
    
            ListNode* prev = dummy;  
            ListNode* curr = head;
    
            while (curr) {
                // Check if this value occurs more than once
                if (curr->next && curr->val == curr->next->val) {
                    
                    // Skip all nodes with this value
                    while (curr->next && curr->val == curr->next->val) {
                        curr = curr->next;
                    }
    
                    // Skip the last duplicate
                    prev->next = curr->next;
                } 
                else {
                    prev = prev->next;  // value was unique
                }
                curr = curr->next;
            }
    
            return dummy->next;
        }
    };
    