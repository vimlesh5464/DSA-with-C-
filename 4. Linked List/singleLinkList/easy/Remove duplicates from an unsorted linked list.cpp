#include <iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// Linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) {
        val = val;
        next = NULL;
    }
};

  class Solution {
    public:
        ListNode* removeDuplicates(ListNode* head) {
            if (head == NULL) return NULL;
    
            ListNode* temp = head;
            unordered_set<int> s;
            vector<int> ans;
    
            while (temp != NULL) {
                if (s.find(temp->val) == s.end()) { // not seen before
                    s.insert(temp->val);
                    ans.push_back(temp->val);
                }
                temp = temp->next;
            }
    
            // If no unique elements, return NULL
            if (ans.empty()) return NULL;
    
            ListNode* newHead = new ListNode(ans[0]);
            ListNode* curr = newHead;
            for (int i = 1; i < ans.size(); i++) {
                curr->next = new ListNode(ans[i]);
                curr = curr->next;
            }
    
            return newHead;
        }
    };
    // ---------------------------------------------------------
class Solution {
  public:
      ListNode* removeDuplicates(ListNode* head) {
          if (!head) return head;
  
          unordered_set<int> seen;
          ListNode* curr = head;
          ListNode* prev = NULL;
  
          while (curr) {
              if (seen.count(curr->val)) {
                  // Duplicate found → delete current node
                  prev->next = curr->next;
              } else {
                  seen.insert(curr->val);
                  prev = curr;
              }
              curr = curr->next;
          }
          return head;
      }
  };
  
  // ----------------- Linked List Helper Functions -----------------
  ListNode* createList(vector<int>& arr) {
      if (arr.empty()) return NULL;
      ListNode* head = new ListNode(arr[0]);
      ListNode* temp = head;
  
      for (int i = 1; i < arr.size(); i++) {
          temp->next = new ListNode(arr[i]);
          temp = temp->next;
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
  
  // ------------------------------ MAIN ------------------------------
  int main() {
      int n;
      cin >> n;
  
      vector<int> arr(n);
      for (int i = 0; i < n; i++) cin >> arr[i];
  
      ListNode* head = createList(arr);
  
      Solution sol;
      head = sol.removeDuplicates(head);
  
      printList(head);
  
      return 0;
  }
  
  