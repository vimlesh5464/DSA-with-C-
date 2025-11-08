#include <iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };
   struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
  TreeNode* buildBST(vector<int>& nums, int start, int end) {
          if (start > end) return nullptr;
  
          int mid = start + (end - start) / 2;
          TreeNode* root = new TreeNode(nums[mid]);
  
          root->left = buildBST(nums, start, mid - 1);
          root->right = buildBST(nums, mid + 1, end);
  
          return root;
      }
  
      TreeNode* sortedListToBST(ListNode* head) {
          vector<int>nums;
          ListNode* temp = head;
          while(temp!=NULL){
              nums.push_back(temp->val);
              temp = temp->next;
          }
          return buildBST(nums,0,nums.size()-1);
      }
  };

  class Solution {
    public:
        TreeNode* sortedListToBST(ListNode* head) {
            if (!head) return nullptr;
            if (!head->next) return new TreeNode(head->val);
    
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = nullptr;
    
            // Find middle (slow)
            while (fast && fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
    
            // Disconnect left half from middle
            prev->next = nullptr;
    
            // Middle node is root
            TreeNode* root = new TreeNode(slow->val);
    
            // Recursively build left and right subtrees
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(slow->next);
    
            return root;
        }
    };
    