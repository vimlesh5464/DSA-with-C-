#include <iostream>
#include<vector>
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
      ListNode* reverseBetween(ListNode* head, int left, int right) {
          if (!head || left == right) return head;
  
          vector<int> arr;
          ListNode* temp = head;
  
          // Step 1: Copy values to vector
          while (temp) {
              arr.push_back(temp->val);
              temp = temp->next;
          }
  
          // Step 2: Reverse only the subarray (left-1 to right-1)
          reverse(arr.begin() + (left - 1), arr.begin() + right);
  
          // Step 3: Copy back to linked list
          ListNode* temp1 = new ListNode(arr[0]);
          ListNode* curr = temp1;
          for(int i = 1; i < arr.size(); i++){
              curr->next = new ListNode(arr[i]);
              curr = curr->next;
          }
          return temp1;
      }
  };
  

// Solution class
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Move prev to one node before 'left'
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Reverse sublist from left to right
        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};

// Helper function to create linked list from array
ListNode* createList(vector<int>&arr, int n) {
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
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
      cin >> arr[i];

  int left, right;
  cin >> left >> right;

  ListNode* head = createList(arr,arr.size());

  Solution s;
  head = s.reverseBetween(head, left, right);

  printList(head);

  return 0;
}