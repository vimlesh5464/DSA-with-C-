# 437. Path Sum III.py - Python skeleton converted from C++

# Original C++ code:
# 
# #include<iostream>
# #include<unordered_map>
# #include<vector>
# 
# using namespace std;
# 
# class TreeNode {
# public:
#     int val;
#     TreeNode* left;
#     TreeNode* right;
# 
#     TreeNode(int val) {
#         this->val = val;
#         left = right = nullptr;
#     }
# };
# 
# class Solution {
#   public:
#      void solve(TreeNode* root, int k, long long currSum, int &count, unordered_map<long long,int> &mp)
#       {
#           if(!root) return;
#   
#           // update current prefix sum
#           currSum += root->val;
#   
#           // check if path from root equals k
#           if(currSum == k)
#               count++;
#   
#           // check if there exists a prefix sum such that currSum - prefix = k
#           if(mp.find(currSum - k) != mp.end())
#               count += mp[currSum - k];
#   
#           // store current prefix sum
#           mp[currSum]++;
#   
#           // traverse left and right
#           solve(root->left, k, currSum, count, mp);
#           solve(root->right, k, currSum, count, mp);
#   
#           // backtrack
#           mp[currSum]--;
#       }
#   
#       int pathSum(TreeNode* root, int k) {
#              unordered_map<long long,int> mp;
#              
#       int count = 0;
#   
#       solve(root, k, 0, count, mp);
#   
#       return count;
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
