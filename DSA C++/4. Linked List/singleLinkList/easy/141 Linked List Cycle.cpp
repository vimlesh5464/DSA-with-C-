// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

 

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:

// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

// Example 3:

// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.

 

// Constraints:

//     The number of the nodes in the list is in the range [0, 104].
//     -105 <= Node.val <= 105
//     pos is -1 or a valid index in the linked-list.

 

// Follow up: Can you solve it using O(1) (i.e. constant) memory?
//Floyd’s Cycle Detection
#include <iostream>
using namespace std;

// Linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to detect cycle
bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // move slow by 1
        fast = fast->next->next;     // move fast by 2

        if (slow == fast) {          // they meet => cycle exists
            return true;
        }
    }
    return false; // fast reached NULL => no cycle
}

// Helper function: Insert node at end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Print linked list (limited to avoid infinite loop if cycle exists)
void printList(Node* head, int limit = 20) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < limit) {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << (temp ? "..." : "NULL") << endl;
}

// Driver code
int main() {
    Node* head = NULL;

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    cout << "Linked List (before cycle): ";
    printList(head);

    cout << "Cycle detected? " << (detectCycle(head) ? "Yes" : "No") << endl;

    // Manually create a cycle: last node -> second node
    head->next->next->next->next->next = head->next;

    cout << "Linked List (with cycle, limited print): ";
    printList(head); // will print limited nodes to avoid infinite loop

    cout << "Cycle detected? " << (detectCycle(head) ? "Yes" : "No") << endl;

    return 0;
}
