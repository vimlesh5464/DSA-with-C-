# Frog Jump.py - Python skeleton converted from C++

# Original C++ code:
# // Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the last stair.
# 
# // Example:
# 
# // Input: heights[] = [20, 30, 40, 20]
# // Output: 20
# // Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
# // jump from stair 0 to 1: cost = |30 - 20| = 10
# // jump from stair 1 to 3: cost = |20 - 30| = 10
# // Total Cost = 10 + 10 = 20
# 
# // Input: heights[] = [30, 20, 50, 10, 40]
# // Output: 30
# // Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
# // jump from stair 0 to 2: cost = |50 - 30| = 20
# // jump from stair 2 to 4: cost = |40 - 50| = 10
# // Total Cost = 20 + 10 = 30
# 
# // Constraints:
# // 1 ≤ height.size() ≤ 105
# // 0 ≤ height[i] ≤ 104
# 
# #include <vector>
# #include <iostream>
# using namespace std;
# 
# class Solution {
#   public:
#       // Solve function using recursion with memoization
#       // ind -> current index the frog needs to reach
#       // height -> vector of heights
#       // dp -> memo table where dp[i] stores min cost to reach i
#       int solve(int ind, const vector<int>& height, vector<int>& dp) {
#           // If at the first stone, cost is 0
#           if (ind == 0) return 0;
#   
#           // Return memoized result if already computed
#           if (dp[ind] != -1) return dp[ind];
#   
#           // Initialize jumpTwo with a large value
#           int jumpTwo = INT_MAX;
#   
#           // Compute cost when jumping from previous stone (ind - 1)
#           int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
#   
#           // Compute cost when jumping from two stones back (ind - 2) if possible
#           if (ind > 1) {
#               jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
#           }
#   
#           // Memoize and return the minimum of the two choices
#           return dp[ind] = min(jumpOne, jumpTwo);
#       }
#   
#       // Helper to handle edge cases and start recursion
#       int frogJump(const vector<int>& height) {
#           // Handle empty input
#           if (height.empty()) return 0;
#   
#           // Prepare dp with -1 indicating uncomputed states
#           int n = (int)height.size();
#           vector<int> dp(n, -1);
#   
#           // Start from the last index
#           return solve(n - 1, height, dp);
#       }
#   };
#   
# class Solution {
# public:
#     // Computes minimum energy to reach last index using bottom-up DP
#     int frogJump(const vector<int>& height) {
#         // Handle empty input
#         if (height.empty()) return 0;
# 
#         // Fetch size of the input
#         int n = (int)height.size();
# 
#         // Create dp array where dp[i] = min energy to reach i
#         vector<int> dp(n, INT_MAX);
# 
#         // Base case: cost to stand on first stone is zero
#         dp[0] = 0;
# 
#         // Iterate over stones from index 1 to n-1
#         for (int ind = 1; ind < n; ind++) {
#             // Compute cost for a jump from ind-1
#             int jumpOne = dp[ind - 1] + abs(height[ind] - height[ind - 1]);
# 
#             // Initialize jumpTwo with large value
#             int jumpTwo = INT_MAX;
# 
#             // If possible, compute cost for a jump from ind-2
#             if (ind > 1) {
#                 jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);
#             }
# 
#             // Take the minimum of the two options
#             dp[ind] = min(jumpOne, jumpTwo);
#         }
# 
#         // Return min energy to reach last stone
#         return dp[n - 1];
#     }
# };
# 
# int main() {
#     // Define the heights array
#     vector<int> height{30, 10, 60, 10, 60, 50};
# 
#     // Create Solution instance
#     Solution sol;
# 
#     // Compute and print the minimum energy
#     cout << sol.frogJump(height) << endl; // Expected: 40
#     return 0;
# }

def main():
    pass  # TODO: Convert C++ code to Python here

if __name__ == '__main__':
    main()
