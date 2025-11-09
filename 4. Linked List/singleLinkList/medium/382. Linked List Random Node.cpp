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
  private:
      ListNode* head;  // Pointer to the head of the linked list
  public:
      // Constructor: store the head of the linked list
      Solution(ListNode* head) {
          this->head = head;
      }
      
      // Returns a random node's value
      int getRandom() {
          int result = head->val; // Start with head value as initial result
          ListNode* node = head->next; // Start traversing from the second node
          int n = 2; // Counter for the current node (used for probability calculation)
          
          while (node) {
              // Replace the result with current node's value with probability 1/n
              // rand() % n gives a number between 0 to n-1, so 0 means we pick current node
              if (rand() % n == 0) { 
                  result = node->val;
              }
              node = node->next; // Move to next node
              n++; // Increment node counter
          }
          
          return result; // Return the randomly selected node value
      }
  };