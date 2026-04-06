# Print extreme nodes of each level of Binary Tree in alternate order.py - Python skeleton converted from C++

# Original C++ code:
# 
# #include <iostream>
# #include<queue>
# #include<vector>
# using namespace std;
# 
# 
# struct Node {
#   int data;
#   Node* left;
#   Node* right;
#   Node* nextRight;
# };
# 
# 
# // Level 1 → RIGHTMOST
# // Level 2 → LEFTMOST
# // Level 3 → RIGHTMOST
# // Level 4 → LEFTMOST
# // … and so on (alternate)
# // ✅ Correct Approach (BFS / Level Order)
# // 💡 Strategy
# // Use a queue (level-order traversal)
# // Track the level number
# // At each level:
# // If level is odd → take last node
# // If level is even → take first node
# 
# class Solution {
#   public:
#     /* Function to print nodes of extreme corners
#     of each level in alternate order */
#     vector<int> extremeNodes(Node* root) {
#         // Your code here
#         vector<int> ans;
#         if (!root) return ans;
# 
#         queue<Node*> q;
#         q.push(root);
#         int level = 1;
# 
#         while (!q.empty()) {
#             int size = q.size();
#             Node* first = NULL;
#             Node* last = NULL;
# 
#             for (int i = 0; i < size; i++) {
#                 Node* curr = q.front();
#                 q.pop();
# 
#                 if (i == 0) first = curr;
#                 if (i == size - 1) last = curr;
# 
#                 if (curr->left) q.push(curr->left);
#                 if (curr->right) q.push(curr->right);
#             }
# 
#             // odd level → rightmost
#             if (level % 2 == 1)
#                 ans.push_back(last->data);
#             // even level → leftmost
#             else
#                 ans.push_back(first->data);
# 
#             level++;
#         }
# 
#         return ans;
#     }
# };
# 
# 
# // for each level of the binary tree:
# // Level 0 → print leftmost
# // Level 1 → print rightmost
# // Level 2 → print leftmost
# // Level 3 → print rightmost
# // … and so on (alternate)
# // ✅ Correct & Efficient Approach (BFS)
# // 💡 Idea
# // Use level-order traversal
# // Track level number
# // At each level:
# // If level is even → print first node
# // If level is odd → print last node
# class Solution {
#   public:
#       vector<int> ExtremeNodes(Node* root) {
#           vector<int> ans;
#           if (!root) return ans;
#   
#           queue<Node*> q;
#           q.push(root);
#           bool leftToRight = true;  // even level
#   
#           while (!q.empty()) {
#               int size = q.size();
#   
#               for (int i = 0; i < size; i++) {
#                   Node* curr = q.front();
#                   q.pop();
#   
#                   // extreme node logic
#                   if (leftToRight && i == 0)
#                       ans.push_back(curr->data);
#                   else if (!leftToRight && i == size - 1)
#                       ans.push_back(curr->data);
#   
#                   if (curr->left) q.push(curr->left);
#                   if (curr->right) q.push(curr->right);
#               }
#   
#               leftToRight = !leftToRight;  // alternate
#           }
#   
#           return ans;
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
