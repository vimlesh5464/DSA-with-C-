#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int num : nums) total += num;

        // If target is impossible to reach
        if (target > total || target < -total) return 0;

        // Check if (target + total) is even, otherwise partition not possible
        if ((target + total) % 2 != 0) return 0;

        int sum = (target + total) / 2;  // Convert to subset sum problem
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

        // Base case: 1 way to make sum 0 (choose nothing)
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int s = 0; s <= sum; s++) {
                int notTake = dp[i-1][s];
                int take = 0;
                if (nums[i-1] <= s) take = dp[i-1][s - nums[i-1]];
                dp[i][s] = take + notTake;
            }
        }

        return dp[n][sum];
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << sol.findTargetSumWays(nums, target) << endl; // Output: 5
    return 0;
}
