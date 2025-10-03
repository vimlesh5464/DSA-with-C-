#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      int helper(vector<int> &arr, int i, int j, vector<vector<int>>& dp) {
          if (i == j) return 0;
  
          if (dp[i][j] != -1) return dp[i][j];
  
          int ans = INT_MAX;
          for (int k = i; k < j; k++) {
              int cost1 = helper(arr, i, k, dp);
              int cost2 = helper(arr, k + 1, j, dp);
              int curr = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
              ans = min(ans, curr);
          }
  
          return dp[i][j] = ans;
      }
  
      int matrixMultiplication(vector<int> &arr) {
          int n = arr.size();
          vector<vector<int>> dp(n, vector<int>(n, -1));
          return helper(arr, 1, n - 1, dp);
      }
  };


class Solution {
  public:
      int matrixMultiplication(vector<int> &arr) {
          int n = arr.size();
          vector<vector<int>> dp(n, vector<int>(n, 0));
  
          // dp[i][j] stores minimum cost to multiply matrices i..j
          for (int len = 2; len < n; len++) { // length of chain
              for (int i = 1; i <= n-len; i++) {
                  int j = i + len - 1;
                  dp[i][j] = INT_MAX;
                  for (int k = i; k < j; k++) {
                      int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                      dp[i][j] = min(dp[i][j], cost);
                  }
              }
          }
  
          return dp[1][n-1]; // result for matrices 1..n-1
      }
  };

  int main() {
    Solution sol;
    vector<int> arr = {40, 20, 30, 10, 30};
    cout << sol.matrixMultiplication(arr) << endl; // Output: 26000
    return 0;
}
  