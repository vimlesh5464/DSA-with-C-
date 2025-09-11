#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry) {
            int sum = carry; 

            if (l1 != NULL) {
                sum += l1->val; 
                l1 = l1->next; 
            }

            if (l2 != NULL) {
                sum += l2->val; 
                l2 = l2->next; 
            }

            carry = sum / 10; 
            temp->next = new ListNode(sum % 10); 
            temp = temp->next; 
        }

        return dummy->next; 
    }
};

// Helper function to create list from array
ListNode* createList(int arr[], int n) {
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
    int arr1[] = {2, 4, 3}; // 342
    int arr2[] = {5, 6, 4}; // 465

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result List: ";
    printList(result); // Expected: 7 -> 0 -> 8 -> NULL (807)

    return 0;
}
