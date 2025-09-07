#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> m;

        // Copy the head node
        Node* newHead = new Node(head->val);
        Node* newTemp = newHead;
        Node* oldTemp = head->next;
        m[head] = newHead;

        // Copy the rest of the nodes (next pointers)
        while (oldTemp != nullptr) {
            Node* copy = new Node(oldTemp->val);
            m[oldTemp] = copy;
            newTemp->next = copy;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        // Copy random pointers
        oldTemp = head;
        newTemp = newHead;
        while (oldTemp != nullptr) {
            newTemp->random = m[oldTemp->random]; // nullptr maps to nullptr
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};

// Helper function to print list (shows value and random)
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Val: " << temp->val;
        if (temp->random) cout << ", Random: " << temp->random->val;
        else cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Example list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Random pointers
    head->random = head->next->next; // 1 -> 3
    head->next->random = head;       // 2 -> 1
    head->next->next->random = head->next; // 3 -> 2

    Solution sol;
    Node* copied = sol.copyRandomList(head);

    cout << "Original List:" << endl;
    printList(head);

    cout << "\nCopied List:" << endl;
    printList(copied);

    return 0;
}
