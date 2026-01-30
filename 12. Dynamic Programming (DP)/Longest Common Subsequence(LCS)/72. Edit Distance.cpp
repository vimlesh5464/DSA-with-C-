
#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int solve(int i, int j, string &w1, string &w2, vector<vector<int>>& dp) {
          if (i < 0) return j + 1;
          if (j < 0) return i + 1;
  
          if (dp[i][j] != -1) return dp[i][j];
  
          if (w1[i] == w2[j])
              return dp[i][j] = solve(i - 1, j - 1, w1, w2, dp);
  
          int insertOp = 1 + solve(i, j - 1, w1, w2, dp);
          int deleteOp = 1 + solve(i - 1, j, w1, w2, dp);
          int replaceOp = 1 + solve(i - 1, j - 1, w1, w2, dp);
  
          return dp[i][j] = min({insertOp, deleteOp, replaceOp});
      }
  
      int minDistance(string word1, string word2) {
          int m = word1.size(), n = word2.size();
          vector<vector<int>> dp(m, vector<int>(n, -1));
          return solve(m - 1, n - 1, word1, word2, dp);
      }
  };
  
class Solution {
  public:
      int minDistance(string word1, string word2) {
          int n = word1.size();
      int m = word2.size();
  
      vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  
      // Initialize base cases
      for (int i = 0; i <= n; i++)
          dp[i][0] = i;   // delete all
      for (int j = 0; j <= m; j++)
          dp[0][j] = j;   // insert all
  
      // DP fill
      for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
  
              if (word1[i - 1] == word2[j - 1]) {
                  dp[i][j] = dp[i - 1][j - 1]; // no operation
              }
  
              else {
                  dp[i][j] = 1 + min({
                      dp[i - 1][j],     // delete
                      dp[i][j - 1],     // insert
                      dp[i - 1][j - 1]  // replace
                  });
              }
          }
      }
  
      return dp[n][m];
      }
  };