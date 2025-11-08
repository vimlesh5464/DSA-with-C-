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
      ListNode* deleteDuplicates(ListNode* head) {
          if (!head) return nullptr;
          
          ListNode* temp = head;
          vector<int> ans;
          while(temp!=NULL){
              ans.push_back(temp->val);
              temp=temp->next;
          }
          unordered_set<int> s;
          int idx = 0;  
  
          for (int i = 0; i < ans.size(); i++) {
              if (s.find(ans[i]) == s.end()) { 
                  s.insert(ans[i]);  
                  ans[idx++] = ans[i];  
              }
          }
      
          ListNode* temp1 = new ListNode(ans[0]);
          ListNode* curr = temp1;
          for(int i = 1; i < idx; i++){
              curr->next = new ListNode(ans[i]);
              curr = curr->next;
          }
          return temp1;
      }
  };

  