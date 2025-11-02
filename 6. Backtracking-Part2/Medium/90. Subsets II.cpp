#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
  void brack(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& ans) {
          // Add the current subset
          ans.push_back(subset);
  
          // Generate all subsets starting from 'index'
          for (int i = index; i < nums.size(); i++) {
              if (i > index && nums[i] == nums[i - 1]) continue;
              subset.push_back(nums[i]);           // Include current element
              brack(nums, i + 1, subset, ans);     // Recurse for next elements
              subset.pop_back();                   // Backtrack
          }
      }
      vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         
          vector<vector<int>> ans;
          vector<int> subset;
          // ✅ Edge Case: If nums is empty
          if (nums.empty()) {
              ans.push_back({}); // Only the empty subset exists
              return ans;
          }
          sort(nums.begin(), nums.end());
          brack(nums, 0, subset, ans);
          
          return ans;
      }
  };