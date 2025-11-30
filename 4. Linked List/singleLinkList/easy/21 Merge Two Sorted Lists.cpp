#include <iostream>
#include<vector>
using namespace std;


class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
      ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
           vector<int> ans;
           ListNode* i = list1;
           ListNode* j = list2;
           while(i!=NULL && j!=NULL){
              if(i->val<=j->val){
                  ans.push_back(i->val);
                  i=i->next;
              }else{
                  ans.push_back(j->val);
                  j=j->next;
              }
           }
           while(i!=NULL){
              ans.push_back(i->val);
              i=i->next;
           }
           while(j!=NULL){
              ans.push_back(j->val);
              j=j->next;
           }
            // 🩵 FIX: handle empty vector
          if (ans.empty()) return NULL;
           ListNode* head = new ListNode(ans[0]);
           ListNode* temp = head;
           for(int i = 1; i < ans.size(); i++){
              temp->next=new ListNode(ans[i]);
              temp = temp->next;
           }
           return head;
      }
  };
// --------------------- SOLUTION ---------------------
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;

        return dummy.next;
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
    int n1, n2;
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) cin >> arr1[i];

    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) cin >> arr2[i];

    ListNode* l1 = createList(arr1);
    ListNode* l2 = createList(arr2);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(l1, l2);

    printList(merged);

    return 0;
}
