// You are given a matrix mat[][] of size n x m where each element is a positive integer. Starting from any cell in the first row, you are allowed to move to the next row, but with specific movement constraints. From any cell (r, c) in the current row, you can move to any of the three possible positions :

//     (r+1, c-1) — move diagonally to the left.
//     (r+1, c) — move directly down.
//     (r+1, c+1) — move diagonally to the right.

// Find the maximum sum of any path starting from any column in the first row and ending at any column in the last row, following the above movement constraints.

// Examples :

// Input: mat[][] = [[3, 6, 1], [2, 3, 4], [5, 5, 1]]
// Output: 15
// Explaination: The best path is (0, 1) -> (1, 2) -> (2, 1). It gives the maximum sum as 15.

// Input: mat[][] = [[2, 1, 1], [1, 2, 2]]
// Output: 4
// Explaination: The best path is (0, 0) -> (1, 1). It gives the maximum sum as 4.

// Input: mat[][] = [[25]]
// Output: 25
// Explaination: (0, 0) is the only cell in mat[][], so maximum path sum will be 25.

// Constraints:
// 1 ≤ mat.size() ≤ 500
// 1 ≤ mat[i].size() ≤ 500
// 1 ≤ mat[i][j] ≤ 1000
#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      int helper(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
          int n = mat.size();
          int m = mat[0].size();
  
          // Out of bounds
          if (j < 0 || j >= m) return -1e9;
  
          // Last row
          if (i == n - 1) return mat[i][j];
  
          // Already computed
          if (dp[i][j] != -1) return dp[i][j];
  
          int down = helper(i + 1, j, mat, dp);
          int leftDiag = helper(i + 1, j - 1, mat, dp);
          int rightDiag = helper(i + 1, j + 1, mat, dp);
  
          return dp[i][j] = mat[i][j] + max({down, leftDiag, rightDiag});
      }
  
      int maximumPath(vector<vector<int>>& mat) {
          int n = mat.size();
          int m = mat[0].size();
  
          vector<vector<int>> dp(n, vector<int>(m, -1));
  
          int maxi = 0;
  
          // Start from any column in first row
          for (int j = 0; j < m; j++) {
              maxi = max(maxi, helper(0, j, mat, dp));
          }
  
          return maxi;
      }
  };