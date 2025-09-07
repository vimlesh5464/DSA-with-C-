#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = next = child = NULL;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;
        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* next = curr->next;

                // Recursively flatten child list
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                // Move to the tail of the flattened child list
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // Connect tail to original next node
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};

// Helper function to print flattened list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Example usage
int main() {
    // Level 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    // Level 2 (child of node 2)
    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    head->next->child->next->prev = head->next->child;

    // Level 3 (child of node 5)
    head->next->child->next->child = new Node(6);

    Solution sol;
    Node* flat = sol.flatten(head);

    cout << "Flattened List: ";
    printList(flat);

    return 0;
}
