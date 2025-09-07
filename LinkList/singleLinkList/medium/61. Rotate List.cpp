#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Compute the length
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }

        // Step 2: Connect last node to head (make it circular)
        temp->next = head;

        // Step 3: Find the new tail: length - k % length steps
        k = k % length;
        int stepsToNewTail = length - k;
        while (stepsToNewTail--) {
            temp = temp->next;
        }

        // Step 4: Break the circle and set new head
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};

// Helper function to create linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* head = createList(arr, 5);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.rotateRight(head, 2);

    cout << "Rotated List by 2: ";
    printList(head);

    return 0;
}
