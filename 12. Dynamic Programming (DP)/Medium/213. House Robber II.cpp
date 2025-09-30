#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // Recursive helper for linear House Robber
    int helper(int i, vector<int>& nums, vector<int>& dp, int start) {
        if (i < start) return 0;            // No houses left
        if (i == start) return nums[start]; // Only one house in range
        if (dp[i] != -1) return dp[i];     // Memoization

        int rob = nums[i] + helper(i - 2, nums, dp, start); // Rob current
        int notRob = helper(i - 1, nums, dp, start);        // Skip current

        return dp[i] = max(rob, notRob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // Case 1: Rob houses 0 to n-2 (exclude last)
        vector<int> dp1(n, -1);
        int case1 = helper(n - 2, nums, dp1, 0);

        // Case 2: Rob houses 1 to n-1 (exclude first)
        vector<int> dp2(n, -1);
        int case2 = helper(n - 1, nums, dp2, 1);

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

