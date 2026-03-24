// Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

// Implement the Solution class:

//     Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
//     int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.

 

// Example 1:

// Input
// ["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
// [[[1, 2, 3]], [], [], [], [], []]
// Output
// [null, 1, 3, 2, 2, 3]

// Explanation
// Solution solution = new Solution([1, 2, 3]);
// solution.getRandom(); // return 1
// solution.getRandom(); // return 3
// solution.getRandom(); // return 2
// solution.getRandom(); // return 2
// solution.getRandom(); // return 3
// // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.

 

// Constraints:

//     The number of nodes in the linked list will be in the range [1, 104].
//     -104 <= Node.val <= 104
//     At most 104 calls will be made to getRandom.

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