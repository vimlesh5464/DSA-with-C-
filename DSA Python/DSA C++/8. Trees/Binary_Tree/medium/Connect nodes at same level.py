# Connect nodes at same level.py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# #include<queue>
# #include<vector>
# using namespace std;
# 
# struct Node {
#   int data;
#   Node* left;
#   Node* right;
#   Node* nextRight;
# };
# 
# class Solution {
#   public:
#       Node* connect(Node* root) {
#           if (!root) return NULL;
#   
#           queue<Node*> q;
#           q.push(root);
#   
#           while (!q.empty()) {
#               int size = q.size();
#               Node* prev = NULL;
#   
#               for (int i = 0; i < size; i++) {
#                   Node* curr = q.front();
#                   q.pop();
#   
#                   if (prev)
#                       prev->nextRight = curr;
#   
#                   prev = curr;
#   
#                   if (curr->left) q.push(curr->left);
#                   if (curr->right) q.push(curr->right);
#               }
#   
#               // last node of this level
#               prev->nextRight = NULL;
#           }
#   
#           return root;   // ✅ IMPORTANT
#       }
#   };
#   

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
