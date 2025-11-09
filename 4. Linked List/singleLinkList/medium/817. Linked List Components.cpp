#include <iostream>
#include<vector>
#include<unordered_set>
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
      int numComponents(ListNode* head, vector<int>& nums) {
          // Step 1: Store nums in unordered_set for O(1) lookups
          unordered_set<int> s(nums.begin(), nums.end());
          
          int count = 0;
          ListNode* curr = head;
          
          // Step 2: Traverse the linked list
          while (curr) {
              // Check if current node is part of nums
              if (s.count(curr->val)) {
                  // If next node is null OR next node not in nums => component ends
                  if (!curr->next || !s.count(curr->next->val)) {
                      count++;
                  }
              }
              curr = curr->next;
          }
          
          return count;
      }
  };
  