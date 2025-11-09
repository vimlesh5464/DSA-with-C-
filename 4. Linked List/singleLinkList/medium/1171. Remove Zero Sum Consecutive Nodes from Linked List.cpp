
#include <iostream>
#include<vector>
#include<stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
      ListNode* removeZeroSumSublists(ListNode* head) {
          vector<int> arr;
          ListNode* temp = head;
          while (temp) {
              arr.push_back(temp->val);
              temp = temp->next;
          }
  
          // Remove zero-sum subarrays
          for (int i = 0; i < arr.size(); i++) {
              int sum = 0;
              for (int j = i; j < arr.size(); j++) {
                  sum += arr[j];
                  if (sum == 0) {
                      arr.erase(arr.begin() + i, arr.begin() + j + 1);
                      i = -1; // Restart after modification
                      break;
                  }
              }
          }
  
          // Rebuild linked list
          ListNode* dummy = new ListNode(0);
          ListNode* cur = dummy;
          for (int val : arr) {
              cur->next = new ListNode(val);
              cur = cur->next;
          }
          return dummy->next;
      }
  };

  class Solution {
    public:
        ListNode* removal(ListNode* head, bool& flag) {
            if (head == NULL) {
                return NULL;
            }
            ListNode* temp = head;
            int sum = 0;
            while (temp != NULL) {
                sum += temp->val;
                if (sum == 0) {
                    flag = true;
                    return temp->next;
                }
                temp = temp->next;
            }
            head->next = removal(head->next, flag);
            return head;
        }
            ListNode* removeZeroSumSublists(ListNode * head) {
                while (1) {
                    bool flag = false;
                    head = removal(head, flag);
                    if (flag == false) {
                        break;
                    }
                }
                return head;
            }
        };