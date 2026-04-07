#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapNodes(ListNode* head, int k) {
    if (!head) return NULL;

    vector<int> arr;
    ListNode* temp = head;

    while (temp) {
        arr.push_back(temp->val);
        temp = temp->next;
    }

    int n = arr.size();

    // constraints already guarantee valid k, but still safe
    if (k <= 0 || k > n) return head;

    swap(arr[k - 1], arr[n - k]);

    temp = head;
    int i = 0;
    while (temp) {
        temp->val = arr[i++];
        temp = temp->next;
    }

    return head;
}

ListNode* swapNodes(ListNode* head, int k) {
  ListNode* first = head;
  ListNode* second = head;
  ListNode* temp = head;

  // Move first to kth node
  for (int i = 1; i < k; i++) {
      first = first->next;
  }

  temp = first;

  // Move temp to end, second follows
  while (temp->next != NULL) {
      temp = temp->next;
      second = second->next;
  }

  // swap values
  swap(first->val, second->val);

  return head;
}
int main() {
    int n;
    cin >> n;

    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ListNode* newNode = new ListNode(x);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;
    cin >> k;

    head = swapNodes(head, k);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}