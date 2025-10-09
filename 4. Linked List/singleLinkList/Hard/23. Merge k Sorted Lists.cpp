#include <iostream>
#include<queue>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap
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
