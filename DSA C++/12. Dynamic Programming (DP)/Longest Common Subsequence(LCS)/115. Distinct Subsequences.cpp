// Given two strings s and t, return the number of distinct subsequences of s 
//which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed integer.

 

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from s.
// rabbbit
// rabbbit
// rabbbit

// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from s.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag

 

// Constraints:

//     1 <= s.length, t.length <= 1000
//     s and t consist of English letters.

 
#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      // Recursive helper function with memoization
      // i -> current index in s
      // j -> current index in t
      // dp -> memoization table
      int helper(int i, int j, string &s, string &t,
                 vector<vector<int>> &dp) {
          // If we have matched all characters of t
          // then we found one valid subsequence
          if (j == t.size()) return 1;
  
          // If we have exhausted s but not t
          // then no valid subsequence can be formed
          if (i == s.size()) return 0;
  
          // If this state has been already computed
          if (dp[i][j] != -1) return dp[i][j];
  
          // If current characters of s and t match
          if (s[i] == t[j]) {
              // Option 1: take this character and move both indices
              int take = helper(i + 1, j + 1, s, t, dp);
  
              // Option 2: skip this character of s and move only in s
              int notTake = helper(i + 1, j, s, t, dp);
  
              // Store result in dp table
              return dp[i][j] = take + notTake;
          } else {
              // If characters do not match, we can only skip s[i]
              return dp[i][j] = helper(i + 1, j, s, t, dp);
          }
      }
      int numDistinct(string s, string t) {
          // Initialize dp table with -1 (uncomputed states)
          vector<vector<int>> dp(s.size(),
                                 vector<int>(t.size(), -1));
  
          // Start recursion from index 0 of s and t
          return helper(0, 0, s, t, dp); 
      }
  };

  class Solution {
    public:
        // Function to count distinct subsequences
        int numDistinct(string s, string t) {
            // Get lengths of both strings
            int n = s.size();
            int m = t.size();
    
            // Create dp table of size (n+1) x (m+1)
            vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    
            // Base case: empty t can be formed from any suffix of s
            for (int i = 0; i <= n; i++) {
                dp[i][m] = 1;
            }
    
            // Fill dp table from bottom to top
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    // If characters match, we have two options:
                    // 1. Take this character -> dp[i+1][j+1]
                    // 2. Skip this character -> dp[i+1][j]
                    if (s[i] == t[j]) {
                        dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                    } else {
                        // If characters don't match, we can only skip
                        dp[i][j] = dp[i + 1][j];
                    }
                }
            }
    
            // Final answer is stored at dp[0][0]
            return dp[0][0];
        }
    };
    