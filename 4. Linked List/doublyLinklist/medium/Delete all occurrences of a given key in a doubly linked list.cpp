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
