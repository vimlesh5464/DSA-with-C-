#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        // Push all values to the stack
        while (temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        // Compare stack values with list nodes
        while (temp != NULL) {
            if (temp->val != st.top()) {
                return false;
            }
            st.pop();
            temp = temp->next;
        }

        return true;
    }
};

// Helper function to create linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
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
    int arr[] = {1, 2, 3, 2, 1};
    ListNode* head = createList(arr, 5);

    cout << "Linked List: ";
    printList(head);

    Solution sol;
    if (sol.isPalindrome(head)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }

    return 0;
}
