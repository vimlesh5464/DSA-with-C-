
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
      vector<ListNode*> splitListToParts(ListNode* head, int k) {
          vector<ListNode*> ans(k, nullptr);
          int length = 0;
          ListNode* node = head;
  
          // Step 1: Find the total length of the linked list
          while (node) {
              length++;
              node = node->next;
          }
  
          // Step 2: Calculate base size and extras
          int size = length / k;
          int extra = length % k;
  
          node = head;
          for (int i = 0; i < k && node; i++) {
              ans[i] = node; // starting node of the current part
              ListNode* prev = NULL;
  
              // current size of this part (some parts may have +1 extra)
              int currentSize = size + (extra > 0 ? 1 : 0);
              if (extra > 0) extra--;
  
              // Move through current part
              for (int j = 0; j < currentSize; j++) {
                  prev = node;
                  node = node->next;
              }
  
              // Break the link
              if (prev) prev->next = NULL;
          }
  
          return ans;
      }
  };
  