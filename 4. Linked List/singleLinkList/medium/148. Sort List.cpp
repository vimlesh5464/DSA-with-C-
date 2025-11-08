
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
      ListNode* sortList(ListNode* head) {
          if(!head){
              return NULL;
          }
          ListNode* temp = head;
          vector<int> ans;
          while(temp!=NULL){
              ans.push_back(temp->val);
              temp =temp->next;
          }
          sort(ans.begin(),ans.end());
          ListNode* temp1=new ListNode(ans[0]);
          ListNode* curr= temp1;
          for(int i =1; i < ans.size(); i++){
              curr->next=new ListNode(ans[i]);
              curr=curr->next;
          }
          return temp1;
      }
  };