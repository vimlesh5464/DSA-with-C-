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
      ListNode* deleteDuplicates(ListNode* head) {
          if (!head) return nullptr;
          
          ListNode* temp = head;
          vector<int> ans;
          while(temp!=NULL){
              ans.push_back(temp->val);
              temp=temp->next;
          }
          unordered_set<int> s;
          int idx = 0;  
  
          for (int i = 0; i < ans.size(); i++) {
              if (s.find(ans[i]) == s.end()) { 
                  s.insert(ans[i]);  
                  ans[idx++] = ans[i];  
              }
          }
      
          ListNode* temp1 = new ListNode(ans[0]);
          ListNode* curr = temp1;
          for(int i = 1; i < idx; i++){
              curr->next = new ListNode(ans[i]);
              curr = curr->next;
          }
          return temp1;
      }
  };

  class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if (!head) return head;
    
            ListNode* curr = head;
    
            while (curr->next) {
                if (curr->val == curr->next->val) {
                    curr->next = curr->next->next;  // remove duplicate
                } else {
                    curr = curr->next;
                }
            }
    
            return head;
        }
    };
    
    // Function to print the list
    void printList(ListNode* head) {
        while (head) {
            cout << head->val;
            if (head->next) cout << " ";
            head = head->next;
        }
        cout << endl;
    }
    
    // Function to build list from input
    ListNode* buildList(vector<int>& arr) {
        if (arr.empty()) return NULL;
    
        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;
    
        for (int i = 1; i < arr.size(); i++) {
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        return head;
    }
    
    int main() {
        int n;
        cin >> n;   // number of nodes
    
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];   // sorted list input
        }
    
        ListNode* head = buildList(arr);
    
        Solution obj;
        head = obj.deleteDuplicates(head);
    
        printList(head);
    
        return 0;
    }
    