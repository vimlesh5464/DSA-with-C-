// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

// Example 2:

// Input: triangle = [[-10]]
// Output: -10

 

// Constraints:

//     1 <= triangle.length <= 200
//     triangle[0].length == 1
//     triangle[i].length == triangle[i - 1].length + 1
//     -104 <= triangle[i][j] <= 104
#include <vector>
#include <iostream>
using namespace std;

// Class to solve the problem
class Solution {
  public:
      // Recursive function with memoization
      int solve(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp) {
          // If value already computed
          if (dp[i][j] != -1)
              return dp[i][j];
  
          // If at bottom row
          if (i == n - 1)
              return triangle[i][j];
  
          // Compute both downward and diagonal moves
          int down = triangle[i][j] + solve(i + 1, j, triangle, n, dp);
          int diag = triangle[i][j] + solve(i + 1, j + 1, triangle, n, dp);
  
          // Store and return min path sum
          return dp[i][j] = min(down, diag);
      }
  
      // Function to start the process
      int minimumPathSum(vector<vector<int>> &triangle) {
          int n = triangle.size();
          vector<vector<int>> dp(n, vector<int>(n, -1));
          return solve(0, 0, triangle, n, dp);
      }
  };
  
 
class Solution {
  public:
      int minimumTotal(vector<vector<int>>& triangle) {
          int n = triangle.size();
          
          // Start from second last row and move upwards
          for (int i = n - 2; i >= 0; i--) {
              for (int j = 0; j < triangle[i].size(); j++) {
                  triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
              }
          }
          
          return triangle[0][0];
      }
  };
  