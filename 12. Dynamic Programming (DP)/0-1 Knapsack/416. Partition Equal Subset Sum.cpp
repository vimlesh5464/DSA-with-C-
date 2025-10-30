#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      bool helper(vector<int>& nums, int index, int target) {
          // Base Cases
          if (target == 0) return true;       // Found a subset
          if (index < 0 || target < 0) return false; // No subset possible
  
          // Choice 1: Include current element
          bool include = helper(nums, index - 1, target - nums[index]);
          
          // Choice 2: Exclude current element
          bool exclude = helper(nums, index - 1, target);
          
          // Either choice can lead to a valid subset
          return include || exclude;
      }
  
      bool canPartition(vector<int>& nums) {
          int totalSum = 0;
          for (int num : nums) totalSum += num;
          
          // If total sum is odd, cannot partition equally
          if (totalSum % 2 != 0) return false;
          
          int target = totalSum / 2;
          return helper(nums, nums.size() - 1, target);
      }
  };
  
  class Solution {
    public:
        bool helper(vector<int>& nums, int index, int target, vector<vector<int>>& dp) {
            // Base Cases
            if (target == 0) return true;          // Found subset
            if (index < 0 || target < 0) return false; // Not possible
            
            // Check if already computed
            if (dp[index][target] != -1) 
                return dp[index][target];
    
            // Choice 1: include current element
            bool include = helper(nums, index - 1, target - nums[index], dp);
            // Choice 2: exclude current element
            bool exclude = helper(nums, index - 1, target, dp);
    
            // Store and return
            return dp[index][target] = include || exclude;
        }
    
        bool canPartition(vector<int>& nums) {
            int totalSum = 0;
            for (int num : nums) totalSum += num;
    
            // If totalSum is odd → not possible
            if (totalSum % 2 != 0) return false;
    
            int target = totalSum / 2;
            int n = nums.size();
    
            // dp[i][j] = whether using first i elements we can make sum j
            vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    
            return helper(nums, n - 1, target, dp);
        }
    };
    