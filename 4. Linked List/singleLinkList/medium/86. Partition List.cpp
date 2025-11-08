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
      ListNode* partition(ListNode* head, int x) {
          if (head == NULL) return NULL;
  
          vector<int> less, greater;
          ListNode* temp = head;
  
          // Step 1: Store values
          while (temp != NULL) {
              if (temp->val < x)
                  less.push_back(temp->val);
              else
                  greater.push_back(temp->val);
              temp = temp->next;
          }
  
          // Step 2: Combine two parts
          vector<int> ans;
          for (int v : less) ans.push_back(v);
          for (int v : greater) ans.push_back(v);
  
          // Step 3: Rebuild linked list
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
  

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes for two lists
        ListNode* beforeHead = new ListNode(0);
        ListNode* afterHead = new ListNode(0);
        
        ListNode* before = beforeHead;
        ListNode* after = afterHead;

        // Traverse and separate
        while (head) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }

        // Terminate 'after' list
        after->next = nullptr;

        // Connect both lists
        before->next = afterHead->next;

        // Return new head
        return beforeHead->next;
    }
};
