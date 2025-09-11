#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast == slow) {
                // Step 2: Find the starting node of cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // starting node of cycle
            }
        }
        return NULL; // no cycle
    }
};

// Helper function to print linked list (for testing without cycle)
void printList(ListNode* head, int limit = 20) {
    int count = 0;
    while (head != NULL && count < limit) {
        cout << head->val << " -> ";
        head = head->next;
        count++;
    }
    if (head != NULL) cout << "... (cycle detected while printing)";
    else cout << "NULL";
    cout << endl;
}

int main() {
    // Create nodes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Introduce cycle: last node points to node with value 3
    head->next->next->next->next->next = head->next->next;

    Solution sol;
    ListNode* cycleStart = sol.detectCycle(head);

    if (cycleStart != NULL)
        cout << "Cycle detected! Starting node value: " << cycleStart->val << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}
