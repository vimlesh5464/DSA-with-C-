#include <iostream>
using namespace std;

// Doubly linked list node
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = NULL;
    }

    // Insert at end (push)
    void push(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Remove from end (pop)
    void pop() {
        if (!tail) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }

    // Insert at specific position (1-based index)
    void insertAtPosition(int pos, int val) {
        if (pos <= 0) return;
        Node* newNode = new Node(val);

        if (pos == 1) { // insert at head
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = newNode;
            return;
        }

        Node* curr = head;
        for (int i = 1; i < pos - 1 && curr; i++) {
            curr = curr->next;
        }
        if (!curr) return; // position out of bounds

        newNode->next = curr->next;
        newNode->prev = curr;
        if (curr->next) curr->next->prev = newNode;
        curr->next = newNode;

        if (newNode->next == NULL) tail = newNode;
    }

    // Delete at specific position (1-based index)
    void deleteAtPosition(int pos) {
        if (!head || pos <= 0) return;
        Node* curr = head;

        if (pos == 1) { // delete head
            head = head->next;
            if (head) head->prev = NULL;
            else tail = NULL;
            delete curr;
            return;
        }

        for (int i = 1; i < pos && curr; i++) {
            curr = curr->next;
        }
        if (!curr) return; // position out of bounds

        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
        if (curr == tail) tail = curr->prev;

        delete curr;
    }

    // Print list
    void printList() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " <-> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.push(1);
    dll.push(2);
    dll.push(4);

    cout << "Original List: ";
    dll.printList(); // 1 <-> 2 <-> 4 <-> NULL

    dll.insertAtPosition(3, 3); // insert 3 at position 3
    cout << "After inserting 3 at position 3: ";
    dll.printList(); // 1 <-> 2 <-> 3 <-> 4 <-> NULL

    dll.pop();
    cout << "After pop: ";
    dll.printList(); // 1 <-> 2 <-> 3 <-> NULL

    dll.deleteAtPosition(2); // delete node at position 2
    cout << "After deleting position 2: ";
    dll.printList(); // 1 <-> 3 <-> NULL

    return 0;
}
