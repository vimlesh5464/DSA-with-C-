// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.

 

// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we do not need any insertions.

// Example 2:

// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".

// Example 3:

// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".

 

// Constraints:

//     1 <= s.length <= 500
//     s consists of lowercase English letters.
#include <iostream>
#include<vector>
using namespace std;

class Solution {
  public:
      int solve(string &s, int i, int j, vector<vector<int>> &dp) {
          // Base case
          if (i >= j) return 0;
  
          // Already computed
          if (dp[i][j] != -1) return dp[i][j];
  
          // If characters match
          if (s[i] == s[j]) {
              return dp[i][j] = solve(s, i + 1, j - 1, dp);
          }
  
          // If not match → insert
          return dp[i][j] = 1 + min(
              solve(s, i + 1, j, dp),
              solve(s, i, j - 1, dp)
          );
      }
  
      int minInsertions(string s) {
          int n = s.length();
          
          // DP table
          vector<vector<int>> dp(n, vector<int>(n, -1));
          
          return solve(s, 0, n - 1, dp);
      }
  };
class Solution {
  public:
    // Function to calculate Longest Common Subsequence
      int lcs(string s1, string s2) {
          
          // Get sizes of both strings
          int n = s1.size();
          int m = s2.size();
  
          // Create a dp table of size (n+1) x (m+1)
          vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  
          // Initialize first row as 0
          for (int i = 0; i <= n; i++) {
              dp[i][0] = 0;
          }
  
          // Initialize first column as 0
          for (int i = 0; i <= m; i++) {
              dp[0][i] = 0;
          }
  
          // Fill dp table using bottom-up approach
          for (int ind1 = 1; ind1 <= n; ind1++) {
              for (int ind2 = 1; ind2 <= m; ind2++) {
  
                  // If characters match, add 1 to previous diagonal
                  if (s1[ind1 - 1] == s2[ind2 - 1])
                      dp[ind1][ind2] = 
                          1 + dp[ind1 - 1][ind2 - 1];
  
                  // Else take max from top or left
                  else
                      dp[ind1][ind2] = 
                          max(dp[ind1 - 1][ind2], 
                              dp[ind1][ind2 - 1]);
              }
          }
  
          // Return bottom-right value
          return dp[n][m];
      }
  
      // Function to find length of Longest Palindromic Subsequence
      int longestPalindromeSubsequence(string s) {
          
          // Reverse the string
          string t = s;
          reverse(s.begin(), s.end());
  
          // LCS of s and its reverse is the LPS
          return lcs(s, t);
      }
      int minInsertions(string s) {
          // Get length of input string
          int n = s.size();
  
          // Get length of longest palindromic subsequence
          int k = longestPalindromeSubsequence(s);
  
          // Return total - palindromic length
          return n - k;
      }
  };