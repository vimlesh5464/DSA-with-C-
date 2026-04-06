# 515. Find Largest Value in Each Tree Row.py - Python skeleton converted from C++

# Original C++ code:
# #include <iostream>
# #include <vector>
# #include <queue>
# using namespace std;
# 
# struct TreeNode {
#     int val;
#     TreeNode* left;
#     TreeNode* right;
#     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
# };
# 
# 
# class Solution {
#   public:
#       vector<int> largestValues(TreeNode* root) {
#           vector<int> result;
#           if (!root) return result;
#   
#           queue<TreeNode*> q;
#           q.push(root);
#   
#           while (!q.empty()) {
#               int size = q.size();
#               int maxi = INT_MIN;
#   
#               // Linear scan for current level
#               for (int i = 0; i < size; i++) {
#                   TreeNode* node = q.front();
#                   q.pop();
#   
#                   maxi = max(maxi, node->val);
#   
#                   if (node->left) q.push(node->left);
#                   if (node->right) q.push(node->right);
#               }
#   
#               result.push_back(maxi);
#           }
#   
#           return result;
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
