// You are a professional robber planning to rob houses along a street. Each house
// has a certain amount of money stashed, the only constraint stopping you from 
//robbing each of them is that adjacent houses have security systems connected and 
//it will automatically contact the police if two adjacent houses were broken into on
// the same night.

// Given an integer array nums representing the amount of money of each house, return
// the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

 

// Constraints:

//     1 <= nums.length <= 100
//     0 <= nums[i] <= 400

 

#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      int solve(int i, vector<int>& nums) {
          int n = nums.size();
  
          // Base case
          if (i >= n) return 0;
  
          int pick = nums[i] + solve(i + 2, nums);
          int notPick = solve(i + 1, nums);
  
          return max(pick, notPick);
      }
  
      int rob(vector<int>& nums) {
          return solve(0, nums);
      }
  };
//(Memoization
  class Solution {
    public:
        int solve(int i, vector<int>& nums, vector<int>& dp) {
            if (i >= nums.size()) return 0;
            if (dp[i] != -1) return dp[i];
    
            int pick = nums[i] + solve(i + 2, nums, dp);
            int notPick = solve(i + 1, nums, dp);
    
            return dp[i] = max(pick, notPick);
        }
    
        int rob(vector<int>& nums) {
            vector<int> dp(nums.size(), -1);
            return solve(0, nums, dp);
        }
    };
    
  

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of houses: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter money in each house:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = sol.rob(nums);
    cout << "Maximum amount that can be robbed: " << result << endl;

    return 0;
}
