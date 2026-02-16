#include<iostream>
#include<vector>
#include<string>
using namespace std;

// | Approach        | Time         | Space    |
// | --------------- | ------------ | -------- | 
// | Pure Recursion  | `O(2^(n+m))` | `O(n+m)` | 
// | Memoization     | `O(nm)`      | `O(nm)`  |
// | Tabulation      | `O(nm)`      | `O(nm)`  | 


class Solution {
  public:
      bool isMatch(string s, string p) {
          return match(s, p, 0, 0);
      }
  
      bool match(string &s, string &p, int i, int j) {
          // If pattern is finished
          if (j == p.length()) {
              return i == s.length();
          }
  
          // Check first character match
          bool firstMatch = (i < s.length() &&
                            (s[i] == p[j] || p[j] == '.'));
  
          // If next character is '*'
          if (j + 1 < p.length() && p[j + 1] == '*') {
              // 1) Skip x*
              // 2) Use x* if firstMatch
              return match(s, p, i, j + 2) ||
                     (firstMatch && match(s, p, i + 1, j));
          }
          else {
              // Normal match
              return firstMatch && match(s, p, i + 1, j + 1);
          }
      }
  };
  

  class Solution {
    public:
        bool isMatch(string s, string p) {
            vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
            return solve(s, p, 0, 0, dp);
        }
    
        bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
            // If already computed
            if (dp[i][j] != -1)
                return dp[i][j];
    
            // If pattern finished
            if (j == p.length())
                return dp[i][j] = (i == s.length());
    
            bool firstMatch = (i < s.length() &&
                              (s[i] == p[j] || p[j] == '.'));
    
            bool ans;
    
            // If next character is '*'
            if (j + 1 < p.length() && p[j + 1] == '*') {
                ans = solve(s, p, i, j + 2, dp) ||
                      (firstMatch && solve(s, p, i + 1, j, dp));
            } else {
                ans = firstMatch && solve(s, p, i + 1, j + 1, dp);
            }
    
            return dp[i][j] = ans;
        }
    };

    class Solution {
      public:
          bool isMatch(string s, string p) {
              int n = s.size();
              int m = p.size();
      
              vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
      
              // Empty string & empty pattern
              dp[0][0] = true;
      
              // Handle patterns like a*, a*b*, a*b*c*
              for (int j = 2; j <= m; j++) {
                  if (p[j - 1] == '*') {
                      dp[0][j] = dp[0][j - 2];
                  }
              }
      
              // Fill DP table
              for (int i = 1; i <= n; i++) {
                  for (int j = 1; j <= m; j++) {
      
                      // Normal char or '.'
                      if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                          dp[i][j] = dp[i - 1][j - 1];
                      }
      
                      // '*'
                      else if (p[j - 1] == '*') {
                          // zero occurrence
                          dp[i][j] = dp[i][j - 2];
      
                          // one or more occurrence
                          if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                              dp[i][j] = dp[i][j] || dp[i - 1][j];
                          }
                      }
                  }
              }
      
              return dp[n][m];
          }
      };
      