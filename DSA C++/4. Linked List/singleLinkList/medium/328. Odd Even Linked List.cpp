// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

// Example 1:

// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

// Example 2:

// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]

 

// Constraints:

//     The number of nodes in the linked list is in the range [0, 104].
//     -106 <= Node.val <= 106

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
    