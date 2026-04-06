# 70. Climbing Stairs.py - Python skeleton converted from C++

# Original C++ code:
# // You are climbing a staircase. It takes n steps to reach the top.
# 
# // Each time you can either climb 1 or 2 steps. In how many distinct ways can you 
# //climb to the top?
# 
#  
# 
# // Example 1:
# 
# // Input: n = 2
# // Output: 2
# // Explanation: There are two ways to climb to the top.
# // 1. 1 step + 1 step
# // 2. 2 steps
# 
# // Example 2:
# 
# // Input: n = 3
# // Output: 3
# // Explanation: There are three ways to climb to the top.
# // 1. 1 step + 1 step + 1 step
# // 2. 1 step + 2 steps
# // 3. 2 steps + 1 step
# 
#  
# 
# // Constraints:
# 
# //     1 <= n <= 45
# 
#  
# #include<iostream>
# #include<vector>
# using namespace std;
# 
# 
# class Solution {
# public:
#     int climbStairs(int n) {
#         // Base cases
#         if (n == 0) return 1; // 1 way to stay at step 0
#         if (n == 1) return 1; // 1 way to reach step 1
# 
#         // Recursive relation:
#         // Ways = ways(n-1) + ways(n-2)
#         return climbStairs(n - 1) + climbStairs(n - 2);
#     }
# };
# //Recursion + Memoization (Fast)
# class Solution {
#   public:
#       int solve(int n, vector<int>& dp) {
#           if (n == 0) return 1;
#           if (n == 1) return 1;
#   
#           if (dp[n] != -1) return dp[n];  // Return already computed value
#   
#           // Memoized recurrence
#           return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
#       }
#   
#       int climbStairs(int n) {
#           vector<int> dp(n + 1, -1);
#           return solve(n, dp);
#       }
#   };
#   //Tabulation (Bottom-Up DP)
# class Solution {
#   public:
#       int climbStairs(int n) {
#           if (n == 0 || n == 1) return 1;
#           vector<int> dp(n + 1);
#           dp[0] = dp[1] = 1;
#           for (int i = 2; i <= n; i++) {
#               dp[i] = dp[i - 1] + dp[i - 2];
#           }
#           return dp[n];
#       }
#   };
#  
# int main() {
#     int n;
#     cout << "Enter number of stairs: ";
#     cin >> n;
# 
#     Solution obj;
#     cout << "Number of ways = " << obj.climbStairs(n) << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
