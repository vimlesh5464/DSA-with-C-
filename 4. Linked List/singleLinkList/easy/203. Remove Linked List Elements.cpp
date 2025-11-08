#include <iostream>
#include<vector>

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
        ListNode* removeElements(ListNode* head, int val) {
            vector<int> ans;
            ListNode* temp = head;
            while(temp!=NULL){
                if(temp->val!=val){
                ans.push_back(temp->val);
                }
                temp=temp->next;
            }
    
            
            if(ans.empty()){
                return NULL;
            }
            ListNode* temp2 = new ListNode(ans[0]);
            ListNode* temp1=temp2;
            for(int i = 1; i < ans.size(); i++){
                temp1->next=new ListNode(ans[i]);
                temp1=temp1->next;
            }
            return temp2;
        }
    };
    class Solution {
      public:
          ListNode* removeElements(ListNode* head, int val) {
              if(head==NULL){
                  return head;
              }
              while(head!=nullptr && head->val==val){
                  head = head->next;
              }
              ListNode* temp=head;
              ListNode* prev = NULL;
              while(temp!=NULL){
                  if(temp->val==val){
                      prev->next=temp->next;
                  }
                  else{
                      prev=temp;
                  }
                  temp=temp->next;
              }
              return head;
          }
      };

      class Solution {
        public:
            ListNode* removeElements(ListNode* head, int val) {
                // Create a dummy node to handle head deletions easily
                ListNode* dummy = new ListNode(0);
                dummy->next = head;
        
                ListNode* curr = dummy;
                while (curr->next != NULL) {
                    if (curr->next->val == val) {
                        // Remove the node by skipping it
                        curr->next = curr->next->next;
                    } else {
                        curr = curr->next;
                    }
                }
        
                return dummy->next; // Return the new head
            }
        };
        