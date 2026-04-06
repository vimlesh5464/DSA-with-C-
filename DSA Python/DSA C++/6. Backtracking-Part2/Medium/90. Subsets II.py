# 90. Subsets II.py - Python skeleton converted from C++

# Original C++ code:
# // Given an integer array nums that may contain duplicates, return all possible (the power set).
# 
# // The solution set must not contain duplicate subsets. Return the solution in any order.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [1,2,2]
# // Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
# 
# // Example 2:
# 
# // Input: nums = [0]
# // Output: [[],[0]]
# 
#  
# 
# // Constraints:
# 
# //     1 <= nums.length <= 10
# //     -10 <= nums[i] <= 10
# 
# #include<iostream>
# #include<vector>
# using namespace std;
# class Solution {
#   public:
#   void brack(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& ans) {
#           // Add the current subset
#           ans.push_back(subset);
#   
#           // Generate all subsets starting from 'index'
#           for (int i = index; i < nums.size(); i++) {
#               if (i > index && nums[i] == nums[i - 1]) continue;
#               subset.push_back(nums[i]);           // Include current element
#               brack(nums, i + 1, subset, ans);     // Recurse for next elements
#               subset.pop_back();                   // Backtrack
#           }
#       }
#       vector<vector<int>> subsetsWithDup(vector<int>& nums) {
#          
#           vector<vector<int>> ans;
#           vector<int> subset;
#           // ✅ Edge Case: If nums is empty
#           if (nums.empty()) {
#               ans.push_back({}); // Only the empty subset exists
#               return ans;
#           }
#           sort(nums.begin(), nums.end());
#           brack(nums, 0, subset, ans);
#           
#           return ans;
#       }
#   };

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
