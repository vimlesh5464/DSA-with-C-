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
