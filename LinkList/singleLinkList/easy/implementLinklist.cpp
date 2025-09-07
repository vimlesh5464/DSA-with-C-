#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Push at beginning
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Pop from beginning
    void pop() {
        if (head == nullptr) {
            cout << "List is empty. Cannot pop.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Popped: " << temp->data << endl;
        delete temp;
    }

    // Insert at specific position (0-based index)
    void insertAt(int val, int pos) {
        Node* newNode = new Node(val);

        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of range\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete node at specific position (0-based index)
    void deleteAt(int pos) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        if (pos == 0) {
            head = head->next;
            cout << "Deleted: " << temp->data << endl;
            delete temp;
            return;
        }

        for (int i = 0; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        cout << "Deleted: " << nodeToDelete->data << endl;
        delete nodeToDelete;
    }

    // Insert in the middle
    void insertMiddle(int val) {
        if (head == nullptr) {
            head = new Node(val);
            return;
        }

        // Count length
        int len = 0;
        Node* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        int mid = len / 2;

        temp = head;
        for (int i = 0; i < mid - 1; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Print the list
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Driver code
int main() {
    LinkedList list;

    // Push elements
    list.push(10);
    list.push(20);
    list.push(30);
    cout << "After push: ";
    list.print();   // 30 -> 20 -> 10 -> NULL

    // Pop element
    list.pop();
    cout << "After pop: ";
    list.print();   // 20 -> 10 -> NULL

    // Insert at specific position
    list.insertAt(25, 1);
    cout << "After inserting 25 at pos 1: ";
    list.print();   // 20 -> 25 -> 10 -> NULL

    // Delete at specific position
    list.deleteAt(1);
    cout << "After deleting at pos 1: ";
    list.print();   // 20 -> 10 -> NULL

    // Insert in middle
    list.insertMiddle(99);
    cout << "After inserting 99 in middle: ";
    list.print();   // 20 -> 99 -> 10 -> NULL

    return 0;
}
