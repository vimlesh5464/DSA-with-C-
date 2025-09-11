#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert at end
    void insert(int val) {
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

    // Print linked list
    void printList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Create a loop for testing
    void createLoop(int pos) {
        if (pos == 0) return;
        Node* loopNode = head;
        for (int i = 1; i < pos && loopNode != NULL; i++) {
            loopNode = loopNode->next;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = loopNode; // last node points to loopNode
    }

    // Detect loop (Floyd’s cycle detection)
    bool detectLoop() {
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    // Remove loop
    void removeLoop() {
        if (head == NULL || head->next == NULL) return;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        // No loop
        if (slow != fast) return;

        // Step 2: Find start of loop
        slow = head;
        if (slow == fast) {
            // Special case: loop starts at head
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Break the loop
        fast->next = NULL;
    }
};

int main() {
    LinkedList list;

    // Insert nodes
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    // Create a loop (last node connects to node at position 2)
    list.createLoop(2);

    // Detect loop
    if (list.detectLoop())
        cout << "Loop detected!\n";
    else
        cout << "No loop detected!\n";

    // Remove loop
    list.removeLoop();

    // Detect loop again
    if (list.detectLoop())
        cout << "Loop still present!\n";
    else
        cout << "Loop removed successfully!\n";

    // Print list
    cout << "Linked List after removing loop:\n";
    list.printList();

    return 0;
}
