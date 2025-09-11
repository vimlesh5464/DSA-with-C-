#include <iostream>
using namespace std;

// Linked list node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to insert node at the end
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

// Function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// ✅ Version 1: Return middle node pointer
Node* middleLinkedList(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // returns pointer to middle node
}

// ✅ Version 2: Return middle node data (int)
int middleLinkedListData(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data; // returns middle node data
}

// Driver code
int main() {
    Node* head = NULL;

    // Insert elements
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    cout << "Linked List: ";
    printList(head);

    // Using version 1
    Node* midNode = middleLinkedList(head);
    cout << "Middle node pointer -> data: " << midNode->data << endl;

    // Using version 2
    int midData = middleLinkedListData(head);
    cout << "Middle node data (int return): " << midData << endl;

    return 0;
}
