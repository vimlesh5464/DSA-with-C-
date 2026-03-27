// Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.

// Example 1:

// Input:
// n = 6
// 1<->1<->1<->2<->3<->4
// Output:
// 1<->2<->3<->4
// Explanation:
// Only the first occurance of node with value 1 is 
// retained, rest nodes with value = 1 are deleted.

// Example 2:

// Input:
// n = 7
// 1<->2<->2<->3<->3<->4<->4
// Output:
// 1<->2<->3<->4
// Explanation:
// Only the first occurance of nodes with values 2,3 and 4 are 
// retained, rest repeating nodes are deleted.

// Your Task:
// You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list.  Your function should return a pointer to a linked list with no duplicate element.

// Constraint:
// 1 <= n <= 105
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)
#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        // If the list is empty, return null
        if (!head) return nullptr;

        Node* current = head;

        // Traverse the list until the second last node
        while (current != nullptr && current->next != nullptr) {
            Node* nextDistinct = current->next;

            // Skip and delete all nodes with the same value as current
            while (nextDistinct != nullptr && nextDistinct->data == current->data) {
                Node* duplicateNode = nextDistinct;
                nextDistinct = nextDistinct->next;
                delete duplicateNode; // Free memory of duplicate node
            }

            // Connect current node to the next distinct node
            current->next = nextDistinct;
            if (nextDistinct != nullptr) {
                nextDistinct->prev = current;
            }

            // Move to the next node
            current = current->next;
        }

        // Return the updated head of the list
        return head;
    }
};