# 494. Target Sum.py - Python skeleton converted from C++

# Original C++ code:
# // You are given an integer array nums and an integer target.
# 
# // You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
# 
# //     For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
# 
# // Return the number of different expressions that you can build, which evaluates to target.
# 
#  
# 
# // Example 1:
# 
# // Input: nums = [1,1,1,1,1], target = 3
# // Output: 5
# // Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
# // -1 + 1 + 1 + 1 + 1 = 3
# // +1 - 1 + 1 + 1 + 1 = 3
# // +1 + 1 - 1 + 1 + 1 = 3
# // +1 + 1 + 1 - 1 + 1 = 3
# // +1 + 1 + 1 + 1 - 1 = 3
# 
# // Example 2:
# 
# // Input: nums = [1], target = 1
# // Output: 1
# 
#  
# 
# // Constraints:
# 
# //     1 <= nums.length <= 20
# //     0 <= nums[i] <= 1000
# //     0 <= sum(nums[i]) <= 1000
# //     -1000 <= target <= 1000
# 
#  
# 
# #include <iostream>
# #include<vector>
# #include<numeric>
# using namespace std;
# class Solution {
#   public:
#       int helper(vector<int>& nums, int index, int target) {
#           // Base case
#           if (index == nums.size()) {
#               if (target == 0) return 1;
#               return 0;
#           }
#   
#           // Choose +
#           int plus = helper(nums, index + 1, target - nums[index]);
#   
#           // Choose -
#           int minus = helper(nums, index + 1, target + nums[index]);
#   
#           return plus + minus;
#       }
#   
#       int findTargetSumWays(vector<int>& nums, int target) {
#           return helper(nums, 0, target);
#       }
#   };
# 
#   class Solution {
#     public:
#      // Recursive function with memoization
#         int countSubsets(vector<int>& nums, int ind, int target, vector<vector<int>>& dp) {
#             // Base case: when we are at index 0
#             if (ind == 0) {
#                 // Two scenarios:
#                 if (target == 0 && nums[0] == 0) return 2; // {pick or not pick 0}
#                 if (target == 0 || target == nums[0]) return 1; // Either pick or skip
#                 return 0; // Otherwise no valid way
#             }
#     
#             // Return if already computed
#             if (dp[ind][target] != -1) return dp[ind][target];
#     
#             // Exclude current element
#             int notPick = countSubsets(nums, ind - 1, target, dp);
#     
#             // Include current element if it is <= target
#             int pick = 0;
#             if (nums[ind] <= target)
#                 pick = countSubsets(nums, ind - 1, target - nums[ind], dp);
#     
#             // Store and return result
#             return dp[ind][target] = pick + notPick;
#         }
#         int findTargetSumWays(vector<int>& nums, int target) {
#              // Calculate the total sum of the array
#             int totalSum = accumulate(nums.begin(), nums.end(), 0);
#     
#             // If target is not achievable (because of sum or parity), return 0
#             if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0) 
#                 return 0;
#     
#             // Our problem reduces to subset sum with sum = (totalSum - target) / 2
#             int subsetSum = (totalSum - target) / 2;
#     
#             // Initialize memo table with -1
#             vector<vector<int>> dp(nums.size(), vector<int>(subsetSum + 1, -1));
#     
#             // Call recursive function with memoization
#             return countSubsets(nums, nums.size() - 1, subsetSum, dp);
#         }
#     };
#     
#     class Solution {
#       public:
#           // Function to find number of ways to assign + or - to reach the target
#           int findTargetSumWays(vector<int>& nums, int target) {
#               int n = nums.size();
#       
#               // First calculate the total sum of all numbers
#               int totalSum = accumulate(nums.begin(), nums.end(), 0);
#       
#               // If (target + totalSum) is odd or target > totalSum, no valid partition exists
#               if ((totalSum + target) % 2 != 0 || abs(target) > totalSum) return 0;
#       
#               // We now need to count subsets with sum = (target + totalSum) / 2
#               int newTarget = (totalSum + target) / 2;
#       
#               // Create DP table: dp[i][j] = number of ways to make sum j using first i numbers
#               vector<vector<int>> dp(n + 1, vector<int>(newTarget + 1, 0));
#       
#               // Base case: One way to form sum 0 (by taking no elements)
#               for (int i = 0; i <= n; i++) dp[i][0] = 1;
#       
#               // Fill DP table iteratively
#               for (int i = 1; i <= n; i++) {
#                   for (int j = 0; j <= newTarget; j++) {
#                       // Exclude current element
#                       dp[i][j] = dp[i - 1][j];
#       
#                       // Include current element if it does not exceed current target j
#                       if (nums[i - 1] <= j) {
#                           dp[i][j] += dp[i - 1][j - nums[i - 1]];
#                       }
#                   }
#               }
#       
#               return dp[n][newTarget];
#           }
#       };
# 
# // Example usage
# int main() {
#     Solution sol;
#     vector<int> nums = {1, 1, 1, 1, 1};
#     int target = 3;
#     cout << sol.findTargetSumWays(nums, target) << endl; // Output: 5
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
