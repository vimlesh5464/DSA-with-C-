// Alice gave Bob a Linked List of size N and asked him to find the maximum sum among pairs formed by adding elements at symmetric positions from both ends of the list, such as

// (first element + last element)
// (second element + second last element),
// and so on up to the middle of the list.
// You are given the head of the linked list. Your task is to determine the maximum sum based on this condition.


// Note: The number of elements in the linked list is always even.

// Input Format

// The first line contains an integer N – the size of LinkedList.
// The second line contains the ‘N’ space-separated integers elements of the Linked List

// Output Format

// Print a single integer ‘K’ – the maximum sum of symmetric pairs according to the given condition.

// Constraints

// 2 <= N<= 10^5  (N is even (i.e.,N can be 2, 4, 6, 8, ..., up to 10^5).)

// -5*10^3 <= arr[i] <= 5*10^3

// Sample Testcase 0

// Testcase Input
// 4
// 1 2 3 4
// Testcase Output
// 5
// Explanation

// Sum of (1, 4) is 5 and sum of (2, 3) is also 5. So, the maximum sum is 5.

// Sample Testcase 1

// Testcase Input
// 6
// -1 2 3 2 4 2
// Testcase Output
// 6
// Explanation

// First pair: (−1+2)=1


// Second pair: (2+4)=6


// Third pair: (3+2)=5


// Now, the maximum sum is 6 from the second and third pairs. Hence, the output is 6.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int pairSum(ListNode* head) {
  // Step 1: Find middle
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
  }

  // Step 2: Reverse second half
  ListNode* prev = NULL;
  ListNode* curr = slow;

  while (curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
  }

  // Step 3: Find max sum
  ListNode* first = head;
  ListNode* second = prev;

  int maxSum = INT_MIN;

  while (second) {
      maxSum = max(maxSum, first->val + second->val);
      first = first->next;
      second = second->next;
  }

  return maxSum;
}
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// Build linked list
Node* build_linked_list(int size, const vector<int>& elements) {
    if (size == 0) return nullptr;

    Node* head = new Node(elements[0]);
    Node* tail = head;

    for (int i = 1; i < size; ++i) {
        tail->next = new Node(elements[i]);
        tail = tail->next;
    }
    return head;
}

// Brute force solution
int pair_sum(Node* head) {
    vector<int> arr;

    // Step 1: Store values
    Node* temp = head;
    while (temp) {
        arr.push_back(temp->val);
        temp = temp->next;
    }

    // Step 2: Two pointers
    int i = 0, j = arr.size() - 1;

    // Initialize safely (important for negative values)
    int maxSum = arr[i] + arr[j];

    while (i < j) {
        maxSum = max(maxSum, arr[i] + arr[j]);
        i++;
        j--;
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;

    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
    }

    Node* head = build_linked_list(n, elements);

    int result = pair_sum(head);
    cout << result << endl;

    return 0;
}