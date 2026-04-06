# 746. Min Cost Climbing Stairs.py - Python skeleton converted from C++

# Original C++ code:
# // You are given an integer array cost where cost[i] is the cost of ith step on a 
# //staircase. Once you pay the cost, you can either climb one or two steps.
# 
# // You can either start from the step with index 0, or the step with index 1.
# 
# // Return the minimum cost to reach the top of the floor.
# 
#  
# 
# // Example 1:
# 
# // Input: cost = [10,15,20]
# // Output: 15
# // Explanation: You will start at index 1.
# // - Pay 15 and climb two steps to reach the top.
# // The total cost is 15.
# 
# // Example 2:
# 
# // Input: cost = [1,100,1,1,1,100,1,1,100,1]
# // Output: 6
# // Explanation: You will start at index 0.
# // - Pay 1 and climb two steps to reach index 2.
# // - Pay 1 and climb two steps to reach index 4.
# // - Pay 1 and climb two steps to reach index 6.
# // - Pay 1 and climb one step to reach index 7.
# // - Pay 1 and climb two steps to reach index 9.
# // - Pay 1 and climb one step to reach the top.
# // The total cost is 6.
# 
#  
# 
# // Constraints:
# 
# //     2 <= cost.length <= 1000
# //     0 <= cost[i] <= 999
# 
#  
# 
# #include <iostream>
# #include <vector>
# using namespace std;
# 
# class Solution {
# public:
#     // pure recursion function
#     int solve(int i, vector<int>& cost) {
#         int n = cost.size();
# 
#         // If beyond last step -> no extra cost
#         if (i >= n) return 0;
# 
#         // Option 1: take single step
#         int one = cost[i] + solve(i + 1, cost);
# 
#         // Option 2: take double step
#         int two = cost[i] + solve(i + 2, cost);
# 
#         return min(one, two);
#     }
# 
#     int minCostClimbingStairs(vector<int>& cost) {
#         // Can start from step 0 OR step 1
#         return min(solve(0, cost), solve(1, cost));
#     }
# };
# 
# class Solution {
#   public:
#       int solve(int i, vector<int>& cost, vector<int>& dp) {
#           int n = cost.size();
#   
#           if (i >= n) return 0;
#           if (dp[i] != -1) return dp[i];
#   
#           int one = cost[i] + solve(i + 1, cost, dp);
#           int two = cost[i] + solve(i + 2, cost, dp);
#   
#           return dp[i] = min(one, two);
#       }
#   
#       int minCostClimbingStairs(vector<int>& cost) {
#           int n = cost.size();
#           vector<int> dp(n, -1);
#   
#           return min(solve(0, cost, dp), solve(1, cost, dp));
#       }
#   };
#   
#   class Solution {
#     public:
#         int minCostClimbingStairs(vector<int>& cost) {
#             int n = cost.size();
#             vector<int> dp(n + 1, 0);
#     
#             for (int i = 2; i <= n; i++) {
#                 int one = dp[i - 1] + cost[i - 1];
#                 int two = dp[i - 2] + cost[i - 2];
#                 dp[i] = min(one, two);
#             }
#     
#             return dp[n];
#         }
#     };
# int main() {
#     int n;
#     cout << "Enter number of steps: ";
#     cin >> n;
# 
#     vector<int> cost(n);
#     cout << "Enter cost array: ";
#     for(int i = 0; i < n; i++) {
#         cin >> cost[i];
#     }
# 
#     Solution obj;
#     cout << "Minimum cost to reach top = " 
#          << obj.minCostClimbingStairs(cost) << endl;
# 
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
