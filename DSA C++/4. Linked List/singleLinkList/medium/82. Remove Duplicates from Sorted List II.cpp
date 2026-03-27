// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

// Example 2:

// Input: head = [1,1,1,2,3]
// Output: [2,3]

 

// Constraints:

//     The number of nodes in the list is in the range [0, 300].
//     -100 <= Node.val <= 100
//     The list is guaranteed to be sorted in ascending order.

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
    