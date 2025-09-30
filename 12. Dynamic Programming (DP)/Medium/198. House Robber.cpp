#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int solve(int i, vector<int>& nums) {
          // Base cases
          if (i < 0) return 0;            // No houses left
          if (i == 0) return nums[0];     // Only first house
  
          // Choice: rob this house or skip it
          int pick = nums[i] + solve(i - 2, nums);  // Rob current, skip previous
          int notPick = solve(i - 1, nums);         // Skip current
  
          return max(pick, notPick);
      }
  
      int rob(vector<int>& nums) {
          int n = nums.size();
          return solve(n - 1, nums);
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
