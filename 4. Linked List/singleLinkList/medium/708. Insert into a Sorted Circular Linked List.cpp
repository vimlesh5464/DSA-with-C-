
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
      ListNode* insert(ListNode* head, int data) {
          if (!head) {
              // Empty list → new node points to itself
              ListNode* newNode = new ListNode(data);
              newNode->next = newNode;
              return newNode;
          }
  
          // Step 1: Store all values in a vector
          vector<int> values;
          ListNode* curr = head;
          do {
              values.push_back(curr->val);
              curr = curr->next;
          } while (curr != head);
  
          // Step 2: Find index to insert
          int index = values.size(); // default end
          for (int i = 0; i < values.size(); i++) {
              if (data <= values[i]) {
                  index = i; // insert before equal/larger
                  break;
              }
          }
  
          // Step 3: Insert value in vector
          values.insert(values.begin() + index, data);
  
          // Step 4: Reconstruct circular linked list
          ListNode* newHead = new ListNode(values[0]);
          ListNode* node = newHead;
          for (int i = 1; i < values.size(); i++) {
              node->next = new ListNode(values[i]);
              node = node->next;
          }
          node->next = newHead; // circular link
  
          return newHead;
      }
  };
  