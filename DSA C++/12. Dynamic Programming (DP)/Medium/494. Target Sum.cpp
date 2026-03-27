// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

//     For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

// Return the number of different expressions that you can build, which evaluates to target.

 

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

// Example 2:

// Input: nums = [1], target = 1
// Output: 1

 

// Constraints:

//     1 <= nums.length <= 20
//     0 <= nums[i] <= 1000
//     0 <= sum(nums[i]) <= 1000
//     -1000 <= target <= 1000

 

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
