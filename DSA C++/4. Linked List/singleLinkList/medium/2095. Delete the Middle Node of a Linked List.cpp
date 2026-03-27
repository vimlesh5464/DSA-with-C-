// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

//     For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

 

// Example 1:

// Input: head = [1,3,4,7,1,2,6]
// Output: [1,3,4,1,2,6]
// Explanation:
// The above figure represents the given linked list. The indices of the nodes are written below.
// Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
// We return the new list after removing this node. 

// Example 2:

// Input: head = [1,2,3,4]
// Output: [1,2,4]
// Explanation:
// The above figure represents the given linked list.
// For n = 4, node 2 with value 3 is the middle node, which is marked in red.

// Example 3:

// Input: head = [2,1]
// Output: [2]
// Explanation:
// The above figure represents the given linked list.
// For n = 2, node 1 with value 1 is the middle node, which is marked in red.
// Node 0 with value 2 is the only node remaining after removing node 1.

 

// Constraints:

//     The number of nodes in the list is in the range [1, 105].
//     1 <= Node.val <= 105

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
      ListNode* deleteMiddle(ListNode* head) {
          if (!head || !head->next) return nullptr; // base case
          
          // Step 1: Copy all elements to a vector
          vector<int> ans;
          ListNode* temp = head;
          while (temp != nullptr) {
              ans.push_back(temp->val);
              temp = temp->next;
          }
  
          int mid = ans.size() / 2; // middle index
  
          // Step 2: Rebuild list without middle element
          ListNode* newHead = new ListNode(ans[0]);
          ListNode* curr = newHead;
  
          for (int i = 1; i < ans.size(); i++) {
              if (i == mid) continue; // skip middle element
              curr->next = new ListNode(ans[i]);
              curr = curr->next;
          }
  
          return newHead; // return new head
      }
  };

  class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
            // Case 1: Only one node
            if (head == NULL || head->next == NULL)
                return NULL;
    
            ListNode* slow = head;
            ListNode* fast = head->next->next;
    
            // Move fast by 2, slow by 1
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            // slow->next is middle node
            slow->next = slow->next->next;
    
            return head;
        }
    };
    
  