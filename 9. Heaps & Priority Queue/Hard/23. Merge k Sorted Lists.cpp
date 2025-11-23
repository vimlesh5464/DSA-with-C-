#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Push all node values into the heap
        for (auto list : lists) {
            while (list != nullptr) {
                minHeap.push(list->val);
                list = list->next;
            }
        }

        // Create a dummy node to build the merged list
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        // Pop elements from min-heap and create nodes
        while (!minHeap.empty()) {
            curr->next = new ListNode(minHeap.top());
            minHeap.pop();
            curr = curr->next;
        }

        return dummy->next;
        
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from vector
ListNode* createList(vector<int> v) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int val : v) {
        curr->next = new ListNode(val);
        curr = curr->next;
    }
    return dummy->next;
}

int main() {
    // Example: merge 3 sorted lists
    vector<ListNode*> lists;

    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    Solution sol;
    ListNode* merged = sol.mergeKLists(lists);

    cout << "Merged list: ";
    printList(merged);

    return 0;
}
