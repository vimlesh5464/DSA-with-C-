#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int solve(vector<int>& nums, int i, int end) {
          // Base case
          if (i > end) return 0;
  
          // Take or skip
          int take = nums[i] + solve(nums, i + 2, end);
          int skip = solve(nums, i + 1, end);
  
          return max(take, skip);
      }
  
      int rob(vector<int>& nums) {
          int n = nums.size();
  
          // Edge case
          if (n == 1) return nums[0];
  
          // Case 1: Exclude last house
          int case1 = solve(nums, 0, n - 2);
  
          // Case 2: Exclude first house
          int case2 = solve(nums, 1, n - 1);
  
          return max(case1, case2);
      }
  };

  class Solution {
    public:
        int solve(vector<int>& nums, int i, int end, vector<int>& dp) {
            // Base case
            if (i > end) return 0;
    
            // Already computed
            if (dp[i] != -1) return dp[i];
    
            int take = nums[i] + solve(nums, i + 2, end, dp);
            int skip = solve(nums, i + 1, end, dp);
    
            return dp[i] = max(take, skip);
        }
    
        int rob(vector<int>& nums) {
            int n = nums.size();
            if (n == 1) return nums[0];
    
            // Case 1: Exclude last house
            vector<int> dp1(n, -1);
            int case1 = solve(nums, 0, n - 2, dp1);
    
            // Case 2: Exclude first house
            vector<int> dp2(n, -1);
            int case2 = solve(nums, 1, n - 1, dp2);
    
            return max(case1, case2);
        }
    };
class Solution {
  public:
      // Linear House Robber DP
      int robLinear(vector<int>& nums, int start, int end) {
          int n = end - start + 1;
          if (n == 0) return 0;
          if (n == 1) return nums[start];
  
          vector<int> dp(n, 0);
          dp[0] = nums[start];
          dp[1] = max(nums[start], nums[start + 1]);
  
          for (int i = 2; i < n; i++) {
              dp[i] = max(dp[i-1], dp[i-2] + nums[start + i]);
          }
  
          return dp[n - 1];
      }
  
      int rob(vector<int>& nums) {
          int n = nums.size();
          if (n == 1) return nums[0];
          if (n == 2) return max(nums[0], nums[1]);
  
          // Case 1: Rob houses 0..n-2
          int case1 = robLinear(nums, 0, n - 2);
          // Case 2: Rob houses 1..n-1
          int case2 = robLinear(nums, 1, n - 1);
  
          return max(case1, case2);
      }
  };

  
int main() {
    Solution sol;

    vector<int> nums = {2, 3, 2}; 
    cout << "Maximum money robbed: " << sol.rob(nums) << endl;

    nums = {1, 2, 3, 1};
    cout << "Maximum money robbed: " << sol.rob(nums) << endl;

    return 0;
}

