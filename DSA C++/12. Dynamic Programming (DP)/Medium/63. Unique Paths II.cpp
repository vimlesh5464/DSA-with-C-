//used leetcode 
// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

// Example 1:

// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// Example 2:

// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1

 

// Constraints:

//     m == obstacleGrid.length
//     n == obstacleGrid[i].length
//     1 <= m, n <= 100
//     obstacleGrid[i][j] is 0 or 1.

#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
  int gridWays(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>>& vis) {
    // Out of bounds or blocked cell
    if(i >= n || j >= m || grid[i][j] == 1) return 0;
  
    // Reached bottom-right cell
    if(i == n - 1 && j == m - 1) return 1;
   // Memoization check
            if(vis[i][j] != -1) {
                return vis[i][j];
            }
    // Move Down + Move Right
    return vis[i][j] =gridWays(i + 1, j, n, m, grid,vis) + gridWays(i, j + 1, n, m, grid,vis);
  }
      int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
          int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, -1));
    return gridWays(0, 0, n, m,obstacleGrid,vis);
      }
  };

  class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
    
            vector<vector<long long>> dp(n, vector<long long>(m, 0));
    
            // Starting cell
            if(grid[0][0] == 1) return 0;
            dp[0][0] = 1;
    
            // First column
            for(int i = 1; i < n; i++) {
                if(grid[i][0] == 0)
                    dp[i][0] = dp[i-1][0];
                else
                    dp[i][0] = 0;
            }
    
            // First row
            for(int j = 1; j < m; j++) {
                if(grid[0][j] == 0)
                    dp[0][j] = dp[0][j-1];
                else
                    dp[0][j] = 0;
            }
    
            // Fill rest of grid
            for(int i = 1; i < n; i++) {
                for(int j = 1; j < m; j++) {
                    if(grid[i][j] == 0) {
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    } else {
                        dp[i][j] = 0;
                    }
                }
            }
    
            return dp[n-1][m-1];
        }
    };