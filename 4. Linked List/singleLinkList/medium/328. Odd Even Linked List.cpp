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
      ListNode* oddEvenList(ListNode* head) {
          if(!head){
              return NULL;
          }
          vector<int> ans;
          ListNode* temp = head;
          while(temp!=NULL){
              ans.push_back(temp->val);
              temp=temp->next;
          }
          vector<int> list;
           // First add odd-indexed nodes (1st, 3rd, 5th, ...)
          for (int i = 0; i < ans.size(); i += 2) {
              list.push_back(ans[i]);
          }
          // Then add even-indexed nodes (2nd, 4th, 6th, ...)
          for (int i = 1; i < ans.size(); i += 2) {
              list.push_back(ans[i]);
          }
          ListNode* curr=new ListNode(list[0]);
          ListNode* curr1=curr;
          for(int i =1; i < list.size(); i++){
              curr1->next=new ListNode(list[i]);
              curr1=curr1->next;
          }
          return curr;
      }
  };
  class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            if (!head || !head->next) return head;
    
            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* evenHead = even; // store start of even list
    
            while (even && even->next) {
                odd->next = even->next;
                odd = odd->next;
                even->next = odd->next;
                even = even->next;
            }
    
            odd->next = evenHead; // connect odd and even parts
            return head;
        }
    };
    