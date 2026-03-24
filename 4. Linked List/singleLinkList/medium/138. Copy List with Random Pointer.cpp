// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

//     val: an integer representing Node.val
//     random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.

// Your code will only be given the head of the original linked list.

 

// Example 1:

// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

// Example 2:

// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]

// Example 3:

// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]

 

// Constraints:

//     0 <= n <= 1000
//     -104 <= Node.val <= 104
//     Node.random is null or is pointing to some node in the linked list.

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
