// You are given the head of a doubly linked list. You have to reverse the doubly linked list and return its head.

// Examples:

// Input:
   
// Output: 5 <-> 4 <-> 3
// Explanation: After reversing the given doubly linked list the new list will be 5 <-> 4 <-> 3.
   

// Input: 
   
// Output: 196 <-> 59 <-> 122 <-> 75
// Explanation: After reversing the given doubly linked list the new list will be 196 <-> 59 <-> 122 <-> 75.
   

// Constraints:
// 1 ≤ number of nodes ≤ 106
// 0 ≤ node->data ≤ 104

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node *reverse(Node *curr) { 
  
    // Base case: if the list is empty or we
  	// reach the end of the list
    if (curr == nullptr)
        return nullptr;

    swap(curr->prev, curr->next);

    // If the previous node (after swap) is null,
  	// this is the new head
    if (curr->prev == nullptr)
        return curr;

    return reverse(curr->prev);
}

Node *reverse(Node *head) {

  // If the list is empty or has only one node,
  // return the head as is
  if (head == nullptr || head->next == nullptr)
      return head;

  Node *prevNode = NULL;
  Node *currNode = head;

  // Traverse the list and reverse the links
  while (currNode != nullptr) {
    
      // Swap the next and prev pointers
      prevNode = currNode->prev;
      currNode->prev = currNode->next;
      currNode->next = prevNode;
    
      // Move to the next node in the original list 
      // (which is now previous due to reversal)
      currNode = currNode->prev;
  }

  return prevNode->prev;
}
void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data;
        if(node->next != nullptr){
            cout << " <-> ";
        }
        node = node->next;
    }
}

int main() {
  
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head = reverse(head);
    printList(head);

    return 0;
}