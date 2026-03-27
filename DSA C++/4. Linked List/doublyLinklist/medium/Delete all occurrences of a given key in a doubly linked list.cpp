// You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.

// Example1:

// Input: 
// 2<->2<->10<->8<->4<->2<->5<->2
// 2
// Output: 
// 10<->8<->4<->5
// Explanation: 
// All Occurences of 2 have been deleted.

// Example2:

// Input: 
// 9<->1<->3<->4<->5<->1<->8<->4
// 9
// Output: 
// 1<->3<->4<->5<->1<->8<->4
// Explanation: 
// All Occurences of 9 have been deleted.

// Your Task:

// Complete the function void deleteAllOccurOfX(struct Node** head_ref, int key), which takes the reference of the head pointer and an integer value key. Delete all occurrences of the key from the given DLL.

// Expected Time Complexity: O(N).

// Expected Auxiliary Space: O(1).

// Constraints:

// 1<=Number of Nodes<=105

// 0<=Node Value <=109
#include <iostream>
using namespace std;

// Structure for a Doubly Linked List node
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    void deleteAllOccurOfX(Node** head_ref, int x) {
        Node* temp = *head_ref;

        while (temp != NULL) {
            if (temp->data == x) {

                // If deleting the head node
                if (temp == *head_ref) {
                  *head_ref=(*head_ref)->next;
                }
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;

                // Fix links for next and prev nodes
                if (nextNode != NULL)
                    nextNode->prev = prevNode;

                if (prevNode != NULL)
                    prevNode->next = nextNode;

                delete temp; // safely delete current node
                temp = nextNode; // move to the next node
            } else {
                temp = temp->next; // move ahead
            }
        }
    }
};

// Helper functions for demonstration
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Main function (for testing)
int main() {
    Node* head = NULL;

    // Create list: 1 <-> 2 <-> 3 <-> 2 <-> 4
    push(&head, 4);
    push(&head, 2);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Original list: ";
    printList(head);

    Solution obj;
    int x = 2;
    obj.deleteAllOccurOfX(&head, x);

    cout << "List after deleting " << x << ": ";
    printList(head);

    return 0;
}
