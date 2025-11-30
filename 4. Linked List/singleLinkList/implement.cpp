#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at end
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

// Reverse linked list
Node* reverseList(Node* head) {
    Node *prev = NULL, *curr = head, *nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next; // store next
        curr->next = prev;     // reverse link
        prev = curr;           // move prev forward
        curr = nextNode;       // move curr forward
    }
    return prev;
}

// Print list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    int n;
    cin >> n;       // number of nodes

    Node* head = NULL;

    // Input values
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(head, x);
    }

    // Reverse the list
    head = reverseList(head);

    // Print reversed list
    printList(head);

    return 0;
}
