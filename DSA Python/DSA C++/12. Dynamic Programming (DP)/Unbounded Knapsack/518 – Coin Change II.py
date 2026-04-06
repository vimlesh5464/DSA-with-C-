# 518 – Coin Change II.py - Python skeleton converted from C++

# Original C++ code:
# // You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
# 
# // Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
# 
# // You may assume that you have an infinite number of each kind of coin.
# 
# // The answer is guaranteed to fit into a signed 32-bit integer.
# 
#  
# 
# // Example 1:
# 
# // Input: amount = 5, coins = [1,2,5]
# // Output: 4
# // Explanation: there are four ways to make up the amount:
# // 5=5
# // 5=2+2+1
# // 5=2+1+1+1
# // 5=1+1+1+1+1
# 
# // Example 2:
# 
# // Input: amount = 3, coins = [2]
# // Output: 0
# // Explanation: the amount of 3 cannot be made up just with coins of 2.
# 
# // Example 3:
# 
# // Input: amount = 10, coins = [10]
# // Output: 1
# 
#  
# 
# // Constraints:
# 
# //     1 <= coins.length <= 300
# //     1 <= coins[i] <= 5000
# //     All the values of coins are unique.
# //     0 <= amount <= 5000
# 
#  
# 
# #include <iostream>
# #include<vector>
# using namespace std;
# 
# class Solution {
#   public:
#       int change(int amount, vector<int>& coins) {
#           int n = coins.size();
#           vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
#   
#           // Base case: 0 amount → 1 way
#           for(int i = 0; i <= n; i++)
#               dp[i][0] = 1;
#   
#           for(int i = 1; i <= n; i++) {
#               for(int j = 1; j <= amount; j++) {
#                   if(coins[i-1] <= j)
#                       dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
#                   else
#                       dp[i][j] = dp[i-1][j];
#               }
#           }
#   
#           return dp[n][amount];
#       }
#   };
#   
# 
# class Solution {
# public:
#     int helper(vector<int>& coins, int W, int n, vector<vector<int>>& dp) {
#         if(W == 0) return 1;   // Found a valid combination
#         if(n == 0) return 0;   // No coins left
# 
#         if(dp[n][W] != -1) return dp[n][W];
# 
#         if(coins[n-1] <= W) {
#             // Include current coin + Exclude current coin
#             int include = helper(coins, W - coins[n-1], n, dp);
#             int exclude = helper(coins, W, n-1, dp);
#             dp[n][W] = include + exclude;
#         } else {
#             // Cannot include current coin, only exclude
#             dp[n][W] = helper(coins, W, n-1, dp);
#         }
# 
#         return dp[n][W];
#     }
# 
#     int change(int amount, vector<int>& coins) {
#         int n = coins.size();
#         vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
#         return helper(coins, amount, n, dp);
#     }
# };
# 
# int main() {
#     Solution sol;
#     vector<int> coins = {1, 2, 5};
#     int amount = 5;
#     cout << "Number of ways: " << sol.change(amount, coins) << endl; // Output: 4
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
