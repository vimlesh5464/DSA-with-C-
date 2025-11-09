#include <iostream>
#include<vector>
#include<stack>
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
      vector<int> nextLargerNodes(ListNode* head) {
          // Step 1: Convert linked list to array
          vector<int> nums;
          ListNode* temp = head;
          while (temp) {
              nums.push_back(temp->val);
              temp = temp->next;
          }
  
          int n = nums.size();
          vector<int> ans(n, 0);
          stack<int> st; // store indices
  
          // Step 2: Traverse from right to left
          for (int i = n - 1; i >= 0; i--) {
              // Pop all smaller or equal elements
              while (!st.empty() && nums[st.top()] <= nums[i]) {
                  st.pop();
              }
  
              // If stack not empty, top is next greater
              if (!st.empty()) {
                  ans[i] = nums[st.top()];
              }
  
              // Push current index
              st.push(i);
          }
  
          return ans;
      }
  };
  

  class Solution {
    public:
        vector<int> nextLargerNodes(ListNode* head) {
            vector<int> nums;
            for (ListNode* curr = head; curr; curr = curr->next) {
                nums.push_back(curr->val);
            }
    
            int n = nums.size();
            vector<int> ans(n, 0);
            stack<int> st; // store indices of elements waiting for next greater
    
            for (int i = 0; i < n; i++) {
                // Pop all indices whose value is smaller than current value
                while (!st.empty() && nums[i] > nums[st.top()]) {
                    ans[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
    
            return ans;
        }
    };
    