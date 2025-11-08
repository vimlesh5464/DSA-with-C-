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
    