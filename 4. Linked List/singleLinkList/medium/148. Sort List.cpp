// Given the head of a linked list, return the list after sorting it in ascending order.

 

// Example 1:

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

// Example 2:

// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]

// Example 3:

// Input: head = []
// Output: []

 

// Constraints:

//     The number of nodes in the list is in the range [0, 5 * 104].
//     -105 <= Node.val <= 105

 

// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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