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
// ----------------- LINKED LIST HELPERS -----------------
ListNode* createList(const vector<int>& nums) {
  if (nums.empty()) return NULL;
  ListNode* head = new ListNode(nums[0]);
  ListNode* curr = head;
  for (int i = 1; i < nums.size(); i++) {
      curr->next = new ListNode(nums[i]);
      curr = curr->next;
  }
  return head;
}

void printList(ListNode* head) {
  while (head) {
      cout << head->val;
      if (head->next) cout << " ";
      head = head->next;
  }
  cout << "\n";
}

// ------------------------- MAIN -------------------------
int main() {
  int k;
  cin >> k;
  vector<ListNode*> lists(k);

  for (int i = 0; i < k; i++) {
      int n;
      cin >> n;
      vector<int> arr(n);
      for (int j = 0; j < n; j++) cin >> arr[j];
      lists[i] = createList(arr);
  }

  Solution sol;
  ListNode* merged = sol.mergeKLists(lists);

  printList(merged);

  return 0;
}