// Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

// The steps of the insertion sort algorithm:

//     Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
//     At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
//     It repeats until no input elements remain.

// The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

 

// Example 1:

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

// Example 2:

// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]

 

// Constraints:

//     The number of nodes in the list is in the range [1, 5000].
//     -5000 <= Node.val <= 5000

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
      ListNode* insertionSortList(ListNode* head) {
          if (head == NULL) return NULL;
  
          // Step 1: Copy to vector
          vector<int> arr;
          ListNode* temp = head;
          while (temp != NULL) {
              arr.push_back(temp->val);
              temp = temp->next;
          }
  
          // Step 2: Insertion sort
          for (int i = 1; i < arr.size(); i++) {
              int key = arr[i];
              int j = i - 1;
              while (j >= 0 && arr[j] > key) {
                  arr[j + 1] = arr[j];
                  j--;
              }
              arr[j + 1] = key;
          }
  
          // Step 3: Build sorted linked list
          ListNode* newHead = new ListNode(arr[0]);
          ListNode* curr = newHead;
          for (int i = 1; i < arr.size(); i++) {
              curr->next = new ListNode(arr[i]);
              curr = curr->next;
          }
  
          return newHead;
      }
  };

  class Solution {
    public:
        ListNode* insertionSortList(ListNode* head) {
            // Dummy node to help insert nodes easily
            ListNode* dummy = new ListNode(INT_MIN);
    
            while (head) {
                ListNode* next = head->next;  // Store next node
                ListNode* temp = dummy;
    
                // Find the correct position to insert current node
                while (temp->next && temp->next->val < head->val) {
                    temp = temp->next;
                }
    
                // Insert the node in the sorted part
                head->next = temp->next;
                temp->next = head;
    
                // Move to next node
                head = next;
            }
    
            return dummy->next;
        }
    };
    