// Given two strings s1 and s2. The task is to remove or insert the minimum 
//number of characters from/in s1 to transform it into s2. It could be 
//possible that the same character needs to be removed from one point of
// s1 and inserted into another point.


// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.

 

// Example 1:

// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

// Example 2:

// Input: word1 = "leetcode", word2 = "etco"
// Output: 4

 

// Constraints:

//     1 <= word1.length, word2.length <= 500
//     word1 and word2 consist of only lowercase English letters.

#include <iostream>
#include<vector>
using namespace std;
class Solution {
  public:
      int solve(string &w1, string &w2, int i, int j) {
          // Base cases
          if(i < 0) return j + 1;
          if(j < 0) return i + 1;
  
          // If characters match
          if(w1[i] == w2[j]) {
              return solve(w1, w2, i - 1, j - 1);
          }
  
          // If not match → delete from either string
          int deleteFromW1 = solve(w1, w2, i - 1, j);
          int deleteFromW2 = solve(w1, w2, i, j - 1);
  
          return 1 + min(deleteFromW1, deleteFromW2);
      }
  
      int minDistance(string word1, string word2) {
          return solve(word1, word2, word1.size() - 1, word2.size() - 1);
      }
  };

  class Solution {
    public:
        int solve(string& w1, string& w2, int i, int j, vector<vector<int>>& dp) {
            // Base cases
            if (i < 0)
                return j + 1;
            if (j < 0)
                return i + 1;
    
            // Check memo
            if (dp[i][j] != -1)
                return dp[i][j];
    
            if (w1[i] == w2[j]) {
                return dp[i][j] = solve(w1, w2, i - 1, j - 1, dp);
            } else {
                int deleteFromW1 = solve(w1, w2, i - 1, j, dp);
                int deleteFromW2 = solve(w1, w2, i, j - 1, dp);
                return dp[i][j] = 1 + min(deleteFromW1, deleteFromW2);
            }
        }
    
        int minDistance(string word1, string word2) {
            int n = word1.size();
            int m = word2.size();
            vector<vector<int>> dp(n, vector<int>(m, -1));
            return solve(word1, word2, n - 1, m - 1, dp);
        }
    };
  class Solution {
    public:
        // Function to find minimum insertions/deletions
        int minOperations(string s1, string s2) {
            // Get lengths of both strings
            int n = s1.length();
            int m = s2.length();
    
            // Create DP table of size (n+1) x (m+1)
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
            // Fill the table using bottom-up approach
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    // If characters match, extend LCS
                    if (s1[i - 1] == s2[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
    
            // Get LCS length
            int lcs = dp[n][m];
    
            // Return total operations = deletions + insertions
            return (n - lcs) + (m - lcs);
        }
    };

    // Class containing the solution
class Solution {
  public:
      // Function to calculate minimum operations
      int minOperations(string s1, string s2) {
          // Get the lengths of both strings
          int n = s1.size(), m = s2.size();
  
          // Create two 1D DP arrays
          vector<int> prev(m + 1, 0), cur(m + 1, 0);
  
          // Iterate through each character of s1
          for (int i = 1; i <= n; i++) {
  
              // Iterate through each character of s2
              for (int j = 1; j <= m; j++) {
  
                  // If characters match, increment LCS length
                  if (s1[i - 1] == s2[j - 1])
                      cur[j] = 1 + prev[j - 1];
  
                  // Else, take max from left or top
                  else
                      cur[j] = max(prev[j], cur[j - 1]);
              }
  
              // Update prev row to current
              prev = cur;
          }
  
          // Calculate total operations
          int lcs = prev[m];
          return (n - lcs) + (m - lcs);
      }
  };