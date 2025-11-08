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