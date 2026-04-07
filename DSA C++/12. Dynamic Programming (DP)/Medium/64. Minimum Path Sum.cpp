// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

 

// Example 1:

// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12

 

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 200
//     0 <= grid[i][j] <= 200

#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
          int n = grid.size();
          int m = grid[0].size();
  
          if (i >= n || j >= m) return INT_MAX;
  
          if (i == n - 1 && j == m - 1)
              return grid[i][j];
  
          if (dp[i][j] != -1) return dp[i][j];
  
          return dp[i][j] = grid[i][j] + min(
              helper(grid, i + 1, j, dp),
              helper(grid, i, j + 1, dp)
          );
      }
  
      int minPathSum(vector<vector<int>>& grid) {
          int n = grid.size();
          int m = grid[0].size();
  
          vector<vector<int>> dp(n, vector<int>(m, -1));
          return helper(grid, 0, 0, dp);
      }
  };